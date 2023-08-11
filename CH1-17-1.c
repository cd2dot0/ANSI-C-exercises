#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MINCHAR 81 /* minimum number of characters that qualifies a line for print */

int getline(char line[], int maxline);

/* print all input lines that are not shorter than MINCHAR characters */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = getline(line, MAXLINE)) > 0)
        if(len >= MINCHAR)
        {
            printf("%s", line);
        }
    return 0;
}

