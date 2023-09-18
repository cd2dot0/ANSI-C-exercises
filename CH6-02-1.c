#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define N 6
#define NKEYS (sizeof keytab / sizeof(struct key))

struct tnode /* the tree node: */
{
    char *word;             /* points to the text */
    int group;              /* affiliation to a group of names */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

struct key
{
    char *word;
} keytab[] =
{
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while"
};

struct tnode *addtree_n(struct tnode *, char *, int, int);
void treeprint_n(struct tnode *);
int getword(char *, int);
int binsearch(char *, struct key *, int);

/* print in alphabetical order each group of variable names (at least 2 names) that are identical in the first n (default 6) characters */
main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int n, in_group;

    if(argc == 2)
        n = atoi(argv[1]); // user-defined value
    else
        n = N; // default value

    if(n <= 0) // handle a non-positive value
        n = N;
    else if(n > MAXWORD) // handle a value above MAXWORD
        n = MAXWORD;

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((binsearch(word, keytab, NKEYS)) == -1 && strlen(word) >= n)
            {
                in_group = 0; // 0 - the name does not belong to a group
                root = addtree_n(root, word, n, in_group);
            }
    treeprint_n(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup_(char *);
int strcmp_n(char *, char *, int);

/* addtree_n: add a node with w, at or below p */
struct tnode *addtree_n(struct tnode *p, char *w, int n, int in_group)
{
    int cond;

    if(p == NULL) /* a new word has arrived */
    {
        p = talloc(); /* make a new node */
        p->word = strdup_(w);
        p->group = in_group;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) < 0)   /* less than into left subtree */
    {
        if(in_group == 0 && strcmp_n(w, p->word, n) == 0) // w and p->word create a common group of names
        {
            p->group = 1;
            in_group = 1;
        }
        p->left = addtree_n(p->left, w, n, in_group);
    }
    else if((cond = strcmp(w, p->word)) > 0)    /* greater than into right subtree */
    {
        if(in_group == 0 && strcmp_n(w, p->word, n) == 0)
        {
            p->group = 1;
            in_group = 1;
        }
        p->right = addtree_n(p->right, w, n, in_group);
    }
    return p;

}

/* treeprint_n: in-order print of tree p */
void treeprint_n(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint_n(p->left);
        if(p->group == 1)
            printf("%s\n", p->word);
        treeprint_n(p->right);
    }
}

/* strcmp_n: return negative, zero, or positive for s < t, s == t, s > t; compare only the first n characters */
int strcmp_n(char *s, char *t, int n)
{
    char *s0 = s;

    for( ; *s == *t; s++, t++)
        if(*s == '\0' || s - s0 == n - 1)
            return 0;
    return *s - *t;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
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
