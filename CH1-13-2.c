#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* vertical histogram of the lengths of words */
main()
{
    int c, n, max_occ, state, i, j;
    int hist[21];

    state = OUT;
    n = max_occ  = 0;
    for (i = 0; i < 21; ++i)
        hist[i] = 0;
    // count words of individual lengths
    while((c = getchar()) != EOF)
    {   // check if we are IN word
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT)
            state = IN;
        if(state == IN)
            ++n; // count consecutive characters in word
        else if(n != 0)
        {   // end of word - increment of corresponding array element
            if(n < 21)
                ++hist[n-1];
            else // over 20 characters in word
                ++hist[20];
            n = 0; // reset counter of characters in word
        }
    }
    // update max number of occurences
    for(i = 0; i < 21; ++i)
        if(hist[i] > max_occ)
            max_occ = hist[i];
    // print histogram
    for(j = max_occ + 1; j > 0 ; --j)
    {
        for(i = 0; i < 21; ++i)
            if(hist[i] >= j)
                printf("### ");
            else if((hist[i] + 1) == j)
                printf("%2d  ",hist[i]);
            else
                printf("    ");

        printf("\n");
    }
    for(i = 0; i < 20; ++i)
        printf("%2d  ",i + 1);
    printf(">20 \n");
}
