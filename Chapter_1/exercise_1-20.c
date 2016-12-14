#include <stdio.h>

#define TABINC 8        /*  tab increment size		*/

/*  erplace tabs with the proper number of blanks	*/
int main()
{
        int c, nb, pos;
        
        pos = 0;
        while ((c = getchar()) != EOF) {
		if (c == '\t') {                        /*  tab character		*/
			int nb = (TABINC - pos%TABINC);	/*  number of blanks necessary	*/
			while (nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		} else if (c == '\n') {       		/*  new line character		*/
			putchar(c);
			pos = 0;
		} else {                        	/* all other character		*/
			putchar(c);
			++pos;
		}
	}

	return 0;
}

