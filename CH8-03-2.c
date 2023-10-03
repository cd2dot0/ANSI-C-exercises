#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

/* fflush: write the data stored in the output buffer */
int fflush(FILE *fp)
{
    if(fp == NULL) // flush all output streams
    {
        for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
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
    }
    else
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
    return 0;
}
