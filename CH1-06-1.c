#include <stdio.h>

/* print the comparison value getchar() != EOF */
main()
{
    int c;
    c = getchar() != EOF; // operator != has higher precedence
    printf("%d",c);
}

