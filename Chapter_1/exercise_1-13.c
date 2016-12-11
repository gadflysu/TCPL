#include <stdio.h>

#define MAXHIST 15	/*  max length of histogram	*/
#define MAXWORD 11	/*  max length of a word	*/
#define IN  	1	/*  inside a word		*/
#define OUT 	0	/*  outside a word		*/

/*  print horizontal histogram				*/
int main()
{
        int c, i, nc, state;
        int len;                        /*  length of each bar		*/
        int maxvalue;                   /*  maximum value for wl[]  	*/
        int overflow;                   /*  number of overflow words  	*/
        int wl[MAXWORD] = {0};          /*  word length counters	*/
        
	state = OUT;
	nc = 0;                         /*  number of chars in a word	*/
	overflow = 0;                   /*  number of words >= MAXWORD	*/
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {        	 /* finish the word  */
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					++wl[nc];
				else
					++overflow;
			nc = 0;
		} else {						
			++nc;
			if (state == OUT)		                /*  beginning of word  */
				state = IN;     
		}
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	for (i = 1; i < MAXWORD; ++i) {
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i]*MAXHIST/maxvalue) <= 0)
				len = 1;
		} else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (overflow > 0)
		printf("There are %d words >= %d\n", overflow, MAXWORD);

	return 0;
}

