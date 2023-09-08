#include <stdio.h>
#include <string.h>

enum { NAME, PARENS, BRACKETS };

int gettoken(void);

extern int tokentype;      /* type of last token */
extern char token[];       /* last token string */
extern char datatype[];    /* data type = char, int, etc. */
extern int repeat_token;

/* check_type: check if the entered data type with qualifiers is correct */
void check_type(void)
{
    int sign = -1;   // -1 no qualifier, 0 unsigned, 1 signed
    int length = -1; // -1 no qualifier, 0 short, 1 long
    int cons = -1;   // -1 no qualifier, 1 const
    int dtype = -1;  // -1 no data type, 0 void, 1 char, 2 int, 3 float, 4 double
    int e = 0;       // 0 no error
    int i = 0;

    do
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
            strcpy(datatype, token);
        else
        {
            strcat(datatype, " ");
            strcat(datatype, token);
        }
        i++;
    }
    while(gettoken() == NAME);
    repeat_token = 1; // repeat the token that ended the do-while loop

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
    else // double
    {
        if(sign != -1 || length == 0)
            e = 1;
    }
    if(e == 1)
        printf("error: wrong data type and/or wrong qualifiers were specified\n");
}
