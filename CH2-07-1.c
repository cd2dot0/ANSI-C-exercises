/* invert: return x with n bits that begin at position p inverted (i.e. 1 changed into 0 and vice versa) */
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask, c1, c2;

    mask = ~(~0 << n) << (p + 1 - n); // 000000...111...0000000
                                      // [rest]...[n]...[p+1-n]
    c1 = ~(x & mask); // 111...~x~x~x...111
    c2 = x | mask; // xxx...111...xxx

    return c1 & c2; // xxx...~x~x~x...xxx
}

