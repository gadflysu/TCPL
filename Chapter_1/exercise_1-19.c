#include <stdio.h>
#define MAXLINE 1000    /*  maxmium input line size	*/

int getline(char line[], int maxline);
void reverse(char s[]);

/*  reverse character string s		*/
int main()
{
	char s[MAXLINE];

	while (getline(s, MAXLINE) > 0) {
		reverse(s);
		printf("%s", s);
	}
	
	return 0;
}

/*  getline: read a line into s, return length  */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/*  reverse character line			*/
void reverse(char s[])
{
	int i, n;
	
	n = -1;
	while (s[++n] != '\0')
		;
	for (i = 0; i < n/2; ++i) {
		int temp = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = temp;
	}
}
