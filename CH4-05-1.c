#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'N' /* signal that a name was found */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void math_fun(char []);

/* reverse Polish calculator */
/* 1) handle the modulus (%) operator and negative numbers */
/* 2) handle the commands: */
/*    * to print the top element of the stack without popping, */
/*    * to duplicate it, */
/*    * to swap the top two elements, */
/*    * to clear the stack */
/* 3) handle the basic functions of the math.h library */
main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

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
            case '%':
                op2 = pop();
                if(((int) op2) != 0)
                    push(((int) pop()) % ((int) op2)); // force the conversion to int (alternatively you can use fmod function)
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 'S': // print the top element of the stack without popping
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'D': // duplicate the top element of the stack
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 'E': // swap the top two elements
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
                break;
            case 'C': // clear the stack
                clear();
                break;
            case NAME: // check if the name is a mathematical function
                math_fun(s);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0; /* next free stack position */

/* clear: clear the entire stack */
void clear(void)
{
    sp = 0;
}

/* mathfun: execute the proper mathematical function if the name is correct */
void math_fun(char s[])
{
    int i, j, stop = 0;
    double op2;
    char t[6][10] = { {"sin\0"}, {"cos\0"}, {"exp\0"}, {"pow\0"}, {"log\0"}, {"sqrt\0"} };

    for(j = 0; j <= 5; j++)
    {
        i = 0;
        switch(j)
        {
        case 0: //sin
            while(s[i] != '\0' && s[i] == t[j][i])
                i++;
            if(s[i] == '\0')
            {
                push(sin(pop()));
                stop = 1;
            }
            break;
        case 1: // cos
            while(s[i] != '\0' && s[i] == t[j][i])
                i++;
            if(s[i] == '\0')
            {
                push(cos(pop()));
                stop = 1;
            }
            break;
        case 2: // exp
            while(s[i] != '\0' && s[i] == t[j][i])
                i++;
            if(s[i] == '\0')
            {
                push(exp(pop()));
                stop = 1;
            }
            break;
        case 3: // pow
            while(s[i] != '\0' && s[i] == t[j][i])
                i++;
            if(s[i] == '\0')
            {
                op2 = pop();
                push(pow(pop(),op2));
                stop = 1;
            }
            break;
        case 4: // log
            while(s[i] != '\0' && s[i] == t[j][i])
                i++;
            if(s[i] == '\0')
            {
                push(log(pop()));
                stop = 1;
            }
            break;
        case 5: // sqrt
            while(s[i] != '\0' && s[i] == t[j][i])
                i++;
            if(s[i] == '\0')
            {
                push(sqrt(pop()));
                stop = 1;
            }
            break;
        }
        if(stop == 1) // break the loop, because a function was found
            break;
    }
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    i = 0;
    if(c >= 'a' && c <= 'z') // there is a name
    {
        c = getch();
        while(c >= 'a' && c <= 'z')
        {
            s[++i] = c;
            c = getch();
        }
        if(c != EOF)
            ungetch(c);
        s[++i] = '\0';
        return 'N';
    }
    if(c == '+' || c == '-') // there is a sign
    {
        s[++i] = getch();
        if(!isdigit(s[i]) &&  s[i] != '.') // the sign doesn't begin a number
        {
            if(s[i] != EOF)
                ungetch(s[i]);
        }
        else // the sign begins a number
            c = s[i];
    }
    if(!isdigit(c) &&  c != '.')
    {
        s[1] = '\0';
        return c;  /* not a number */
    }
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
