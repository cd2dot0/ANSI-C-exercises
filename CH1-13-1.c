#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* horizontal histogram of the lengths of words */
main()
{
    int c, n, state, i, j;
    int hist[21];

    state = OUT;
    n = 0;
    for (i = 0; i < 21; ++i)
    {
        hist[i] = 0;
    }
    while((c = getchar()) != EOF)
    {   // check if we are IN word
        if(c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if(state == OUT)
        {
            state = IN;
        }
        if(state == IN)
        {   // count consecutive characters in word
            ++n;
        }
        else if(n != 0)
        {   // end of word - increment of corresponding array element
            if(n < 21)
            {
                ++hist[n-1];
            }
            else
            {   // over 20 characters in word
                ++hist[20];
            }
            n = 0;
        }
    }
    // print histogram
    for(i = 0; i < 21; ++i)
    {
        if(i < 20)
        {
           printf("%3d: ",i + 1);
        }
        else
        {
           printf(">20: ");
        }
        for(j = hist[i]; j > 0; --j)
        {
            printf("#");
            if(j == 1)
            {
                printf(" ");
            }
        }
        printf("%d\n",hist[i]);
    }
}
