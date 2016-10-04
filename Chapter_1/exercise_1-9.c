#include <stdio.h>

#define NONBLANK 'a'

/*  replace a string of blanks with a single blank  */

int main()
{
	int c;
	int lastc = NONBLANK;
	
	while ((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
	
	return 0;
}
