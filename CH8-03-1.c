#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

/* _flushbuf: allocate or write and then empty input buffer */
int _flushbuf(int x, FILE *fp)
{
    int bufsize;
    int num; // number of characters to write

    if(fp >= _iob + OPEN_MAX || fp < _iob) // wrong pointer
        return EOF;
    if((fp->flag & (_WRITE | _EOF | _ERR)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if(fp->base == NULL)    /* no buffer yet */
    {
        if((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;     /* can't get buffer */
    }
    else // buffer was created
    {
        num = fp->ptr - fp->base;
        if(write(fp->fd, fp->base, num) != num)
        {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    fp->ptr = fp->base; // return to the beginning of buffer
    fp->cnt = bufsize - 1; // set the counter
    return *fp->ptr++ = x; // write the given character at the beginning of buffer
}
