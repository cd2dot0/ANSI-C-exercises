/* squeeze: delete each character in string s1 that matches any character in the string s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k, m, is_new;

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

    for(i = m = 0; s1[i] != '\0'; i++)
    {
        k = j;
        while(k > 0 && s1[i] != all_c[k - 1]) // the current character from s1 is compared with consecutive characters from all_c
            k--;
        if(k == 0) // the current character from s1 is not any of the forbidden characters
            s1[m++] = s1[i];
    }
    s1[m] = '\0';
}
