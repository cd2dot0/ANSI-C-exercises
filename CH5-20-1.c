#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
void check_type(void);
int check_args(void);

int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char arguments[MAXTOKEN];   // the inside of the function
char out[1000];
int repeat_token = 0;

/* convert declaration to words; handle declarations with function argument types, qualifiers */
/* detect and handle following errors in input data: */
/* 1) wrong data type and/or wrong qualifiers for this type were entered */
/* 2) there are additional spaces inside () or [] */
/* 3) there are wrong expressions inside [] */
/* 4) parser did not end its work after error in dirdcl() */
/* Re 4: e.g. if an error was caused by the token '\n', this token must be artificially repeated */
/* to end the current iteration of the while loop, otherwise the parser will not finish its work */
/* and will consider the declaration from the next line as a continuation of the old declaration */
main()
{
    while(gettoken() != EOF)        // 1st token on line
    {                               // is the datatype with possible qualifiers
        check_type();
        out[0] = '\0';
        dcl();  /* parse rest of line */
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* gettoken: return next token */
int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    int i = 0;

    if(repeat_token) // repeat previous token
    {
        repeat_token = 0;
        return tokentype;
    }
    while((c = getch()) == ' ' || c == '\t')
        ;
    if(c == '(')
    {
        while((c = getch()) == ' ' || c == '\t') // skip spaces and tabs
            ;
        if(c == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            if(isalpha(c))
            {
                for(*p++ = c; isalnum(c = getch()); i++)
                    *p++ = c;
                *p = '\0';
                ungetch(c);
                if(check_args() > 0) // this is the inside of the function
                    return tokentype;
                else // this is not the inside of the function
                {
                    while(i-- >= 0)
                        ungetch(*--p);
                    return tokentype = '(';
                }
            }
            else // this is not the inside of the function
            {
                ungetch(c);
                return tokentype = '(';
            }
        }
    }
    else if (c == '[')
    {
        *p++ = c;
        while((c = getch()) == ' ' || c == '\t') // skip spaces and tabs
            ;
        if(c == ']') // empty square bracket
            *p++ = c;
        else if(isdigit(c)) // square bracket with the size giving as a number
            {
                for(*p++ = c; isdigit(c = getch()); ) // write consecutive digits
                    *p++ = c;
                ungetch(c);
                while((c = getch()) == ' ' || c == '\t') // skip spaces and tabs
                    ;
                if(c == ']')
                    *p++ = c;
                else
                    printf("error: wrong array size\n");
            }
        else if(isalpha(c)) // square bracket with the size giving as a name
        {
            for(*p++ = c; isalnum(c = getch()); ) // write consecutive alphanumeric characters
                *p++ = c;
            ungetch(c);
            while((c = getch()) == ' ' || c == '\t') // skip spaces and tabs
                ;
            if(c == ']')
                *p++ = c;
            else
                printf("error: wrong array size\n");
        }
        else
            printf("error: wrong array size\n");
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

/* dirdcl: parse a direct declarator */
/* the token causing the error is reused by gettoken function */
void dirdcl(void)
{
    int type;

    if(tokentype == '(') /* ( dcl ) */
    {
        dcl();
        if(tokentype != ')')
        {
            printf("error: missing )\n");
            repeat_token = 1;
        }
    }
    else if(tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
    {
        printf("error: expected name or (dcl)\n");
        repeat_token = 1;
    }
    while((type = gettoken()) == PARENS || type == BRACKETS)
        if(type == PARENS)
        {
            strcat(out, " function (");
            strcat(out, arguments);
            strcat(out, ") returning");
        }
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}
