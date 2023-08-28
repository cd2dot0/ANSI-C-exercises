#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line length */
#define NUMBER '0' /* signal that a number was found */

int getline(char s[], int lim);
void push(double);
double pop(void);

/* reverse Polish calculator */
/* read an entire input line */
main()
{
    int i, j, type;
    double op2;
    char line[MAXLINE], s[MAXLINE];

    while(getline(line, MAXLINE) > 0)
    {
        i = 0;
        while(line[i] != '\0')
        {
            while(line[i] == ' ' || line[i] == '\t') // skip spaces and tabs
                i++;
            if(!isdigit(line[i]) && line[i] != '.') // the element is not part of number
            {
                type = line[i];
                i++;
            }
            else // there is a number
            {
                j = 0;
                while(isdigit(line[i])) // integer part
                    s[j++] = line[i++];
                if(line[i] == '.') // fraction part
                {
                    s[j++] = line[i++];
                    while(isdigit(line[i]))
                        s[j++] = line[i++];
                }
                s[j] = '\0';
                type = NUMBER;
            }

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
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }

    return 0;
}
