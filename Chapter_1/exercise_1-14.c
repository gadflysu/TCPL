#include <stdio.h>

#define MAXHIST 15
#define MAXCHAR 128

int main()
{
	int nc[MAXCHAR] = {0};
	int i, len, maxnc;
	int c;
	
	while ((c = getchar()) != EOF) {
		++nc[c];
	}
	maxnc = 0;
	for (i = 0; i < MAXCHAR; i++)
		if (nc[i] > maxnc)
			maxnc = nc[i];
	for (i = 0; i < MAXCHAR; i++) {
		if (nc[i] > 0) {
			if (i != ' ' && i != '\n' && i != '\t') {
				printf(" ");
				putchar(i);
			}
                        else
				switch (i) {
					case ' ' :
						printf("\\_");
						break;
					case '\n' :
						printf("\\n");
						break;
					case '\t' :
						printf("\\t");
						break;
				}
			printf(" - %3d :  ", nc[i]);
			if ((len = nc[i]/maxnc*MAXHIST) <= 0)
				len = 1;
//			else
//				len = 0;
			while (len-- > 0)
				printf("*");
			printf("\n");
		}
	}
	
	return 0;
}

