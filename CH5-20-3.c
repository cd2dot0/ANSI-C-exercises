#include <stdio.h>
#include <string.h>

enum { NAME, PARENS, BRACKETS };

int gettoken(void);

extern int tokentype;      /* type of last token */
extern char token[];       /* last token string */
extern char arguments[];   // the inside of the function
extern int repeat_token;

/* check_args: recognise a list of function arguments and check its correctness */
int check_args(void)
{
    int sign;   // -1 no qualifier, 0 unsigned, 1 signed
    int length; // -1 no qualifier, 0 short, 1 long
    int cons;   // -1 no qualifier, 1 const
    int dtype;  // -1 no data type, 0 void, 1 char, 2 int, 3 float, 4 double
    int e;      // 0 no error
    int i = 0;  // total number of components of all arguments
    int j = 0;  // number of arguments
    char prev_tokentype; // type of previous token

    do // check consecutive argument
    {
        sign = length = cons = dtype = -1;
        e = 0;
        if(j > 0)
            strcat(arguments, ",");

        j++;
        do // check consecutive components of argument
        {
            if(strcmp("unsigned", token) == 0)
            {
                if(sign == -1) // qualifier of number sign is specified for the first time
                    sign = 0;
                else // error
                    e = 1;
            }
            else if(strcmp("signed", token) == 0)
            {
                if(sign == -1)
                    sign = 1;
                else
                    e = 1;
            }
            else if(strcmp("const", token) == 0)
            {
                if(cons == -1) // qualifier const is specified for the first time
                    cons = 1;
                else
                    e = 1;
            }
            else if(strcmp("short", token) == 0)
            {
                if(length == -1) // qualifier of number length is specified for the first time
                    length = 0;
                else
                    e = 1;
            }
            else if(strcmp("long", token) == 0)
            {
                if(length == -1)
                    length = 1;
                else
                    e = 1;
            }
            else if(strcmp("void", token) == 0)
            {
                if(dtype == -1) // data type is specified for the first time
                    dtype = 0;
                else
                    e = 1;
            }
            else if(strcmp("char", token) == 0)
            {
                if(dtype == -1)
                    dtype = 1;
                else
                    e = 1;
            }
            else if(strcmp("int", token) == 0)
            {
                if(dtype == -1)
                    dtype = 2;
                else
                    e = 1;
            }
            else if(strcmp("float", token) == 0)
            {
                if(dtype == -1)
                    dtype = 3;
                else
                    e = 1;
            }
            else if(strcmp("double", token) == 0)
            {
                if(dtype == -1)
                    dtype = 4;
                else
                    e = 1;
            }
            else
                break;

            if(i == 0)
                strcpy(arguments, token);
            else
            {
                strcat(arguments, " ");
                strcat(arguments, token);
            }
            i++;
        }
        while(gettoken() == NAME);

        if(i == 0) // no components of argument - it is not the inside of the function
            return i;

        // constraints for individual data types
        if(dtype == -1) // error - no data type was entered
            e = 1;
        else if(dtype == 0) // void
        {
            if(sign != -1 || length != -1)
                e = 1;
        }
        else if(dtype == 1) // char
        {
            if(length != -1)
                e = 1;
        }
        else if(dtype == 2) // int
            ;
        else if(dtype == 3) // float
        {
            if(sign != -1 || length != -1)
                e = 1;
        }
        else //double
        {
            if(sign != -1 || length == 0)
                e = 1;
        }
        if(e == 1)
            printf("error: wrong data type and/or wrong qualifiers were specified for %d. argument in function\n", j);
    }
    while((prev_tokentype = tokentype) == ',' && gettoken() == NAME); // the argument ended with comma - check next one

    if(prev_tokentype == ',')
    {
        printf("error: expected data type with qualifiers for %d. argument in function \n", j + 1);
        repeat_token = 1; // repeat the token that ended the outside do-while loop
        tokentype = PARENS;
    }
    else if(prev_tokentype == ')')
        tokentype = PARENS;
    else
    {
        printf("error: expected ',' or ')'\n");
        repeat_token = 1; // repeat the token that ended both do-while loops
        tokentype = PARENS;
    }

    return i;
}
