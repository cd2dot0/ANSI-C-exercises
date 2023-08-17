#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TABPOS 8 /* tab width */
#define N 120 /* N-th column of the line - new line character must be before it */

int getline(char line[], int maxline); /* functions prototypes */
void cut_line(char line[], char new_line[]);

/* "fold" long input lines into two or more shorter lines */
main()
{
    char line[MAXLINE]; /* current input line */
    char new_line[MAXLINE]; /* revised line */

    while(getline(line, MAXLINE) > 0)
    {
        cut_line(line, new_line);
    }
    return 0;
}

/* cut_line: split long lines into two or more shorter lines and print them */
/* the split point is before N-th column on the last character that is not a blank or tab (if possible) */
void cut_line(char s[], char new_s[])
{
    int i, j, pos, jump, temp_j, temp_i, reset, white_ok;

    pos = 1; // position
    j = reset = white_ok = 0;
    // break the loop when null character was found
    for(i = 0; s[i] != '\0'; ++i)
    {
        new_s[j] = s[i];
        // the reset state is disabled when the first non-white character is found after the line is truncated
        if(reset == 1 && (new_s[j] != '\t' && new_s[j] != ' '))
            reset = 0;
        if(pos == N) // position equals N-th column
        {
            temp_j = j; // assign current index values to temporary variables
            temp_i = i;
            // seek white characters
            while((new_s[j] != '\t' && new_s[j] != ' ') && j >= 0) // "rewinding"
            {
                --j;
                --i;
            }
            if(j >= 0) // white character is found
                white_ok = 1;
            else // no white characters
            {
                // restore the indexes from before the "rewinding" minus 1
                // to return to the position before N-th column
                j = temp_j - 1;
                i = temp_i - 1;
                new_s[j+1] = '\n'; // cut line and print
                new_s[j+2] = '\0';
                printf("%s", new_s);
                reset = 1;
            }
        }
        else if(pos > N) // position after N-th column (the previous character was a tab)
        {
            --j; // back to tab
            --i;
            white_ok = 1;
        }
        if(white_ok == 1)
        {
            temp_j = j; // assign current index values to temporary variables
            temp_i = i;
            // seek non-white characters
            while((new_s[j] == '\t' || new_s[j] == ' ') && j >= 0) // "rewinding"
            {
                --j;
                --i;
            }
            if(j < 0) // no non-white characters
            {
                // restore the indexes from before the "rewinding"
                // to return to the position of first white character that was found
                j = temp_j;
                i = temp_i;
            }
            new_s[j+1] = '\n'; // cut line and print
            new_s[j+2] = '\0';
            printf("%s", new_s);
            reset = 1;
            white_ok = 0;
        }
        ++j;
        // determine the current position
        if(s[i] != '\t')
            ++pos;
        else
        {
            jump = TABPOS - ((pos-1)%TABPOS); // calculate how many spaces are equal to tab jump
            pos = pos + jump;
        }
        if(reset == 1) // when the line is truncated, reset state is enabled
        {              // set j and pos to their initial values
            j = 0;
            pos = 1;
        }
    }
    // add 1 element ending line
    new_s[j] = '\0';
    printf("%s", new_s);
}

