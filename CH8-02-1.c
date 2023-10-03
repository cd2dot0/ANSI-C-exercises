#include <fcntl.h>
#include "unistd.h"
#include <stdlib.h>

#define PERMS 0666 /* RW for owner, group, others */

#ifdef NULL
    #undef NULL
#endif

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 /* max files open at once */

typedef struct _iobuf
{
    int cnt;        /* characters left */
    char *ptr;      /* next character position */
    char *base;     /* location of buffer */
    struct
    {
        unsigned int is_read : 1;   /* file open for reading */
        unsigned int is_wrt : 1;    /* file open for writing */
        unsigned int is_unbuf : 1;  /* file is unbuffered */
        unsigned int is_eof : 1;    /* EOF has occurred on this file */
        unsigned int is_err : 1;    /* error occurred on this file */
    } flag;         /* mode of file access */
    int fd;         /* file decriptor */
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

FILE *fopen(char *, char *);
int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((p)->flag.is_eof == 1)
#define ferror(p) ((p)->flag.is_err == 1)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 \
                 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 \
                   ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE _iob[OPEN_MAX] = /* stdin, stdout, stderr */
{
    { 0, (char*) 0, (char*) 0, { .is_read = 1 }, 0},
    { 0, (char*) 0, (char*) 0, { .is_wrt = 1 }, 1},
    { 0, (char*) 0, (char*) 0, { .is_wrt = 1, .is_unbuf = 1 }, 2}
};

/* this version of program uses bit-fields instead of explicit bit operations */
int main()
{
    FILE *fp;
    char c[100];
    int i = 0;

    fp = fopen("text.txt","r");
    while((c[i++] = getc(fp)) != EOF)
        ;
    c[--i] = '\0';
    return 0;
}

/* fopen: open the named file in one of the three modes */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if(*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if(fp->flag.is_read == 0 && fp->flag.is_wrt == 0)
            break; /* found free slot */
    if(fp >= _iob + OPEN_MAX) /* no free slots */
        return NULL;
    if(*mode == 'w')
        fd = creat(name, PERMS);
    else if(*mode == 'a')
    {
        if((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    }
    else
        fd = open(name, O_RDONLY, 0);
    if(fd == -1) /* couldn't access name */
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    if(*mode == 'r')
    {
        fp->flag.is_read = 1;
        fp->flag.is_wrt = 0;
    }
    else
    {
        fp->flag.is_wrt = 1;
        fp->flag.is_read = 0;
    }
    fp->flag.is_unbuf = 0;
    fp->flag.is_eof = 0;
    fp->flag.is_err = 0;
    return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if(fp->flag.is_eof == 1 || fp->flag.is_err == 1 || fp->flag.is_read == 0)
        return EOF;
    bufsize = (fp->flag.is_unbuf == 1) ? 1 : BUFSIZ;
    if(fp->base == NULL)    /* no buffer yet */
        if((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;     /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if(--fp->cnt < 0)
    {
        if(fp->cnt == -1)
            fp->flag.is_eof = 1;
        else
            fp->flag.is_err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
