#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    TNode *left;
    TNode *right;
}TNode;

TNode *initBTree(int elements[], int size) {
    if (size < 1) {
        return NULL;
    }
    TNode **nodes = (TNode *)malloc(size * sizeof(TNode));
    for (int i = 0; i < size; i++) {
        if(elements[i] == 0) {
            nodes[i] = NULL;
        }
        else {
            nodes[i] = (TNode *)malloc(sizeof(TNode));
            nodes[i]->val = elements[i];
        }
    }
}

int main(int argc, char **argv) {
    return 0;
}