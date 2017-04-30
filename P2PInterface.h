/*                                          */
/*       File: P2PInterface.h               */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the drawing  */
/*         the interface of the application */
/*                                          */

#ifndef P2PInterface
#define P2PInterface

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

char * getInput();
void drawMainScreen();
void drawBox(int width, int height, int startX, int startY);
void printServerMessages(char * message);
void printUserData(char * ipString);

#endif