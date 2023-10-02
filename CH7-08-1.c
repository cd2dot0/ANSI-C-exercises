#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000 // maximum number of characters per line
#define LINENUM 10 // number of lines per page

char *fgets_(char *, int, FILE *);

/* list: print a set of files, starting each new one on a new page, with a title and a running page count for each file */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int lineno;
    long pageno;
    FILE *fp;

    if(argc == 1) // there are no files names
    {
        fprintf(stderr, "Usage: list file1 file2 ...\n");
        exit(1);
    }
    else if(argc > 1) // there are files names
    {
        while(argc-- > 1)
        {
            if((fp = fopen(*++argv, "r")) == NULL) // open the file
            {
                fprintf(stderr, "list: can't open %s\n", *argv);
                exit(1);
            }
            else
            {
                lineno = 0;
                pageno = 1;
                printf("name: %s\n\n", *argv); // title of the file
                lineno += 2;
                while((fgets_(line, MAXLINE, fp)) != NULL) // print the consecutive lines of the file
                {
                    printf("%s", line);
                    lineno++;
                    if(lineno >= LINENUM - 1) // the end of the page
                    {
                        printf("----- %ld -----\n", pageno++);
                        lineno = 0;
                    }
                }
                while(lineno != 0) // the last page of the file
                {
                    printf("\n");
                    lineno++;
                    if(lineno >= LINENUM - 1) // the end of the page
                    {
                        printf("----- %ld -----\n", pageno++);
                        lineno = 0;
                    }
                }
                fclose(fp);
            }
        }
    }
    exit(0);
}
