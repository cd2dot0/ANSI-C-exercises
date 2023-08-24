#include <ctype.h>

/* expand: expand shorthand notations in s1 into the equivalent complete list in s2 */
void expand(char s1[], char s2[])
{
    int i, j, d, u, l;
    char c;

    for(i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if(i != 0 && s1[i] == '-' && s1[i - 1] <= s1[i + 1]) // check if it is a shorthand notation
        {
            d = isdigit(s1[i - 1]) && isdigit(s1[i + 1]);
            u = isupper(s1[i - 1]) && isupper(s1[i + 1]);
            l = islower(s1[i - 1]) && islower(s1[i + 1]);
            if(d || u || l)
            {
                for(c = s1[i - 1] + 1; c <= s1[i + 1]; c++) // expand the shorthand notation
                    s2[j++] = c;
                i++;
            }
            else // copy character
            {
                s2[j] = s1[i];
                j++;
            }
        }
        else // copy character
        {
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = '\0';
}
