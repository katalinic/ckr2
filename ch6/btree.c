#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"

#define MAX_WORD_LENGTH 100

typedef struct node *Treeptr;

struct node {
    char *word;
    int count;
    Treeptr left;
    Treeptr right;
};

typedef struct node Treenode;

Treeptr add(Treeptr p, char *word) {
    int cond;
    if (p == NULL) {
        p = malloc(sizeof (Treenode));
        p->word = astrdup(word);
        p->count++;
        p->left = NULL;
        p->right = NULL;
    } else if ((cond = strcmp(word, p->word)) == 0) {
        p->count++;
    } else if (cond > 0) {
        p->right = add(p->right, word);
    } else {
        p->left = add(p->left, word);
    }
    return p;
}

void printTree(Treeptr n) {
    if (n == NULL) {
        return;
    }
    printTree(n->left);
    printf("%s : %d\n", n->word, n->count);
    printTree(n->right);
}

void releaseNode(Treeptr n) {
    if (n == NULL) {
        return;
    }
    releaseNode(n->left);
    releaseNode(n->right);
    free(n->word);
    free(n);
}

int main() {
    char word[MAX_WORD_LENGTH];
    Treeptr root = NULL;

    while (getword(word, MAX_WORD_LENGTH) != EOF) {
        if (isalpha(word[0])) {
            root = add(root, word);
        }
    }
    printTree(root);

    releaseNode(root);
    return 0;
}
