#include <stdio.h>

/*  Count the number of characters ' ', '\t' and '\n' in the input  */

int main()
{
	int c;
	int ns, nt, nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++ns;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("Space: %d\nTab: %d\nNewline: %d\n", ns, nt, nl);
}
