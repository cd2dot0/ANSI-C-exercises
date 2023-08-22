/* rightrot: return the value of the integer x rotated to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
    unsigned c, i, mask, c1, c2;

    i = 0;
    c = ~0;
    while(c != 0) // calculate the length of a machine word
    {
        c = c << 1;
        i++;
    }
    n = n % i; // decrease the shift value by a multiple of the machine word length

    mask = ~(~0 << n);          // 00000000111
                                // [i - n ][n]
    c1 = x & mask;              // 00000000xxR (R is the rightmost bit of original x)
    c1 = c1 << (i - n);         // xxR00000000

    c2 = ~(mask << (i - n));    // 00011111111
    c2 = (x >> n) & c2;         // 000Lxxxxxxx (L is the leftmost bit of original x)
    return c1 | c2;             // xxRLxxxxxxx
}
