#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 100

struct nlist            /* table entry: */
{
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

void check_command(void);
int to_new_line(void);
struct nlist *install(char *, char *);
int getch(void);
void ungetch(int);

/* simple version of the #define processor */
main()
{
    char c;

    do // one iteration is one non-empty text line
    {
        while(isspace(c = getch())) // skip white characters
            ;
        if(c == '#') // preprocessor command
            check_command();
        while((c = getch()) != EOF && c != '\n') // wait until the end of line or file
            ;
    }
    while(c != EOF);

    return 0;
}

/* check_command: check preprocessor command */
void check_command(void)
{
    char c, command[MAXLEN + 1], name[MAXLEN + 1], defn[MAXLEN + 1];
    int i;

    // are there white characters before command?
    while(isspace(c = getch()) && c != '\n')
        ;
    if(c == '\n' || c == EOF)
    {
        printf("error: no command\n");
        ungetch(c);
        return;
    }
    ungetch(c);
    // command type
    for(i = 0; i < MAXLEN && (isalpha(c = getch()) || c == '\\'); )
    {
        if(c == '\\')
        {
            if(to_new_line() == 0)
                return;
        }
        else
            command[i++] = c;
    }
    command[i] = '\0';
    if(i >= MAXLEN)
    {
        printf("error: command too long\n");
        return; // there is no new character from getch
    }
    if(strcmp(command, "define") != 0)
    {
        printf("error: unknown command\n");
        ungetch(c);
        return;
    }
    // are there white characters before name?
    if(isspace(c) == 0 || c == '\n' || c == EOF)
    {
        printf("error: expected space after command\n");
        ungetch(c);
        return;
    }
    while((isspace(c = getch()) && c != '\n') || c == '\\')
        if(c == '\\')
        {
            if(to_new_line() == 0)
                return;
        }
    if(c == '\n' || c == EOF)
    {
        printf("error: no name\n");
        ungetch(c);
        return;
    }
    // name
    if(isalpha(c) || c == '_')
        name[0] = c;
    else
    {
        printf("error: wrong form of name\n");
        ungetch(c);
        return;
    }
    for(i = 1; i < MAXLEN && (isalnum(c = getch()) || c == '_' || c == '\\'); )
    {
        if(c == '\\')
        {
            if(to_new_line() == 0)
                return;
        }
        else
            name[i++] = c;
    }
    name[i] = '\0';
    if(i >= MAXLEN)
    {
        printf("error: name too long\n");
        return; // there is no new character from getch
    }
    // are there white characters before definition?
    if(isspace(c) == 0 || c == '\n' || c == EOF)
    {
        printf("error: expected space after name\n");
        ungetch(c);
        return;
    }
    while((isspace(c = getch()) && c != '\n') || c == '\\')
        if(c == '\\')
        {
            if(to_new_line() == 0)
                return;
        }
    if(c == '\n' || c == EOF)
    {
        printf("error: no definition\n");
        ungetch(c);
        return;
    }
    ungetch(c);
    // definition
    for(i = 0; i < MAXLEN && !isspace(c = getch()); )
    {
        if(c == '\\')
        {
            if(to_new_line() == 0)
                return;
        }
        defn[i++] = c;
    }
    defn[i] = '\0';
    if(i >= MAXLEN)
    {
        printf("error: definition too long\n");
        return; // there is no new character from getch
    }
    install(name, defn);
    ungetch(c);
    return;
}

/* to_new_line: check if there is a newline character after white characters */
int to_new_line(void)
{
    char c;

    while(isspace(c = getch()) && c != '\n')
        ;
    if(c != '\n')
    {
        printf("error: after '\\' expected new line\n");
        ungetch(c);
        return 0;
    }
    else
        return 1;
}
