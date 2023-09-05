#include <stdlib.h>

#define TABWID 8 /* default tab width */

void qsort_(int v[], int left, int right);

/* create_list: create list of jumps to the next tab position according to passed arguments */
void create_list(int argc, char *argv[], int list_jump[], int lim)
{
    int pos[argc - 1]; // array of passed tab positions
    int tab_width;
    int i, j, k, prev_pos, new_pos;

    if(argc > 1) // create list according to arguments
    {
        for(i = 0; i < argc - 1; i++)
            pos[i] = atoi(*++argv); // write consecutive arguments into array
        qsort_(pos, 0, argc - 2); // sort elements in ascending order

        prev_pos = 0;
        j = 0; // index of jump list array
        i = 0; // index of array of inserted tab positions
        k = 0; // temporary index which is counted from old position
        while(j < lim)
        {
            if(i < argc - 1) // determine new tab position
                new_pos = pos[i];
            else
                new_pos = lim;
            tab_width = new_pos - prev_pos;
            if(j < new_pos && tab_width != 0)
            {
                list_jump[j] = tab_width - (k%tab_width); // calculate how many spaces are equal to tab jump
                j++;
                k++;
            }
            else // update old position and reset index k
            {
                k = 0;
                i++;
                prev_pos = new_pos;
            }
        }
    }
    else // create default list
    {
        tab_width = TABWID;
        for(j = 0; j < lim; j++)
            list_jump[j] = tab_width - (j%tab_width); // calculate how many spaces are equal to tab jump
    }
}
