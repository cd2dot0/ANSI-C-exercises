#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void min_space(char line[], char new_line[], int list_jump[]);
void create_list_ext(int argc, char *argv[], int list_jump[], int lim);

/* entab: replace strings of blanks by the minimum number of tabs and blanks */
/* accept a list of tab stops as arguments (also shorthand entab -m +n) */
main(int argc, char *argv[])
{
    char line[MAXLINE]; /* current input line */
    char new_line[MAXLINE]; /* revised line */
    int list_jump[MAXLINE]; // list of jumps to the next tab position

    create_list_ext(argc, argv, list_jump, MAXLINE); // extended version

    while(getline(line, MAXLINE) > 0)
    {
        min_space(line, new_line, list_jump);
        printf("%s", new_line);
    }
    return 0;
}
