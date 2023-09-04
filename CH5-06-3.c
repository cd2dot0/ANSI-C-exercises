void reverse(char s[]);

/* itoa_ch3: convert n to characters in s; function from Chapter 3, pointer version */
void itoa_ch3(int n, char *s)
{
    int sign;
    char *s0;

    s0 = s; // remember initial address
    if((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    do /* generate digits in reverse order */
    {
        *s++ = n % 10 + '0'; /* get next digit */
    }
    while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(s0);
}
