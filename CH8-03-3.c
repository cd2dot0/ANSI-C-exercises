#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

/* fclose: free the allocated buffer, close the file */
int fclose(FILE * fp)
{
    if((fp->flag & _WRITE) != 0) // file has write mode
    {
        if(_flushbuf(0, fp) != EOF)
        {
            fp->ptr = fp->base; // return to the beginning of buffer
            fp->cnt++; // correct the counter
        }
        else
            return EOF;
    }
    free((void *) fp->base); // free the memory of buffer
    fp->base = fp->ptr = NULL;
    close(fp->fd); // return the file descriptor
    fp->fd = fp->cnt = fp->flag = 0;
    return 0;
}
