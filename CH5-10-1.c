#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char [], int *, char *);
void push(double);
double pop(void);

/* expr: reverse Polish calculator */
/* multiplication character is passed as *_ argument, because * is some special character */
main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    int *p_argc = &argc; // pointer to argc

    while((type = getop(s, p_argc, *++argv)) != EOF) // *++argv is pointer to char array of next argument
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                argc = 1;
                break;
        }
    }
    // print result in the end
    printf("\t%.8g\n", pop());
    return 0;
}


#include <ctype.h>

/* getop: get next character or numeric operand */
int getop(char s[], int *p_argc, char *one_arg)
{
    int i, c;

    if(--*p_argc > 0)
    {
        s[0] = c = *one_arg; // first character of the passed argument
        s[1] = '\0';
        if(!isdigit(c) &&  c != '.')
            return c;  /* not a number */
        i = 0;
        if(isdigit(c)) /* collect integer part */
            while(isdigit(s[++i] = c = *++one_arg))
                ;
        if(c == '.') /* collect fraction part */
            while(isdigit(s[++i] = c = *++one_arg))
                ;
        s[i] = '\0';
        return NUMBER;
    }
    else // the end of arguments (operators and operands)
        return EOF;
}
