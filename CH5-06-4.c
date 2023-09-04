#include <string.h>

/* reverse_ch3: reverse string s in place; function from Chapter 3, pointer version */
void reverse_ch3(char *s)
{
    int c;
    char *s2;

    for(s2 = s + (strlen(s) - 1); s < s2; s++, s2--)
    {
        c = *s;
        *s = *s2;
        *s2 = c;
    }
}
