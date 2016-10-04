#include <stdio.h>

/*  count blanks, tabs, and newlines  */

int main()
{
	int c;
	int nb, nt, nl = 0;  /*  number of blanks, tabs, newlines  */
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", nb, nt, nl);
}
