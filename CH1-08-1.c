#include <stdio.h>

/* counts blanks, tabs and newlines */
main()
{
    int c, nl, s, t, z;

    nl = 0;
    s = 0;
    t = 0;
    while((c=getchar()) != EOF)
    {
        if(c == '\n')
            ++nl;
        if(c == ' ')
            ++s;
        if(c == '\t')
            ++t;
    }
    z = nl+s+t;
    printf("Number of blanks: %d\nNumber of tabs: %d\nNumber of newlines: %d\nTotal number of above characters: %d",s,t,nl,z);
}
