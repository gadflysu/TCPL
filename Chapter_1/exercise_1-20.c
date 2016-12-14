#include <stdio.h>

int main()
{
        int c, nc;
        int i, n;
        
        nc = 0;
        n = 8;
        while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = 0; i < (n - nc%n); ++i)
				putchar(' ');
			nc = 0;
		}
		else {
			putchar(c);
			if (c == '\n')
				nc = 0;
			else
				++nc;
		}
	}

	return 0;
}

