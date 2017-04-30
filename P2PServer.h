/*                                          */
/*       File: P2PServer.h                  */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the getting  */
/*         messages from the network        */
/*                                          */

#include <stdio.h>
#include <string.h>       //strlen
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>    //inet_addr
#include <unistd.h>       //write

#ifndef P2PServer
#define P2PServer

#include "P2P.h"
#include "P2PInterface.h"

int createServer(int verbose);
void printServerMessages(char * message);

#endif