#include <stdio.h>
#include <fcntl.h>
#include "unistd.h"

/* cat: concatenate files, version 3 */
/* using the system functions (read, write, open, close) */
int main(int argc, char *argv[])
{
    int fd;
    void cpy(int, int);
    char *prog = argv[0]; /* program name for errors */

    if(argc == 1) /* no args; copy standard input */
        cpy(0, 1);
    else
        while(--argc > 0)
            if((fd = open(*++argv, O_RDONLY, 0)) == -1)
            {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else
            {
                cpy(fd, 1);
                close(fd);
            }
    exit(0);
}

/* cpy: copy f1 to f2 */
void cpy(int f1, int f2)
{
    int n;
    char buf[BUFSIZ];

    while((n = read(f1, buf, BUFSIZ)) > 0)
        if(write(f2, buf, n) != n)
        {
            fprintf(stderr, "cpy: write error on file");
            exit(2);
        }
}
