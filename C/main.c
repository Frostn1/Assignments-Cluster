#include "binNode.h"
#include <stdio.h>

int main() {
    int numArray[] = {3, 12, 6, 4, 9, 1, 23, 15, 7};
    BinNode* nodeList = Build(numArray, sizeof(numArray)/sizeof(int));
    printf("\nBefore insertion:\n");
    Show(nodeList);
    // Middle spot insertion
    Insert(nodeList, newNode(4, NULL, NULL), 37);
    printf("\nAfter insertion:\n");
    Show(nodeList);
    return 0;
}