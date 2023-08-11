#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
int cleanline(char line[]);

/* remove trailing blanks and tabs from each line of input, and delete entirely blank lines */
main()
{
    int show; /* 0/1 - hide/show line */
    char line[MAXLINE]; /* current input line */

    while(getline(line, MAXLINE) > 0)
    {
        show = cleanline(line);
        if(show == 1)
            printf("%s", line);
    }
    return 0;
}

/* cleanline: remove blanks and tabs at the end of line or entire line if it is empty */
int cleanline(char line[])
{
    int i,show;
    show = 0;

    for(i = 0; line[i] != '\0'; ++i) // seek last element of line (null character)
        ;
    if(i != 0)
    {
        --i; // go back to penultimate element
        // decrement variable i until non-white character is found
        while((i >= 0) && (line[i] == ' ' ||  line[i] == '\t' || line[i] == '\n'))
            --i;
        if(i >= 0)
        {
            line[i+1] = '\n'; // after last non-white character insert newline character
            line[i+2] = '\0'; // and null character, ending line

            show = 1;
        }
        else // all characters were white, so line is empty
            show = 0;
    }
    else // line contains only one null character, so is empty
        show = 0; // in practice, such case does not occur
                  // (because there is always at least newline character still)

    return show;
}
