#ifndef BIN_NODE_H
#define BIN_NODE_H

// Includes
#include <stdio.h>
#include <stdlib.h>

#define NULL_POS -1

// Struct for two sided node
typedef struct BinNode {
    int data;
    struct BinNode* next;
    struct BinNode* prev;
}BinNode;

// Addition functions
BinNode* Add(BinNode* node, int x);
BinNode* Insert(BinNode* node, BinNode* pos, int x); // if @pos is null, @x will be added at the end of the list
BinNode* InsertSorted(BinNode* node, int x);

// Creation functions
BinNode* newNode(int data, BinNode* prev, BinNode* next);
BinNode* Build(int* arr, int size); // if @arr is null, an empty list will be returned

// Removing functions
BinNode* Remove(BinNode* node); // deletes the first element in the list
BinNode* RemoveAt(BinNode* node, BinNode* pos); // assumption, @pos isn't null

// Printing functions
void Show(BinNode* node);
void ShowBackword(BinNode* node);

// Locating functions
BinNode* GetLast(BinNode* node);
BinNode* GetPosition(BinNode* node, int x);


// Utility functions
void FreeNode(BinNode* node);
void FreeNodeList(BinNode* node); // Given node head free entire list forward

#endif // !BIN_NODE_H