/* strncpy_: copy at most n characters of t to s */
void strncpy_(char *s, char *t, int n)
{
    int i, t_end;

    t_end = 0;
    for(i = 0; i < n; i++)
    {
        if(*t == '\0' && t_end == 0) // the end of string t
            t_end = 1;
        if(t_end == 0)
            *s++ = *t++;
        else
            *s++ = '\0';
    }
    if(*(s - 1) != '\0') // if there is no null character, add one
        *s = '\0';
}
