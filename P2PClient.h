/*                                          */
/*       File: P2PClient.h                  */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the sending  */
/*         messages to the network          */
/*                                          */

#define __USE_BSD
#include <netinet/in.h>
#define __FAVOR_BSD
#include <netinet/tcp.h>
#include <unistd.h>
#include <stdlib.h>
#include "P2PInterface.h"

#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stdio.h>
#include <string.h>       //strlen
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>    //inet_addr


#ifndef P2PCLient
#define P2PClient


void createClient(int unhidden);


#endif