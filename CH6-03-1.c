#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXLINES 10000 /* maximum lines number */
#define NUMEL (sizeof irr_tab / sizeof(struct irrelevant))

struct tnode /* the tree node: */
{
    char *word;             /* points to the text */
    char lines[MAXLINES + 1]; /* array of occurings */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct irrelevant
{
    char *word;
} irr_tab[] =
{
    "a",
    "an",
    "and",
    "but",
    "or",
    "the"
};

struct tnode *addtree_l(struct tnode *, char *, int);
void treeprint_l(struct tnode *);
int getword(char *, int);
int binsearch(char *, struct irrelevant *, int);

/* print a list of all words (skip irrelevant ones) with a list of the line numbers on which they occur */
main()
{
    struct tnode *root;
    char word[MAXWORD];
    int i = 1; // line number

    root = NULL;
    while(i <= MAXLINES && getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
        {
            if((binsearch(word, irr_tab, NUMEL)) == -1)
                root = addtree_l(root, word, i);
        }
        else if(word[0] == '\n')
            i++;
    treeprint_l(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup_(char *);

/* addtree_l: add a node with w, at or below p */
struct tnode *addtree_l(struct tnode *p, char *w, int i)
{
    int cond;
    int j;

    if(p == NULL) /* a new word has arrived */
    {
        p = talloc(); /* make a new node */
        p->word = strdup_(w);
        for(j = 1; j <= MAXLINES; j++)
            p->lines[j] = 0;
        p->lines[i] = 1; // the word occurs for the first time
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
        p->lines[i] = 1; // the word occurs again
    else if(cond < 0)   /* less than into left subtree */
        p->left = addtree_l(p->left, w, i);
    else                /* greater than into right subtree */
        p->right = addtree_l(p->right, w, i);
    return p;
}

/* treeprint_l: in-order print of tree p */
void treeprint_l(struct tnode *p)
{
    int j;
    int first = 1;

    if(p != NULL)
    {
        treeprint_l(p->left);
        printf("%s ", p->word);
        for(j = 1; j <= MAXLINES; j++)
            if(p->lines[j] == 1 && first == 1)
            {
                printf(" %d", j);
                first = 0;
            }
            else if(p->lines[j] == 1)
                printf(", %d", j);
        printf("\n");
        treeprint_l(p->right);
    }
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct irrelevant tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low  = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* getword: get next word or character from input */
/* return also a newline character '\n' */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()) && c != '\n')
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
