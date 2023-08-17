#include <stdio.h>
#include <string.h>
#define MAXCHAR 5000 /* maximum number of characters in the code */

int check_state(int i, int k_start, char code[], int states[]);
void count_brackets(char ch, char ch_next, int num_line, int brackets[]);

/* check a C program for rudimentary errors (only unmatched round, square and curly brackets) */
main()
{
    int i, c, num_line, k_start;
    char code[MAXCHAR]; // array to store program code
    int states[4]; // consecutively: q, a, type1, type2
    int brackets[6]; // consecutively: b_round, b_square, b_curly, round_1st, square_1st, curly_1st

    // store the program code in array
    for(i = 0;(c = getchar()) != EOF && i < MAXCHAR - 1; ++i)
        code[i] = c;
    code[i] = '\0';
    // prepare the data for the second loop
    num_line = 1;
    k_start = -1;
    for(i = 0; i < 4; ++i)
        states[i] = 0;
    for(i = 0; i < 6; ++i)
    {
        if(i < 3)
            brackets[i] = 0;
        else
            brackets[i] = -1;
    }
    i = 0;
    while(code[i] != '\0')
    {
        // check whether the character is in single quotes, double quotes or comment
        k_start = check_state(i, k_start, code, states);
        if(states[0] == 0 && states[1] == 0 && states[2] == 0 && states[3] == 0)
        {
            // detect errors with brackets
            count_brackets(code[i], code[i + 1], num_line, brackets);
        }
        if(code[i] == '\n')
        {
            ++num_line; // update line number
        }
        ++i; // update array index number
    }

    return 0;
}

/* check_state: check whether the character is in single quotes, double quotes or comment */
int check_state(int i, int k_start, char code[], int states[])
{
    int j, q, a, type1, type2, change, k_end;

    q = states[0]; // "unpacking" the data from the array
    a = states[1];
    type1 = states[2];
    type2 = states[3];

    k_end = - 1;
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
    if(i > 0 && code[i - 1] == '/' && type1 == 0 && type2 == 0 && q == 0 && a == 0)
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
    if(type1 == 1 && code[i - 1] == '*' && code[i] == '/' && k_start != i - 2)
    {
        type1 = 0; // end a comment of type one
        k_end = i;
    }
    if(type2 == 1 && code[i] == '\n')
    {
        type2 = 0; // end a comment of type two
        k_end = i;
    }
    if(k_start != -1 && k_end != -1) // delete the comment
    {
        for(j = k_start; j <= k_end; ++j)
        {
            if(code[j] != '\n') // if no newline character - insert blank
                code[j] = ' ';
        }
        k_start = k_end = -1;
    }

    states[0] = q; // "packing" the data into the array
    states[1] = a;
    states[2] = type1;
    states[3] = type2;

    return k_start;
}

/* count_brackets: count brackets and print errors */
void count_brackets(char ch, char ch_next, int num_line, int brackets[])
{
    int b_round, b_square, b_curly; // the counters of 3 types of brackets (round, square, curly)
    int round_1st, square_1st, curly_1st; // the line numbers of the first left bracket of a given type

    b_round = brackets[0]; // "unpacking" the data from the array
    b_square = brackets[1];
    b_curly = brackets[2];
    round_1st = brackets[3];
    square_1st = brackets[4];
    curly_1st = brackets[5];

    if(ch == '(')
    {
        ++b_round;
        if(b_round == 1)
            round_1st = num_line; // save the line number of the first left round bracket
    }
    else if(ch == ')')
    {
        --b_round;
        if(b_round == 0)
            round_1st = -1; // "clear" the line number of the first left round bracket
        else if(b_round < 0)
        {
            printf("Line %d: expected '(' before ')'.\n", num_line);
            b_round = 0;
        }
    }
    else if(ch == '[')
    {
        ++b_square;
        if(b_square == 1)
            square_1st = num_line;
    }
    else if(ch == ']')
    {
        --b_square;
        if(b_square == 0)
            square_1st = -1;
        else if(b_square < 0)
        {
            printf("Line %d: expected '[' before ']'.\n", num_line);
            b_square = 0;
        }
    }
    else if(ch == '{')
    {
        ++b_curly;
        if(b_curly == 1)
            curly_1st = num_line;
    }
    else if(ch == '}')
    {
        --b_curly;
        if(b_curly == 0)
            curly_1st = -1;
        else if(b_curly < 0)
        {
            printf("Line %d: expected '{' before '}'.\n", num_line);
            b_curly = 0;
        }
    }
    if(ch_next == '\0')
    {
        if(b_round > 0)
            printf("Line %d: expected ')' after '('.\n", round_1st);
        if(b_square > 0)
            printf("Line %d: expected ']' after '['.\n", square_1st);
        if(b_curly > 0)
            printf("Line %d: expected '}' after '{'.\n", curly_1st);
    }

    brackets[0] = b_round; // "packing" the data into the array
    brackets[1] = b_square;
    brackets[2] = b_curly;
    brackets[3] = round_1st;
    brackets[4] = square_1st;
    brackets[5] = curly_1st;
}
