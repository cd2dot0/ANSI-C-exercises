#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode /* the tree node: */
{
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct tnode *addtree_m(struct tnode *, char *, int *);
void treeprint_m(struct tnode *, int);
int getword(char *, int);

/* print the distinct words sorted into decreasing order of frequency of occurrence */
main()
{
    struct tnode *root;
    char word[MAXWORD];
    int maxnum = 0; // number of occurrences of the most popular word
    int *pmax = &maxnum;

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
        {
            if(maxnum == 0) // there is at least a single word
                maxnum = 1;
            root = addtree_m(root, word, pmax);
        }
    for( ; maxnum > 0; maxnum--)
        treeprint_m(root, maxnum);
    return 0;
}

struct tnode *talloc(void);
char *strdup_(char *);

/* addtree_m: add a node with w, at or below p */
struct tnode *addtree_m(struct tnode *p, char *w, int *pmax)
{
    int cond;

    if(p == NULL) /* a new word has arrived */
    {
        p = talloc(); /* make a new node */
        p->word = strdup_(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
    {
        p->count++; // word repeats itself
        if(p->count > *pmax)
            *pmax = p->count;
    }
    else if(cond < 0)   /* less than into left subtree */
        p->left = addtree_m(p->left, w, pmax);
    else                /* greater than into right subtree */
        p->right = addtree_m(p->right, w, pmax);
    return p;
}

/* treeprint_m: in-order print of tree p but only those elements that their counter of occurrences is m */
void treeprint_m(struct tnode *p, int m)
{
    if(p != NULL)
    {
        treeprint_m(p->left, m);
        if(m == p->count)
            printf("%4d %s\n", p->count, p->word);
        treeprint_m(p->right, m);
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++)
        if(!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
