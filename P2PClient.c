/*                                          */
/*       File: P2PClient.c                  */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the sending  */
/*         messages to the network          */
/*                                          */

#include "P2PClient.h"

void createClient(int unhidden) {
	int port = 8810;

	// Upen the socket for a raw UDP packet
	int socketInfo = socket (PF_INET, SOCK_RAW, IPPROTO_UDP);

	// Max packet size (Assuming each message can only contain 1K characters)
	int maxMessageSize = (sizeof(struct ip) + sizeof(struct udphdr) + (sizeof(char) * 1000) );

	// Create some space for the packet
	void * packet = malloc(maxMessageSize);

	// Create the headers
	struct ip *iph = (struct ip *) packet; // Set this header to the beginning of the packet

	struct udphdr *udph = packet + sizeof (struct ip); // Set this header to right after the IP header

	char * packetData = packet + sizeof (struct ip) + sizeof (struct udphdr);

	// Destination Info
	struct sockaddr_in sin;
	sin.sin_port = htons (8820);
	sin.sin_addr.s_addr = htonl(-1); // -1 Will broadcast the message to the network

	// Fill the IP Header struct (which will go directly into the packet)
	iph->ip_hl = 5;
	iph->ip_v = 4;
 	iph->ip_tos = 0;
 	iph->ip_len = sizeof (struct ip) + sizeof(struct udphdr); // Packet size
 	iph->ip_id = htonl (0);	// Let the IP layer deal with this
	iph->ip_off = 0;
 	iph->ip_ttl = 255;
 	iph->ip_p = IPPROTO_UDP;
 	iph->ip_sum = 0;

 	if (!unhidden)
 		iph->ip_src.s_addr = inet_addr ("1.0.0.0"); // Spoofed real IP with 1.0.0.0

 	iph->ip_dst.s_addr = sin.sin_addr.s_addr;

 	// Fill the UDP Header struct (Which will directly go into the packet)

 	udph->uh_sport = htons(1234); // Spoofed source port
 	udph->uh_dport = htons(8820); // Destination port
 	udph->uh_ulen = htons(8);

 	int tempVal = 1;
    if (setsockopt (socketInfo, IPPROTO_IP, IP_HDRINCL, &tempVal, sizeof (tempVal)) < 0)
      printf ("Application must be run with sudo\n");

 	while(1) {
 		// Get user message
 		char * buffer = NULL;

 		buffer = getInput();

 		int stringSize = sizeof(char) * (strlen(buffer) + 1);
 		strcpy(packetData, buffer);

 		iph->ip_len = sizeof (struct ip) + sizeof(struct udphdr) + stringSize; // Update packet size
 		udph->uh_ulen = htons(8 + stringSize);



	 	if (sendto (socketInfo, packet, iph->ip_len, 0, (struct sockaddr *) &sin, sizeof (sin)) < 0)		/* a normal send() */
			printf ("Failed to send\n");

		free(buffer);
	}

	free(packet);
}
