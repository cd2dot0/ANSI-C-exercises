#define MAXLINE 1000 /* maximum number of array elements */

/* escape: convert each escape sequence into two visible characters */
void escape(char s[], char t[])
{
    int i, j;

    j = 0;
    for(i = 0; t[i] != '\0' && j < MAXLINE - 1; i++)
    {
        switch(t[i])
        {
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            case '\?':
                s[j++] = '\\';
                s[j++] = '?';
                break;
            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
                break;
            case '\"':
                s[j++] = '\\';
                s[j++] = '"';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    // if there is an escape sequnce that exceeds the limit - do not print it
    if(j == MAXLINE)
        j = j - 2;

    s[j] = '\0';
}
