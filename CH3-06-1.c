/* itoa_3arg: convert n to characters in s with a minimum field width p */
void itoa_3arg(int n, char s[], unsigned int p)
{
    int i, sign, k;
    unsigned un;
    void reverse(char s[]);

    if((sign = n) < 0) /* record sign */
        un = 1 + (unsigned) ~n; // conversion to take account of two's complement
    else
        un = (unsigned) n;

    i = 0;
    k = 0; // the counter of used fields
    do /* generate digits in reverse order */
    {
        s[i++] = un % 10 + '0'; /* get next digit */
        k++;
    }
    while ((un /= 10) > 0); /* delete it */
    if (sign < 0)
    {
        s[i++] = '-';
        k++;
    }
    for(; k < p; k++) // add spaces to provide p
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
