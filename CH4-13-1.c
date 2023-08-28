#include <string.h>

/* reverse_rec: reverse the string s in place with recursion */
void reverse_rec(char s[])
{
    int c, j;
    static int i = 0;

    j = strlen(s) - 1 - i;

    if(i < j)
    {
        c = s[i];
        s[i++] = s[j];
        s[j] = c;
        reverse_rec(s);
    }
}
