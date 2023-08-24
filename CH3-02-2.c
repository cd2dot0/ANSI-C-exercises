/* reescape: convert proper two characters into the escape sequence */
void reescape(char r[], char s[])
{
    int i, j, k, is_esc_seq;

    j = 0;
    for(i = 0; s[i] != '\0'; i++)
    {
        // count characters '\' to check whether it can be an escape sequence
        is_esc_seq = 0;
        for(k = 1; i - k >= 0 && s[i - k] == '\\'; k++)
                is_esc_seq = !is_esc_seq;

        if(is_esc_seq == 1)
        {
            switch(s[i])
            {
                case 'a':
                    r[--j] = '\a';
                    j++;
                    break;
                case 'b':
                    r[--j] = '\b';
                    j++;
                    break;
                case 'f':
                    r[--j] = '\f';
                    j++;
                    break;
                case 'n':
                    r[--j] = '\n';
                    j++;
                    break;
                case 'r':
                    r[--j] = '\r';
                    j++;
                    break;
                case 't':
                    r[--j] = '\t';
                    j++;
                    break;
                case 'v':
                    r[--j] = '\v';
                    j++;
                    break;
                case '\\':
                    r[--j] = '\\';
                    j++;
                    break;
                case '?':
                    r[--j] = '\?';
                    j++;
                    break;
                case '\'':
                    r[--j] = '\'';
                    j++;
                    break;
                case '"':
                    r[--j] = '\"';
                    j++;
                    break;
                default:
                    r[j++] = s[i];
                    break;
            }
        }
        else
        {
            r[j++] = s[i];
        }
    }
    r[j] = '\0';
}
