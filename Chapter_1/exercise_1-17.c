#include <stdio.h>
#define MAXLINE 1000    /*  maxmium input line size	*/
#define LIM 80

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*  print longest input line  */
int main()
{
	int len;               /*  current line length		*/
	char line[MAXLINE];     /*  current input line		*/
	char longest[MAXLINE];  /*  longest line saved here	*/

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LIM)
			printf("%s", line);

	return 0;
}

/*  getline: read a line into s, return length  */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim-2)
			s[j++] = c;
	if (c == '\n')
		s[j++] = c;
	s[j] = '\0';

	return i;
}

