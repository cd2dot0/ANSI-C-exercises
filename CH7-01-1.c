#include <stdio.h>
#include <ctype.h>

/* convert upper case to lower or lower case to upper depending on the program name */
int main(int argc, char *argv[])
{
    int c;

    if(islower(*argv[0]))
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    else
        while((c = getchar()) != EOF)
            putchar(toupper(c));
    return 0;
}
