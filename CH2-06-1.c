/* setbits: return x with the n bits that begin at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned i, mask, r_bits, z;
    unsigned getbits(unsigned x, int p, int n);

    i = p + 1 - n; // number of the rightmost bits of x that will not be changed

    mask = 1;
    while(i > 0)
    {
        mask = mask * 2;
        i--;
    }
    mask = mask - 1;

    r_bits = x & mask; // save the rightmost bits of x

    z = getbits(y, n - 1, n); // get the rightmost n bits of y
    x = x >> (p + 1); // keep only those bits that are to the left of the exchanged ones
    x = x << n; // add right-hand side n zeros for new bits
    x = x | z; // insert new bits from y
    x = x << (p + 1 - n); // add right-hand side zeros for saved right bits
    x = x | r_bits; // insert saved right bits

    return x;
}
