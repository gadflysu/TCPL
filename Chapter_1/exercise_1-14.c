#include <stdio.h>

#define MAXHIST 15
#define MAXCHAR 128

int main()
{
	int c, i;
	int len;		/*  length of each bar		*/
	int maxvalue;           /*  maximum value of nc[]	*/
	int nc[MAXCHAR] = {0};  /*  character counters		*/

	while ((c = getchar()) != EOF) {
		if (c < MAXCHAR)
			++nc[c];
	}
	maxvalue = 0;
	for (i = 1; i < MAXCHAR; i++)
		if (nc[i] > maxvalue)
			maxvalue = nc[i];
	for (i = 1; i < MAXCHAR; i++) {
		if (isprint(i))
			printf("%5d - %c - %5d :  ", i, i, nc[i]);
		else
			printf("%5d -   - %5d :  ", i, nc[i]);
                if (nc[i] > 0) {
			if ((len = nc[i]/maxvalue*MAXHIST) <= 0)
				len = 1;
		} else
			len = 0;
		while (len-- > 0)
			printf("*");
		putchar('\n');
	}
	
	return 0;
}

