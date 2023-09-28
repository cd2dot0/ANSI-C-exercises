#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char *line, int max);
char *fgets_(char *, int, FILE *);

/* find: print lines that match pattern from 1st arg; 3rd version */
/* take the input from a set of named files or, if no files are named as arguments, from the standard input */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char *pattern, *p;
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    FILE *fp;

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                fprintf(stderr, "find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if(argc < 1) // there is no pattern
        fprintf(stderr, "Usage: find -x -n pattern file1 file2 ...\n");
    else if(argc > 1) // there are a pattern and files names
    {
        pattern = *argv;
        while(argc-- > 1)
        {
            if((fp = fopen(*++argv, "r")) == NULL) // open the file
            {
                fprintf(stderr, "find: can't open %s\n", *argv);
                found = -1;
            }
            else
            {
                while((p = fgets_(line, MAXLINE, fp)) != NULL) // check the consecutive lines of the file
                {
                    lineno++;
                    if((strstr(line, pattern) != NULL) != except)
                    {
                        printf("%-10s ", *argv);
                        if(number)
                            printf("%ld:", lineno);
                        printf("%s", line);
                        found++;
                    }
                }
                fclose(fp);
                lineno = 0;
            }
        }
    }
    else // there is only pattern
        while(getline(line, MAXLINE) > 0)
        {
            lineno++;
            if((strstr(line, *argv) != NULL) != except)
            {
                if(number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}
