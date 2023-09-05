#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void no_tab(char line[], char new_line[], int list_jump[]);
void create_list_ext(int argc, char *argv[], int list_jump[], int lim);

/* detab: replace tabs with spaces in the input data */
/* accept a list of tab stops as arguments (also shorthand detab -m +n) */
main(int argc, char *argv[])
{
    char line[MAXLINE]; /* current input line */
    char new_line[MAXLINE]; /* revised line */
    int list_jump[MAXLINE]; // list of jumps to the next tab position

    create_list_ext(argc, argv, list_jump, MAXLINE); // extended version

    while(getline(line, MAXLINE) > 0)
    {
        no_tab(line, new_line, list_jump);
        printf("%s", new_line);
    }
    return 0;
}
