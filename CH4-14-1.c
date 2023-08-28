#define swap(t, x, y) \
{ \
    t c;\
    c = x;\
    x = y; \
    y = c; \
}

#include <stdio.h>

main()
{
    int a = 0, b = 1;
    swap(int, a, b); // no arguments can have the name c
    printf("a = %d, b = %d", a, b);

    return 0;
}
