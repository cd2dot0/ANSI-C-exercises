#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TABPOS 8 /* tab width */

int getline(char line[], int maxline); /* functions prototypes */
void no_tab(char line[], char new_line[]);

/* detab: replace tabs with spaces in the input data */
main()
{
    char line[MAXLINE]; /* current input line */
    char new_line[MAXLINE]; /* revised line */

    while(getline(line, MAXLINE) > 0)
    {
        no_tab(line, new_line);
        printf("%s", new_line);
    }
    return 0;
}

/* no_tab: remove tabs and replace them with spaces in such a way that the tab position does not change */
void no_tab(char s[], char new_s[])
{
    int i, j, jump;

    j = 0;
    // break the loop when newline character was found
    // or it remains less than 3 free elements in temporary array
    for(i = 0; s[i] != '\n' && j < MAXLINE - 2; ++i)
    {
        if(s[i] != '\t')
        {
            new_s[j] = s[i];
            ++j;
        }
        else
        {
            jump = TABPOS - (j%TABPOS); // calculate how many spaces are equal to tab jump
            if(j + jump >= MAXLINE)
                jump = MAXLINE - j - 1; //  decrease number of spaces to avoid overflow of array
            while(jump > 0)
            {
                new_s[j] = ' ';
                ++j;
                --jump;
            }
        }
    }
    // add 2 elements ending line
    if(j < MAXLINE - 2)
    {
        new_s[j] = '\n';
        new_s[j+1] = '\0';
    }
    else
    {
        new_s[MAXLINE - 2] = '\n';
        new_s[MAXLINE - 1] = '\0';
    }
}
