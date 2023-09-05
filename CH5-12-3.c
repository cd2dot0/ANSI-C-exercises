#include <stdlib.h>

#define TABWID 8 /* default tab width */

void qsort_(int v[], int left, int right);

/* create_list_ext: create list of jumps to the next tab position according to passed arguments; handle arguments -m +n */
void create_list_ext(int argc, char *argv[], int list_jump[], int lim)
{
    int pos[lim]; // array of passed tab positions
    int tab_width;
    int i, j, k, n, start, num_pos, prev_pos, new_pos;

    if(argc > 1) // create list according to arguments
    {
        start = -1;
        n = -1;
        j = 0;
        for(i = 0; i < argc - 1; i++)
        {
            if((*++argv)[0] == '-') // initial column of tabulation every n columns
                start = atoi(++(*argv));
            else if((*argv)[0] == '+')
                n = atoi((*argv)++); // user-defined tab width
            else
                pos[j++] = atoi(*argv); // write argument into array
        }
        if(start != -1 || n != -1)
        {
            if(start == -1) // default settings
                start = TABWID;
            if(n == -1)
                n = TABWID;
            pos[j] = start;
            while(pos[j++] < lim)
                pos[j] = pos[j - 1] + n;
        }
        num_pos = j; // final number of written tab positions
        qsort_(pos, 0, num_pos - 1); // sort elements in ascending order

        prev_pos = 0;
        j = 0; // index of jump list array
        i = 0; // index of array of inserted tab positions
        k = 0; // temporary index which is counted from old position
        while(j < lim)
        {
            if(i < num_pos) // determine new tab position
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
