#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 100 /* max lines to be printed */
#define LASTLINES 10 /* standard number of lines to be printed */

int readlines(char *lineptr[], int n);
void write_n_lines(char *lineptr[], int nlines, int n);

/* tail: print the last n lines of input */
main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int n; // number of last lines which should be printed

    if(argc == 2 && (*++argv)[0] == '-')
        n = atoi(++(*argv)); // user-defined value
    else
        n = LASTLINES; // default value

    if(n <= 0) // handle a non-positive value
        n = 1;
    else if(n > MAXLINES) // handle a value above MAXLINES
        n = MAXLINES;

    char *lineptr[n]; // pointers to the last n lines

    nlines = readlines(lineptr, n);
    write_n_lines(lineptr, nlines, n);

    return 0;
}

#define MAXLEN 100 /* max length of any input line */
#define ALLOCSIZE MAXLINES*MAXLEN /* the size of required memory space */

static char allocbuf[ALLOCSIZE]; /* reserved memory */
static char *allocp = allocbuf; /* next free position */

int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int n)
{
    int len, nlines, i;
    char *p, line[MAXLEN];

    nlines = 0;
    i = 0;
    while((len = getline(line, MAXLEN)) > 0)
    {
        nlines++; // consecutive line was read
        if(allocbuf + ALLOCSIZE - allocp >= len) /* it fits */
            allocp += len;
        else // not enough room - start from the beginning of the buffer
            allocp = allocbuf + len;
        p = allocp - len; /* old p */

        line[len - 1] = '\0'; /* delete newline */
        strcpy(p, line); // copy the line to the buffer
        lineptr[i++] = p; // save the line address (adress to part of the buffer)

        if(i == n) // there are n pointers in array
            i = 0; // save the next pointer in the 0th element of array
    }
    return nlines;
}

/* write_n_lines: write the last n output lines */
void write_n_lines(char *lineptr[], int nlines, int n)
{
    int i;

    if(n < nlines) // the lines were more than n
        for(i = 0; i < n ; nlines++, i++)
            printf("%s\n", lineptr[nlines%n]);
    else
        for(i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}
