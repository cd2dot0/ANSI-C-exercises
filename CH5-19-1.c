#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);

int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char out[1000];

/* undcl: convert word descriptions to declarations; do not add redundant parentheses */
main()
{
    int type;
    char temp[MAXTOKEN];
    int ready; // be ready to insert previously parenthesis if there will be () or []

    while(gettoken() != EOF)
    {
        strcpy(out, token); // name - the simplest type of dirdcl
        ready = 0;
        while((type = gettoken()) != '\n')
            if(type == PARENS || type == BRACKETS)
            {
                if(ready)
                {
                    sprintf(temp, "(%s)", out);
                    strcpy(out, temp);
                    ready = 0;
                }
                strcat(out, token);
            }
            else if(type == '*')
            {
                sprintf(temp, "*%s", out);
                strcpy(out, temp);
                ready = 1;
            }
            else if(type == NAME) // data type (int/char)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}

/* gettoken: return next token */
int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while((c = getch()) == ' ' || c == '\t')
        ;
    if(c == '(')
    {
        if((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for(*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if(isalpha(c))
    {
        for(*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}
