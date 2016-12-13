#include <stdio.h>
#define MAXLINE 1000    /*  maxmium input line size	*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*  print longest input line  */
int main()
{
	int len;		/*  current line length		*/
	int max;                /*  maxmium length seen so far  */
	char line[MAXLINE];     /*  current input line		*/
	char longest[MAXLINE];  /*  longest line saved here	*/

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		printf("%d %s", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)            /* there was a line		*/
		printf("%s", longest);

	return 0;
}

/*  getline: read a line into s, return length  */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	int j = i;
	while ((j > 0) && (s[j-1] == ' ' || s[j-1] == '\t'))
		--j;
	if (c == '\n') {
		++i;
		if (j > 0)
			s[j++] = c;
	}
	s[j] = '\0';

	return i;
}
/*  copy: copy 'from' into 'to'; assumed to is big enough */
void copy(char from[], char to[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
