/*                                          */
/*       File: P2P.c                        */
/*       Author: Tyler Herbert              */
/*       Version: 1.0                       */
/*       Last Editted: February 1, 2016     */
/*                                          */
/*       File Section Description:          */
/*         This section is for the inital   */
/*         Application load and setup       */
/*                                          */

#include "P2P.h"


void endNcurses(int dummy) {
    endwin();
    exit(0);
}

int main(int argc , char *argv[]) {

    int verbose = 0;
    int unhidden = 0;

    // Setup  ncurses
    initscr();
    curs_set(0);
    signal(SIGINT, endNcurses);
    drawMainScreen();
    noecho();

    // Check if verbose/unhidden modes are on
    for (int i = 1; i <= argc; i++) {
    	if (strcmp(argv[i-1], "-v") == 0)
    		verbose = 1;

    	if (strcmp(argv[i-1], "-uh") == 0)
    		unhidden = 1;
    }

    pid_t child = fork();

    // Determine if client or server
    if (child == 0) {
        createServer(verbose);
    } else {
        createClient(unhidden);
    }

    endwin();

    return 0;
}