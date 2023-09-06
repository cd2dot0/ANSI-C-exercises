#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
           int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int strcmp_fd(char *, char *);

// static variables - not visible outside the source file
static int no_size = 0; // 1, if case letters does not matter
static int dir_order = 0; // 1, if "directory order"

/* sort input lines numerically or lexicographically */
/* 1) handle sorting in increasing or decreasing order */
/* 2) handle folding upper and lower case together */
/* 3) handle sorting in "directory order" (comparisons only on letters, numbers and blanks) */
main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1, if numeric sort */
    int reverse = 0; // 1, if sort in decreasing order
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
            case 'd':
                dir_order = 1;
                break;
            default:
                printf("illegal option %c\n", c);
                argc = 1;
                break;
            }
    if(argc)
    {
        printf("Usage: sort -nrfd \n");
        return 1;
    }
    else
        if((nlines = readlines(lineptr, MAXLINES)) >= 0)
        {
            qsort_((void**) lineptr, 0, nlines - 1,
                   (int (*)(void*, void*))(numeric ? numcmp : strcmp_fd), reverse);
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

/* strcmp_fd: return negative, zero, or positive for s < t, s == t, s > t */
/* 1) have a case-insensitive option */
/* 2) have a "directory order" option */
int strcmp_fd(char *s, char *t)
{
    char s1, t1;

    do
    {
        if(dir_order) // skip if there are no letters, numbers, blanks
        {
            while(!isalpha(*s) && !isdigit(*s) && *s != ' ' && *s != '\0')
                s++;
            while(!isalpha(*t) && !isdigit(*t) && *t != ' ' && *t != '\0')
                t++;
        }
        s1 = *s++;
        t1 = *t++;
        if(no_size) // convert uppercase letters to lowercase
        {
            if(isupper(s1))
                s1 += 32;
            if(isupper(t1))
                t1 += 32;
        }
        if(s1 == '\0' && t1 == '\0')
            return 0;
    }
    while(s1 == t1);

    return s1 - t1;
}
