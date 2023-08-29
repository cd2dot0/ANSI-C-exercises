/* strncat_: concatenate n characters of t to end of s */
void strncat_(char *s, char *t, int n)
{
    int i;

    while(*s) // seek end of s
        s++;
    for(i = 0; i < n && *t != '\0'; i++)
        *s++ = *t++;
    *s = '\0';
}
