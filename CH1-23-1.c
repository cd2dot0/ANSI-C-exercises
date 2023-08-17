#include <stdio.h>
#include <string.h>
#define MAXCHAR 5000 /* maximum number of characters in the code */

/* remove all comments from a C program */
main()
{
    char code[MAXCHAR];
    int i, j, c, k_start, k_end, type1, type2, q, a, change;

    type1 = type2 = a = q = 0;
    k_start = k_end = -1;
    for(i = 0;(c = getchar()) != EOF && i < MAXCHAR - 1; ++i)
    {
        code[i] = c;
        if(code[i] == '\"' && type1 == 0 && type2 == 0 && a == 0) // double quote 1/0 (start/end)
        {
            change = 1; // make a change when before (") an even number (also 0) of times appeared (\)
            for(j = i - 1; code[j] == '\\' && j >= 0; --j)
                change = !change;
            if(change == 1)
                q = !q;
        }
        if (code[i] == '\'' && type1 == 0 && type2 == 0 && q == 0) // single quote 1/0 (start/end)
        {
            change = 1; // make a change when before (') an even number (also 0) of times appeared (\)
            for(j = i - 1; code[j] == '\\' && j >= 0; --j)
                change = !change;
            if(change == 1)
                a = !a;
        }
        if(i > 0 && code[i-1] == '/' && type1 == 0 && type2 == 0 && q == 0 && a == 0)
        {
            if(code[i] == '*')
            {
                type1 = 1; // start a comment of type one
                k_start = i - 1;
            }

            else if(code[i] == '/')
            {
                type2 = 1; // start a comment of type two
                k_start = i - 1;
            }
        }
        if(type1 == 1 && code[i-1] == '*' && code[i] == '/' && k_start != i - 2)
        {
            type1 = 0; // end a comment of type one
            k_end = i;
        }
        if(type2 == 1 && code[i] == '\n')
        {
            type2 = 0; // end a comment of type two
            k_end = i;
        }
        if(k_start != -1 && k_end != -1)
        {
            for(j = k_start; j <= k_end; ++j)
            {
                if(code[j] != '\n') // if no newline character - insert blank
                    code[j] = ' ';
            }
            k_start = k_end = -1;
        }
    }
    printf("%s", code);

    return 0;
}
