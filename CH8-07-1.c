#include <stdio.h>

#define MAXB (unsigned) 10240 // maximum number of bytes

void *malloc2_(unsigned);
void free2_(void *);

/* this program uses improved functions to manage memory */
int main()
{

    void *p;

    p = malloc2_(18);
    free2_(p);

    return 0;
}

typedef long double Align; // for alignment to long double boundary
union header /* block header */
{
    struct
    {
        union header *ptr; /* next block if on free list */
        unsigned size; /* size of this block */
    } s;
    Align x; /* force alignment of blocks */
};
typedef union header Header; // Header type is union header

static unsigned maxunits = 0;   // the largest number of units allocated by the system
static Header base;             /* empty list to get started */
static Header *freep = NULL;    /* start of free list */

#define NALLOC 1024 /* minimum units to request */

/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
    char *cp, *sbrk(int);
    Header *up;

    if(nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if(cp == (char *) -1) /* no space at all */
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    if(nu > maxunits)
        maxunits = nu; // update maxunits
    free2_((void *)(up + 1));
    return freep;
}

/* free2_: put block ap in free list */
/* check size of block ap to avoid errors */
void free2_(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1; /* point to block header */
    if(bp->s.size < 2 || bp->s.size > maxunits) // wrong block size
    {
        fprintf(stderr, "free2_: can't free %u units\n", bp->s.size);
        return;
    }
    for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break; /* freed block at start or end of arena */
    if(bp + bp->s.size == p->s.ptr) /* join to upper nbr */
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
        bp->s.ptr = p->s.ptr;
    if(p + p->s.size == bp)         /* join to lower nbr */
    {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
        p->s.ptr = bp;
    freep = p;
}

/* malloc2_: general-purpose storage allocator */
/* check value of input argument to avoid errors */
void *malloc2_(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    if(nbytes < 1)
    {
        fprintf(stderr, "malloc2_: can't allocate 0 bytes\n");
        return NULL;
    }
    else if (nbytes > MAXB)
    {
        fprintf(stderr, "malloc2_: can't allocate more than %u bytes\n", MAXB);
        return NULL;
    }

    // 1. If there is the rest, we must round up,
    // so we use the component "+ sizeof(Header) - 1" to provide this
    // 2. "+1" at the end, because we must additionally store the header
    nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    if((prevp = freep) == NULL) /* no free list yet */
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
    {
        if(p->s.size >= nunits) /* big enough */
        {
            if(p->s.size == nunits) /* exactly */
                prevp->s.ptr = p->s.ptr;
            else                    /* allocate tail end */
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if(p == freep) /* wrapped around free list */
            if((p = morecore(nunits)) == NULL)
                return NULL; /* none left */
    }
}
