#include <stdio.h>

void free_(void *);

/* bfree: free an arbitrary block p of n characters into free list maintained by malloc and free */
void bfree(void *p, unsigned n)
{
    Header *up;
    unsigned nunits;

    if(freep == NULL) /* no free list yet */
    {
        base.s.ptr = freep = &base;
        base.s.size = 0;
    }
    // take account of only this part of the block to store whole headers
    nunits = n / sizeof(Header);
    if(nunits < 2) // the block to be freed is too small (required minimum is 1 unit for header + 1 unit for data)
    {
        fprintf(stderr,"bfree: can't add this block into free list ");
        return;
    }
    up = (Header *) p;
    up->s.size = nunits;
    free_((void *)(up + 1));
}
