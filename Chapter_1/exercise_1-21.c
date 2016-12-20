#include <stdio.h>

#define TABINC 8        /*  tab increment size		*/

void rmBlanks(char bf[], int *pos);
void clearBf(char a[], int *pos);

/*  erplace blanks with the least number of tabs and blanks	*/
/*  solution from The C Answer Book				*/
/*
int main()
{
	int c, nb, nt, pos;

	nb = 0;                 			//  # of blanks necessary
	nt = 0;                 			//  # of tabs necessary
	for (pos = 1; (c = getchar()) != EOF; ++pos) {
		if (c == ' ') {
			if (pos % TABINC != 0)
				++nb;           	//  increment # of blanks
			else {
				nb = 0;         	//  reset # of blanks
				++nt;           	//  one more tab
			}
		} else {
			for ( ; nt > 0; --nt)
				putchar('\t');  	//  output tab(s)
			if (c == '\t')          	//  forget the blank(s)
				nb = 0;
			else                    	//  output blank(s)
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABINC - pos%TABINC);
		}
	}
}
*/

/*  another solution by GadflySu			*/
int main()
{
        int c, nb, pos;
        char bf[TABINC]; 		/*  buffer	*/

        pos = 0;
        while ((c = getchar()) != EOF) {
        	if (c == '\n') {                        /*  new line character		*/
			bf[pos++] = c;
			clearBf(bf, &pos);
		} else if ((pos+1 == TABINC && c == ' ') || c == '\t') {	/*  buffer full, end with blanks or tabs	*/
        		rmBlanks(bf, &pos);
			bf[pos++] = '\t';
			clearBf(bf, &pos);
		} else if (pos+1 == TABINC) {           /*  buffer NORMAL full		*/
			bf[pos++] = c;
			clearBf(bf, &pos);
		} else {                        	/*  all other character		*/
			bf[pos++] = c;
		}
	}
	clearBf(bf, &pos);

	return 0;
}

void rmBlanks(char a[], int *pos)
{
	while (a[*pos-1] == ' ')
		-- *pos;
}

void clearBf(char bf[], int *pos)
{
	int i;
	
	for (i = 0; i < *pos; ++i)
		putchar(bf[i]);
	*pos = 0;
}
