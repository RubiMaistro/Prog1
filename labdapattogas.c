#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main ( void ) 
{

	WINDOW *ablak;
	ablak = initscr ();

	int x = 0;
	int y = 0;

	int xone =0 , yone = 0;

	int xmax, ymax;
	
	for(;;)
	{
		getmaxyx ( ablak, ymax, xmax );
		
		mvprintw ( y, x, "O" );

		refresh();
		usleep (100);

		x = x + xone;
		y = y + yone;

		if ( x >= xmax-1 ) {
			xone *= -1;
		}
		if ( x <= 0 ) {
			xone *= -1;
		}
		if ( y >= yone-1) {
			yone *= -1;
		}
		if ( y >= ymax-1 ) {
			yone *= -1;
		}
	}

	return 0;
}
