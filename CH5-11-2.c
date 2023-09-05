#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void min_space(char line[], char new_line[], int list_jump[]);
void create_list(int argc, char *argv[], int list_jump[], int lim);

/* entab: replace strings of blanks by the minimum number of tabs and blanks; accept a list of tab stops as arguments */
main(int argc, char *argv[])
{
    char line[MAXLINE]; /* current input line */
    char new_line[MAXLINE]; /* revised line */
    int list_jump[MAXLINE]; // list of jumps to the next tab position

    create_list(argc, argv, list_jump, MAXLINE);

    while(getline(line, MAXLINE) > 0)
    {
        min_space(line, new_line, list_jump);
        printf("%s", new_line);
    }
    return 0;
}

/* min_space: remove strings of blanks and replace them by the minimum number of tabs and blanks to achieve the same spacing */
void min_space(char s[], char new_s[], int list_jump[])
{
    int i, j, k, jump, pos, space_pos;

    k = 0; // space counter
    pos = 1; // position
    j = 0;
    // break the loop when null character was found
    for(i = 0; s[i] != '\0'; ++i)
    {
        if(s[i] != ' ')
        {
            if(k != 0) // string of spaces ended
            {
                space_pos = pos - k; // first space position
                while(k > 0)
                {
                    jump = list_jump[space_pos-1]; // jump length
                    if(k >= jump)
                    {
                        new_s[j] = '\t';
                        ++j;
                        k = k - jump;
                        space_pos = space_pos + jump; // update
                    }
                    else
                    {
                        new_s[j] = ' ';
                        ++j;
                        --k;
                        ++space_pos; // update
                    }
                }
            }
            new_s[j] = s[i];
            ++j;
        }
        else
            ++k; // increment the space counter
        // determine the current position
        if(s[i] != '\t')
            ++pos;
        else
        {
            jump = list_jump[pos-1]; // get the length of jump from list
            pos = pos + jump;
        }
    }
    // add 1 element ending line
    new_s[j] = '\0';
}
