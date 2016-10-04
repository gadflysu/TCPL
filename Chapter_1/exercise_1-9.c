#include <stdio.h>

/*  copy input to output and reduce the whitespaces to leave only a single space  */

int main()
{
	int c;
	int nb = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else nb = 0;
		if (nb <= 1)
			putchar(c);
	}
}
