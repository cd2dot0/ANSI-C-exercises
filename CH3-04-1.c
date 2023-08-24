/* Q: In a two's complement number representation,                             */
/* original version of itoa does not handle the largest negative number,       */
/* that is, the value of n equal to -(2 to power (wordsize - 1)). Why?         */
/* A: There is a certain line in original function itoa:                       */
/* n = -n; // make n positive                                                  */
/* Let's assume the wordsize is 8. The largest negative number equals          */
/* -128 and the largest positive number equals 127. If n is -128, then -n      */
/* should be 128. But in a two's complement number representation -n = ~n + 1. */
/* Bitwise representation of number -128:                                      */
/* 1000 0000                                                                   */
/* We use bitwise ~ operator and get:                                          */
/* 0111 1111                                                                   */
/* Then we add 1 and get:                                                      */
/* 1000 0000                                                                   */
/* So, we have -128 again. To deal with this problem, we can use a conversion  */
/* to unsigned number before we add 1.                                         */

/* itoa_v2: convert n to characters in s; handle the largest negative number */
void itoa_v2(int n, char s[])
{
    int i, sign;
    unsigned un;
    void reverse(char s[]);

    if((sign = n) < 0) /* record sign */
        un = 1 + (unsigned) ~n; // conversion to take account of two's complement
    else
        un = (unsigned) n;

    i = 0;
    do /* generate digits in reverse order */
    {
        s[i++] = un % 10 + '0'; /* get next digit */
    }
    while ((un /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
