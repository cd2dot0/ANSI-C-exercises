/* strncmp_: return negative, zero, or positive for s < t, s == t, s > t; compare only the first n characters */
int strncmp_(char *s, char *t, int n)
{
    int i;

    for(i = 0; i < n && *s == *t; s++, t++, i++)
        if(*s == '\0')
            return 0;
    if(i == n)
        return 0;
    else
        return *s - *t;
}
