#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
           int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int strcmp_fd(char *, char *);
void extract_field(char *s, char *s_new, int p, int w);

// static variables - not visible outside the source file
static int no_size = 0; // 1, if case letters does not matter
static int dir_order = 0; // 1, if "directory order"
static int pos = 0; // position from which the field starts
static int wid = MAXLEN; // field width (number of positions inside the field)

/* sort input lines numerically or lexicographically */
/* 1) handle sorting in increasing or decreasing order */
/* 2) handle folding upper and lower case together */
/* 3) handle sorting in "directory order" (comparisons only on letters, numbers and blanks) */
/* 4) handle fields */
main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1, if numeric sort */
    int reverse = 0; // 1, if sort in decreasing order
    int c;

    while(--argc > 0 && (*++argv)[0] == '-')
    {
        if(argv[0][1] == 'p') // field
            if(isdigit(argv[0][2]))
            {
                pos = atoi(argv[0] + 2);
                if(pos >= MAXLEN)
                    pos = MAXLEN - 1;
            }
            else
            {
                printf("after -p, an unsigned number was expected");
                argc = 1;
            }
        else if(argv[0][1] == 'w') // field width
            if(isdigit(argv[0][2]))
            {
                wid = atoi(argv[0] + 2);
                if(wid > MAXLEN)
                    wid = MAXLEN;
            }
            else
            {
                printf("after -w, an unsigned number was expected");
                argc = 1;
            }
        else // remaining options
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
                    printf("find: illegal option %c\n", c);
                    argc = 1;
                    break;
                }
    }
    if(argc)
    {
        printf("Usage: sort -nrfd -p# -w# where # is unsigned number \n");
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

/* strcmp_fd: return negative, zero, or positive for s < t, s == t, s > t */
/* 1) have a case-insensitive option */
/* 2) have a "directory order" option */
/* 3) handle fields in lines */
int strcmp_fd(char *s, char *t)
{
    char s1, t1;
    char s_new[MAXLEN], t_new[MAXLEN];
    char *p_s, *p_t;

    // initialise pointers to new arrays
    p_s = s_new;
    p_t = t_new;

    // extract fields in compared lines
    extract_field(s, p_s, pos, wid);
    extract_field(t, p_t, pos, wid);

    do
    {
        if(dir_order) // skip if there are no letters, numbers, blanks
        {
            while(!isalpha(*p_s) && !isdigit(*p_s) && *p_s != ' ' && *p_s != '\0')
                p_s++;
            while(!isalpha(*p_t) && !isdigit(*p_t) && *p_t != ' ' && *p_t != '\0')
                p_t++;
        }
        s1 = *p_s++;
        t1 = *p_t++;
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

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    char s1_new[MAXLEN], s2_new[MAXLEN];

    // extract fields in compared lines
    extract_field(s1, s1_new, pos, wid);
    extract_field(s2, s2_new, pos, wid);

    v1 = atof(s1_new);
    v2 = atof(s2_new);
    if(v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* extract_field: copy elements within field from s to s_new  */
void extract_field(char *s, char *s_new, int p, int w)
{
    for(s = s + p; (w--) && (*s_new++ = *s++); )
        ;
    if(w < 0)
        *s_new = '\0';
}
