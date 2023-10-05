void *malloc_(unsigned);

/* calloc_: return a pointer to n objects of size "size", */
/* with the storage initialized to zero */
void *calloc_(unsigned n, unsigned size)
{
    // char type has size of one byte, so in the expression "p++"
    // the value of the pointer p really increase by 1 (no scaling),
    // and in that we can access each byte of allocated memory
    char *p;
    unsigned i;

    if((p = (char *) malloc_(n*size)) != NULL)
        for(i = 0; i < n*size; i++) // assign 0 to each byte of allocated memory
            *(p + i) = 0;

    return (void *) p;
}
