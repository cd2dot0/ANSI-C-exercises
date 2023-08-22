/* lower: convert c to lower case with a conditional expression; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
