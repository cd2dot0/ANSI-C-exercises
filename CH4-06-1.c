#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define ASSIGNMENT '1' /* signal that a value will be assigned to a variable */
#define VARIABLE '2' /* signal that a variable was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
/* handle 52 variables (lower and upper case single letters) and have a variable for the most recently printed value */
/* the command =c assigns a value from the stack to the variable c */
main()
{
    int type, i;
    double op2, last, var[52];
    char s[MAXOP];

    for(i = 0; i < 52; i++)
        var[i] = 0.0;

    while((type = getop(s)) != EOF)
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
            case '\n':
                printf("\t%.8g\n", last = pop()); // assign the most recently printed value to the variable
                break;
            case '#':
                push(last);
                break;
            case ASSIGNMENT: // assign the top element of the stack to the variable
                op2 = pop();
                if(islower(s[1]))
                     var[s[1] - 'a'] = op2;
                else
                    var[s[1] - 'A' + 26] = op2;
                push(op2);
                break;
            case VARIABLE: // use the variable
                if(islower(s[0]))
                    push(var[s[0] - 'a']);
                else
                    push(var[s[0] - 'A' + 26]);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(c == '=')
    {
        c = getch();
        if(islower(c) || isupper(c))
        {
            s[1] = c;
            s[2] = '\0';
            return ASSIGNMENT;
        }
        else
        {
            if(c != EOF)
                ungetch(c);
            return s[0];
        }
    }
    else if(islower(c) || isupper(c))
    {
        return VARIABLE;
    }
    if(!isdigit(c) &&  c != '.')
        return c;  /* not a number */
    i = 0;
    if(isdigit(c)) /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') /* collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
