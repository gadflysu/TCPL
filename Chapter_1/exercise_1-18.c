#include <stdio.h>
#define MAXLINE 1000    /*  maxmium input line size	*/

int getline(char line[], int maxline);
int rm(char s[]);

/*  remove trailing blanks and tabs, delete blank lines		*/
int main()
{
	char line[MAXLINE];     /*  current input line		*/

	while (getline(line, MAXLINE) > 0)
		if (rm(line) > 0)
			printf("%s", line);

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

/*  remove trailing blanks and tabs from character steing s	*/
int rm(char s[])
{
	int i;
	
	i = 0;
	while (s[i] != '\n')    /*  find new line character	*/
		++i;
	--i;                    /*  back off from '\n'		*/
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0) {           /*  is it a nonblank line?	*/
		s[++i] = '\n';  /*  put newline character back	*/
		s[++i] = '\0';  /*  terminate the string	*/
	}
	
	return i;
}
