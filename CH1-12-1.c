#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* print one word per line */
main()
{
    int c, c_prev, state;

    c_prev = '\n';
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT) // new word, so we move to new line
        {
            state = IN;
            if(c_prev != '\n') // if previous character wasn't newline, we insert newline before word
            {
                putchar('\n');
            }
        }
        putchar(c);
        c_prev = c;
    }
}
