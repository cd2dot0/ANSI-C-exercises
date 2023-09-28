#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

#define MAXLEN 30

/* minprintf: extension of minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    char text[MAXLEN]; // table for conversion specification
    int ival, j;
    double dval;
    unsigned int uval;
    void * vval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for(p = fmt; *p; p++)
    {
        if(*p != '%')
        {
            putchar(*p);
            continue;
        }
        text[0] = '%';
        for(p++, j = 1; *p && (!isalpha(*p) || *p == 'l' || *p == 'h'); p++, j++)
            text[j] = *p;
        text[j] = *p;
        text[j + 1] = '\0';
        switch(*p)
        {
        case 'c': case 'd': case 'i':
            ival = va_arg(ap, int);
            printf(text, ival);
            break;
        case 'e': case 'E': case 'f': case 'g': case 'G':
            dval = va_arg(ap, double);
            printf(text, dval);
            break;
        case 'o': case 'u': case 'x': case 'X':
            uval = va_arg(ap, unsigned);
            printf(text, uval);
            break;
        case 'p':
            vval = va_arg(ap, void *);
            printf(text, vval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            printf(text, sval);
            break;
        default:
            printf(text);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}
