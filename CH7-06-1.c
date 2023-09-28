#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

char *fgets_(char *, int, FILE *);

/* compare: compare two files, printing the first line where they differ */
int main(int argc, char *argv[])
{
    FILE *fp[2];
    char line1[MAXLINE], line2[MAXLINE], *p1, *p2;
    int i = 0;

    if(argc != 3) // wrong number of arguments
    {
        fprintf(stderr, "compare: wrong number of arguments");
        exit(1);
    }
    else
        while(--argc > 0)
            if((fp[i++] = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "compare: can't open %s\n", *argv);
                exit(1);
            }
    do
    {
        p1 = fgets_(line1, MAXLINE, fp[0]);
        p2 = fgets_(line2, MAXLINE, fp[1]);
    }
    while(strcmp(line1, line2) == 0 && p1 != NULL && p2 != NULL);
    if(strcmp(line1, line2) != 0) // were the last lines the same?
    {
        printf("%s\n", line1);
        printf("%s\n", line2);
    }
    fclose(fp[0]);
    fclose(fp[1]);

    exit(0);
}
