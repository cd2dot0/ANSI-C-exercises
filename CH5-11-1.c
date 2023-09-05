#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void no_tab(char line[], char new_line[], int list_jump[]);
void create_list(int argc, char *argv[], int list_jump[], int lim);

/* detab: replace tabs with spaces in the input data; accept a list of tab stops as arguments */
main(int argc, char *argv[])
{
    char line[MAXLINE]; /* current input line */
    char new_line[MAXLINE]; /* revised line */
    int list_jump[MAXLINE]; // list of jumps to the next tab position

    create_list(argc, argv, list_jump, MAXLINE);

    while(getline(line, MAXLINE) > 0)
    {
        no_tab(line, new_line, list_jump);
        printf("%s", new_line);
    }
    return 0;
}

/* no_tab: remove tabs and replace them with spaces in such a way that the tab position does not change */
void no_tab(char s[], char new_s[], int list_jump[])
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
            jump = list_jump[j]; // get the length of jump from list
            if(j + jump >= MAXLINE)
                jump = MAXLINE - j - 1; // decrease number of spaces to avoid overflow of array
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
