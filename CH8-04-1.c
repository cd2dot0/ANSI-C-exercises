#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

/* fseek: change the position in the file */
int fseek(FILE *fp, long offset, int origin)
{
    int num;
    int bufsize;

    if(fp >= _iob + OPEN_MAX || fp < _iob) // wrong pointer
        return EOF;
    if(origin >= 3 || origin < 0) // wrong value of origin
        return EOF;
    if((fp->flag & _READ) != 0) // a read file
    {
        if(origin == 1) // from the current position
            offset = offset - fp->cnt; // correct the offset - the true current position is where the buffer ended
        fp->cnt = 0; // the buffer will be refilled
        if(lseek(fp->fd, offset, origin) < 0) // lseek error
        {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    else if((fp->flag & _WRITE) != 0) // a write file
    {
        num = fp->ptr - fp->base;
        if(num > 0)
        {
            if(write(fp->fd, fp->base, num) != num)
            {
                fp->flag |= _ERR;
                return EOF;
            }
            fp->ptr = fp->base; // return to the beginning of buffer
            bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
            fp->cnt = bufsize; // set the counter
        }
        if(lseek(fp->fd, offset, origin) < 0) // lseek error
        {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    return 0;
}
