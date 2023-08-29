/* strcat_: concatenate t to end of s; s must be big enough; pointer version */
void strcat_(char *s, char *t)
{
    while(*s++) /* find end of s */
        ;
    s--; // go back to the first character '/0'
    while(*s++ = *t++) /* copy t */
        ;
}
