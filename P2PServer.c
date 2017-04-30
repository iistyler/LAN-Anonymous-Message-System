/*                                          */
/*       File: P2PServer.c                  */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the getting  */
/*         messages from the network        */
/*                                          */

#include "P2PServer.h"

int createServer(int verbose) {

    /* Server Info */
    int socket_desc, client_sock, c, read_size;

    // Server and client
    struct sockaddr_in server;

    // Message
    char message_size[60];
    char client_message[60];

    int sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Server Settings
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons( 8820 );

    unsigned sinlen = sizeof(struct sockaddr_in);

    //Make sure server will take in broadcast messages & allow port to be listened on multiple times
    int tempVal = 1;
    if (setsockopt (sock, SOL_SOCKET, SO_REUSEPORT, (const char*)&tempVal, sizeof (tempVal)) < 0)
      printf ("Application must be run with sudo\n");


    // Open socket
    bind(sock, (struct sockaddr *)&server, sinlen);
    getsockname(sock, (struct sockaddr *)&server, &sinlen);

    // Recieve message size
    while ( recvfrom(sock, client_message, 60, 0, (struct sockaddr *)&server, &sinlen) ) {

    	char* ipString = inet_ntoa(server.sin_addr);
        
        printServerMessages(client_message);

        if (verbose)
        	printUserData(ipString);

    }

    return 0;
}