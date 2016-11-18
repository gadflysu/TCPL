#include <stdio.h>

#define LIM 10000
#define IN  1
#define OUT 0

void showChart(int chart[], int *maxL);

int main()
{
        int i, j;
        int c;
        int lenWord, maxLen, state;
        int chart[LIM] = {0};
        
	state = OUT;
	lenWord = 0;
	maxLen = lenWord;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {        	 /* finish the word  */
			if (state == IN) {                              
				state = OUT;
				++chart[lenWord];
				maxLen = (maxLen > lenWord) ? maxLen : lenWord;
				lenWord = 0;
			}
		} else {						/*  beginning of word  */
			++lenWord;
			if (state == OUT)		
				state = IN;     
		}
	}
	++chart[lenWord];
	
	showChart(chart, &maxLen);

	return 0;
}

void showChart(int chart[], int *maxL)
{
	int i, j;
	int maxLen = *maxL;
	
	for (i = 1; i <= maxLen; i++) {
		printf("%d | ", i);
		for (j = 0; j < chart[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}

