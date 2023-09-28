#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 120 // maximum number characters per line
#define HEXLENGTH 5 // length of hexadecimal value

/* print arbitrary input in a sensible way */
/* 1) break long text lines */
/* 2) print non-graphic characters in hexadecimal (for the 7-bit ASCII character set) */
main()
{
    int c, i = 0;

    while((c = getchar()) != EOF)
    {
        if(c >= 33 && c <= 126) // graphic character (without space)
        {
            if(i + 1 < MAXLENGTH)
            {
                putchar(c);
                i++;
            }
            else
            {
                putchar('\n');
                putchar(c);
                i = 1;
            }
        }
        else // non-graphic character
        {
            if(i + HEXLENGTH < MAXLENGTH)
            {
                printf(" \\%02X ", c);
                i = i + HEXLENGTH;
            }
            else
            {
                putchar('\n');
                printf(" \\%02X ", c);
                i = HEXLENGTH;
            }
            if(c == '\n') // newline character
            {
                putchar('\n');
                i = 0;
            }
        }
    }
    return 0;
}
