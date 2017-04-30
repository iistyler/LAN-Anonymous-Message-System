/*                                          */
/*       File: P2P.h                        */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the inital   */
/*         Application load and setup       */
/*                                          */

#include <stdio.h>
#include <string.h>       //strlen
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>    //inet_addr
#include <unistd.h>       //write

#ifndef P2PMain
#define P2PMain

#include "P2PServer.h"
#include "P2PClient.h"
#include "P2PInterface.h"

int createSocket(int * socket_desc);

#endif