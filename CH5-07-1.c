#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define BUFSIZE 10000 /* size of available memory area */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char buf[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
    int nlines; /* number of input lines read */
    char buf[BUFSIZE]; // memory

    if((nlines = readlines(lineptr, MAXLINES, buf)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);

/* readlines: read input lines, do not call alloc */
int readlines(char *lineptr[], int maxlines, char buf[])
{
    int len, nlines;
    char *p, line[MAXLEN];
    char *pos = buf; // next free position

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
    {
        if(buf + BUFSIZE - pos >= len) // it fits
        {
            pos += len;
            p = pos - len; // old pos
        }
        else // not enough room
            p = 0;

        if(nlines >=  maxlines || p == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line); // copy newline to buffer
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
