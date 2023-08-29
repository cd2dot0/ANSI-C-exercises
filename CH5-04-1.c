/* strend: check if t occurs at the end of s */
int strend(char *s, char *t)
{
    char *t0, *s0;

    // remember initial adresses
    t0 = t;
    s0 = s;

    while(*s) // seek end of s
        s++;
    while(*t) // seek end of t
        t++;
    while(s != s0 - 1 && t != t0 - 1 && *s == *t)
    {
        s--;
        t--;
    }
    if(t + 1 == t0)
        return 1;
    else
        return 0;
}
