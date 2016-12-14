#include <stdio.h>

#define TABINC 8        /*  tab increment size		*/

void rmBlanks(char bf[], int *pos);
void clearBf(char a[], int *pos);

/*  erplace blanks with the least number of tabs and blanks	*/
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
