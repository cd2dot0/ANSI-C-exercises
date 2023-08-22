/* any: return the first location in a string s1 where any character from the string s2 occurs */
/* or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[])
{
    int i, j, k, is_new, pos;

    for(i = 0; s2[i] != '\0'; i++) // seek the end of s2, to determine array size
        ;
    i++;

    char all_c[i]; // the array to store only one character of each type from the string s2
    for(i = j = 0; s2[i] != '\0'; i++)
    {
        k = j;
        while(k > 0 && s2[i] != all_c[k - 1]) // the current character from s2 is compared with consecutive characters from all_c
            k--;
        if(k == 0)
            is_new = 1;
        else
           is_new = 0;

        if(is_new == 1)
            all_c[j++] = s2[i];
    }
    all_c[j] = '\0';

    pos = -1;
    for(i = 0; (s1[i] != '\0') && (pos == -1); i++)
    {
        k = j;
        while(k > 0 && s1[i] != all_c[k - 1]) // the current character from s1 is compared with consecutive characters from all_c
            k--;
        if(k != 0) // there is a character from s2 at position i in s1
            pos = i;
    }

    return pos;
}
