#include "binNode.h"
#include <stdio.h>

int main() {
    int numArray[] = {3, 12, 6, 4, 9, 1, 23, 15, 7};
    BinNode* nodeList = Build(numArray, sizeof(numArray)/sizeof(int));

    // Insertion
    printf("\nInsertion Test:\n");
    Show(nodeList);
    Insert(nodeList, newNode(4, NULL, NULL), 37);
    Insert(nodeList, newNode(3, NULL, NULL), 54);
    Insert(nodeList, newNode(12, NULL, NULL), 8);
    putchar('\n');
    Show(nodeList);


    // Deletion
    printf("\nDeletion Test:\n");
    Show(nodeList);
    RemoveAt(nodeList, newNode(54, NULL, NULL));
    RemoveAt(nodeList, newNode(4, NULL, NULL));
    putchar('\n');
    Show(nodeList);

    return 0;
}