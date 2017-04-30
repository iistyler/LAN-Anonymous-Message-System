/*                                          */
/*       File: P2PInterface.c               */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the drawing  */
/*         the interface of the application */
/*                                          */

#include "P2PInterface.h"
static int currentLen = 0;

void drawMainScreen() {
	// Draw echo area
	drawBox(70, 20, 4, 3);

	drawBox(70, 3, 4, 24);

	mvprintw(1, 27, "Anonymous Message Network");

	refresh();
}

void printServerMessages(char * message) {
	static char messageList[8][60] = { 0 };

	for (int i = 7; i >= 0; i--) {
		memset(messageList[i], '\0', 60);
		strcpy(messageList[i], messageList[i-1]);
	}

	memset(messageList[0], '\0', 60);
	strcpy(messageList[0], message);

	for (int i = 0; i < 8; i++) {

		// Clear old message
		for (int j = 0; j < 66; j++)
			mvaddch(20-(2*i), 8+j, ' ');

		// Print new message, if it exists
		if (strlen(messageList[i]) > 0) {
			mvprintw(20-(2*i), 8, "User: ");
			mvprintw(20-(2*i), 14, messageList[i]);
		}
	}

	mvaddch(25, 9+currentLen, ACS_CKBOARD);
	refresh();
}

void printUserData(char * ipString) {
	// Clear old message
	for (int j = 0; j < 66; j++)
		mvaddch(28, 4+j, ' ');

	mvprintw(28, 5, "Message recieved from:");
	mvprintw(28, 28, ipString);

	mvaddch(25, 9+currentLen, ACS_CKBOARD);
	refresh();
}

char * getInput() {
	char * buffer = malloc(0);
	char tempChar = 0;

	mvaddch(25, 9, ACS_CKBOARD);

	while(1) {
		tempChar = getch();

		// Dont send message if empty
		if (tempChar == '\n' && currentLen == 0)
			continue;

		// Send message
		if (tempChar == '\n')
			break;

		// Backspace
		if (tempChar == 127) {
			if (currentLen == 0)
				continue;

			// Blank out that info
			buffer[strlen(buffer)-1] = 0;
			mvaddch(25, 8+currentLen, ACS_CKBOARD);
			mvaddch(25, 9+currentLen, ' ');

			if (currentLen > 0)
				currentLen--;
			continue;
		}

		// Max message length is 60
		if (currentLen >= 59)
			continue;

		currentLen++;
		buffer = realloc(buffer, currentLen+1);
		buffer[currentLen-1] = tempChar;
		buffer[currentLen] = 0;

		mvaddch(25, 8+currentLen, tempChar);
		mvaddch(25, 9+currentLen, ACS_CKBOARD);

		refresh();
	}
	currentLen = 0;

	for (int i = 0; i < 61; i++)
		mvaddch(25, 8+i, ' ');

	return buffer;
}

void drawBox(int width, int height, int startX, int startY) {

	// Sides

	// Horizontal
	for (int i = 0; i < width; i++) {
		mvaddch(startY, startX+i, ACS_HLINE);
		mvaddch(startY+height, startX+i, ACS_HLINE);
	}
	
	// Vertical
	for (int i = 0; i < height; i++) {
		mvaddch(startY+i, startX, ACS_VLINE);
		mvaddch(startY+i, startX+width, ACS_VLINE);
	}

	// Corners
	mvaddch(startY, startX, ACS_ULCORNER);
	mvaddch(startY, startX+width, ACS_URCORNER);

	mvaddch(startY+height, startX, ACS_LLCORNER);
	mvaddch(startY+height, startX+width, ACS_LRCORNER);

}
