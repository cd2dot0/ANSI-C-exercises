#include <stdio.h>

/*  replace each string of one or more blanks by a single blank */
main()
{
    int c, s;

    s = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++s;
        }
        if(c != ' ')
        {
            s = 0;
        }
        if(s < 2)
        {
            putchar(c);
        }
    }
}

