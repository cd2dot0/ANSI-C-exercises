/* x &= (x-1) deletes the rightmost 1-bit in x in a two's complement number system */
/* checking */
/* assume that b is a single bit (0 or 1) */
/* 1) if x is an odd number:              */
/*    x:          bbb...bbb1              */
/*    (x-1):      bbb...bbb0              */
/*    x &= (x-1): bbb...bbb0              */
/*    the righmost 1-bit was deleted      */
/* 2) if x is an even number (not zero):  */
/*    x:          bbb...1000...           */
/*    (x-1):      bbb...0111...           */
/*    x &= (x-1): bbb...0000...           */
/*    the righmost 1-bit was deleted      */
/* 3) if x is zero:                       */
/*    x:          000...000               */
/*    (x-1):      111...111               */
/*    x &= (x-1): 000...000               */
/*    there are no 1-bites                */
/* conclusion */
/* the statement is true */

/* bitcount_faster: count 1 bits in x faster */
int bitcount_faster(unsigned x)
{
    int b;

    for(b = 0; x != 0; x &= (x - 1))
        b++;

    return b;
}
