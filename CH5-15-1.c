#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
           int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int strcmp_(char *, char *);
int strcmp_no_size(char *, char *);

/* sort input lines numerically or lexicographically */
/* 1) handle sorting in increasing or decreasing order */
/* 2) handle folding upper and lower case together */
main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1, if numeric sort */
    int reverse = 0; // 1, if sort in decreasing order
    int no_size = 0; // 1, if case letters does not matter
    int c;

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c)
            {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                no_size = 1;
                break;
            default:
                printf("illegal option %c\n", c);
                argc = 1;
                break;
            }
    if(argc)
    {
        printf("Usage: sort -nrf \n");
        return 1;
    }
    else
        if((nlines = readlines(lineptr, MAXLINES)) >= 0)
        {
            if(no_size)
                qsort_((void**) lineptr, 0, nlines - 1,
                       (int (*)(void*, void*))(numeric ? numcmp : strcmp_no_size), reverse);
            else
                qsort_((void**) lineptr, 0, nlines - 1,
                       (int (*)(void*, void*))(numeric ? numcmp : strcmp_), reverse);
            writelines(lineptr, nlines);
            return 0;
        }
        else
        {
            printf("input too big to sort\n");
            return 1;
        }
}

/* qsort_: sort v[left]...v[right] into increasing or decreasing order */
void qsort_(void *v[], int left, int right,
           int (*comp)(void *, void *), int reverse)
{
    int i, last;
    void swap(void *v[], int, int);

    if(left >= right)   /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(reverse ? (*comp)(v[i], v[left]) > 0 : (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_(v, left, last - 1, comp, reverse);
    qsort_(v, last + 1, right, comp, reverse);
}


#include <ctype.h>

/* strcmp_no_size: return negative, zero, or positive for s < t, s == t, s > t; not case-sensitive */
int strcmp_no_size(char *s, char *t)
{
    char s1, t1;

    s1 = *s;
    t1 = *t;
    if(isupper(s1))
        s1 += 32;
    if(isupper(t1))
        t1 += 32;
    while(s1 == t1)
    {
        if(s1 == '\0')
            return 0;
        s1 = *++s;
        t1 = *++t;
        if(isupper(s1))
            s1 += 32;
        if(isupper(t1))
            t1 += 32;
    }
    return s1 - t1;
}
