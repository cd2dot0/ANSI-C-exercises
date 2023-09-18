#include <stdio.h>
#include <ctype.h>

/* getword: get next word or character from input */
/* handle underscores, string constants, comments and preprocessor control lines */
/* detect names of functions */
int getword(char *word, int lim)
{
    // 0 - normal state, 1 - character constant, 2 - string constant, 3 - comment, 4 - preprocessor control line
    static int state = 0;
    int next_line = 0;

    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(state != 0)
    {
        c = getch();
        if(state == 1 && c == '\'')      // the end of character constant
            state = 0;
        else if(state == 2 && c == '\"') // the end of string constant
            state = 0;
        else if((state == 1 || state == 2) && c == '\\') // ignore the next character
            getch();
        else if(state == 3 && c == '*')
        {
            if((c = getch()) == '/')     // the end of comment
                state = 0;
            else
                ungetch(c);
        }
        else if(state == 4 && c == '\\') // extend the preprocessor control command by next line
            next_line = 1;
        else if(state == 4 && c == '\n')
        {
            if(next_line == 1)           // go to next line of preprocessor control command
                next_line = 0;
            else                         // the end of preprocessor control command
                state = 0;
        }
        else if(c == EOF)
        {
            *w = '\0';
            return c;
        }
    }

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c) && c != '_')
    {
        if(c == '\'') // the beginning of character constant
        {
            state = 1;
            *--w = '\0';
            return 1;
        }
        else if(c == '\"') // the beginning of string constant
        {
            state = 2;
            *--w = '\0';
            return 2;
        }
        else if(c == '/')
        {
            if((c = getch()) == '*') // the beginning of comment
                {
                    state = 3;
                    *--w = '\0';
                    return 3;
                }
            else
                ungetch(c);
        }
        else if(c == '#') // the beginning of preprocessor control command
        {
            state = 4;
            *--w = '\0';
            return 4;
        }
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++) // word
        if(!isalnum(*w = getch()) && *w != '_')
        {
            if(isspace(*w)) // the first character after this word is white
            {
                while(isspace(c = getch())) // seek the first non-white character
                    ;
                *w = c;
            }
            if(*w == '(') // the word is a function name, so it is not a variable
               word[0] = '\0';

            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
