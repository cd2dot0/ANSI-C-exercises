#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

#define MAXLEN 30

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval, c;
    char text[MAXLEN]; // table for conversion specification
    int *p_ival, j;
    double *p_dval;
    unsigned int *p_uval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for(p = fmt; *p; p++)
    {
        if(isspace(*p)) // skip white characters of format string
            continue;
        if(*p != '%') // ordinary characters
        {
            for(c = getchar(); c == ' ' || c == '\t'; c = getchar()) // skip input spaces and tabs
                ;
            if(*p == c) // input and format characters are compatible
                continue;
            else
                return;
        }
        text[0] = '%'; // characters of the conversion specification
        for(p++, j = 1; *p && (!isalpha(*p) || *p == 'l' || *p == 'h' || *p == 'L'); p++, j++)
            text[j] = *p;
        text[j] = *p;
        text[j + 1] = '\0';
        switch(*p)
        {
        case 'd': case 'i': case 'o': case 'x':
            p_ival = va_arg(ap, int *);
            scanf(text, p_ival);
            break;
        case 'e': case 'f': case 'g':
            p_dval = va_arg(ap, double *);
            scanf(text, p_dval);
            break;
        case 'u':
            p_uval = va_arg(ap, unsigned *);
            scanf(text, p_uval);
            break;
        case 'c': case 's':
            sval = va_arg(ap, char *);
            scanf(text, sval);
            break;
        default:
            scanf(text);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}
