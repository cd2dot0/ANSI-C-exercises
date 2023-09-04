/* strindex_ch4: return index of t in s, -1 if none; function from Chapter 4, pointer version */
int strindex_ch4(char *s, char *t)
{
    char *s2, *s0, *t0;

    s0 = s; // save initial addresses of arrays s and t
    t0 = t;
    for( ; *s != '\0'; s++)
    {
        for(s2 = s, t = t0; *t != '\0' && *s2 == *t; s2++, t++)
            ;
        if(t > t0 && *t == '\0')
            return s - s0;
    }
    return -1;
}
