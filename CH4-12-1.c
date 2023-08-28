/* itoa_rec: convert n to characters in s with recursion */
void itoa_rec(int n, char s[])
{
    int sign;
    static int i = 0;

    if((sign = n) < 0)  /* record sign */
        n = -n;         /* make n positive */
    if (sign < 0)
        s[i++] = '-';
    if(n / 10 > 0) // generate digits in normal order
         itoa_rec(n / 10, s);
    s[i++] = n % 10 + '0'; /* get next digit */
    s[i] = '\0';
}
