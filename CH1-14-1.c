#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define ASCII 128 /* number of ASCII characters */

/* horizontal histogram of the frequencies of different characters */
main()
{
    int c, i, j;
    int hist[ASCII];

    for(i = 0; i < ASCII; ++i)
    {
        hist[i] = 0;
    }
    while((c = getchar()) != EOF)
    {
        ++hist[c];
    }
    // print histogram
    for(i = 0; i < ASCII; ++i)
    {
        printf("%3d: ",i); // character numbers by ASCII code table
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
