#include <string.h>
#include <stdlib.h>

unsigned hash(char *);

/* undef: remove a name and definition from the table */
void undef(char *s)
{
    struct nlist *np, *next_np = NULL;
    unsigned hashval;
    int i = 0; // counter of structures
    int is_del = 0;

    hashval = hash(s); // table index
    for(np = hashtab[hashval]; np != NULL; np = np->next)
    {
        if(strcmp(s, np->name) == 0)    // find a name to remove
        {
            if(np->next != NULL)        // if it was not the last column,
                next_np = np->next;     // save the address of the next one
            free((void *) np->name);
            free((void *) np->defn);
            free((void *) np);          // free allocated memory for the structure
            is_del = 1;
            break;
        }
        i++;
    }
    if(is_del == 1) // is a structure removed?
    {
        if(i == 0) // the first structure was removed
            hashtab[hashval] = next_np;
        else
        {
            for(np = hashtab[hashval]; i > 1; np = np->next) // go to the structure before the removed one
                i--;
            np->next = next_np;
        }
    }
}
