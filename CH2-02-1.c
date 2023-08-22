#include <stdio.h>

#define MAXLINE 1000

/* replace the for loop from the function getline without using && or || */
main()
{
    int i, lim, stop;
    char c, s[MAXLINE];

    lim = MAXLINE;

    // original loop
    // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    //     s[i] = c;
    // end of original loop

    // loop equivalent
    stop = 0;
    i = 0;
    while(stop == 0)
    {
        if(i < lim - 1)
        {
            if((c = getchar()) != '\n')
            {
                if(c != EOF)
                {
                    s[i] = c;
                    ++i;
                }
                else
                    stop = 1;
            }
            else
                stop = 1;
        }
        else
            stop = 1;
    }
    // end of loop equivalent
    s[i] = '\0';

    return 0;
}
