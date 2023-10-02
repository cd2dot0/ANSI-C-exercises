#include <ctype.h>
#include <stdio.h>
#include <time.h>

#define isupper2(c) (((c) >= 'A' && (c) <= 'Z') ? (c) : 0)
#define NUMCALL 1000000000

int isupper1(int c);

int main()
{
    int i, d;
    char c = 'M';
    clock_t t1, t2;
    double diff;

    // my own function (function saves space that would be needed for a macro or an array)
    t1 = clock();
    for(i = 0; i < NUMCALL; i++)
        d = isupper1(c);
    t2 = clock();
    diff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    printf("time of my own function: %.3f s\n", diff);

    // my own macro (macro executes faster, so it saves time)
    t1 = clock();
    for(i = 0; i < NUMCALL; i++)
        d = isupper2(c);
    t2 = clock();
    diff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    printf("time of my own macro: %.3f s\n", diff);

    // library function
    t1 = clock();
    for(i = 0; i < NUMCALL; i++)
        d = isupper(c);
    t2 = clock();
    diff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    printf("time of library function: %.3f s\n", diff);

    return 0;
}

int isupper1(int c)
{
    return (c >= 'A' && c <= 'Z') ? c : 0;
}
