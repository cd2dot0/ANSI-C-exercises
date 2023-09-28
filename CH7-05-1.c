#include <stdio.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

int idx; // index of temporary array
char temp[MAXOP]; // array of temporary characters from scanf

/* reverse Polish calculator with scanf */
main()
{
    int type;
    double op2;
    float f;
    char s[MAXOP];

    temp[0] = '\0';
    idx = 0;
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                sscanf(s,"%f",&f);
                push(f);
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
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}


#include <ctype.h>

/* getop: get next character or numeric operand with scanf */
int getop(char s[])
{
    int i;

    if(temp[idx] == '\0') // all characters were used - get new ones
    {
        if(scanf("%s", temp) == EOF)
            return EOF;
        idx = 0;
    }
    s[0] = temp[idx];
    s[1] = '\0';
    if(!isdigit(temp[idx]) &&  temp[idx] != '.')
        return temp[idx++];  /* not a number */
    i = 0;
    if(isdigit(temp[idx])) /* collect integer part */
        while(isdigit(s[++i] = temp[++idx]))
            ;
    if(temp[idx] == '.') /* collect fraction part */
        while(isdigit(s[++i] = temp[++idx]))
            ;
    s[i] = '\0';
    return NUMBER;
}
