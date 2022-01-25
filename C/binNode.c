#include "binNode.h"

// Addition functions
BinNode* Add(BinNode* node, int x) {
    while(node->prev != NULL) node = node->prev;
    node->prev = newNode(x, NULL, node);
    return node->prev;
}

BinNode* Insert(BinNode* node, BinNode* pos, int x) {
    if(!pos) return Add(node, x);
    while(node->prev) node = node->prev;
    while(node && node->data != pos->data) node = node->next;
    if(node->data == pos->data) {
        node->next = newNode(x, node, node->next);
        return node;
    } 
    return NULL;
}

BinNode* InsertSorted(BinNode* node, int x) {
    while(node->prev != NULL) node = node->prev;
    while(node->next != NULL && node->data < x) node = node->next;
    node->next = newNode(x, node, node->next);
    return node;
}

// Creation functions
BinNode* newNode(int data, BinNode* prev, BinNode* next) {
    BinNode* node = (BinNode*)malloc(sizeof(BinNode));
    node->data = data;
    node->prev = prev;
    node->next = next;
    return node;
}

BinNode* Build(int* arr, int size) {
    if (!arr || !size) return NULL;
    BinNode* node = newNode(arr[0], NULL, NULL);
    for (size_t i = 1; i < size; i++) {
        node->prev = newNode(arr[i], NULL, node);
        node = node->prev;
    }
    return node;
    
}

// Removing functions
BinNode* Remove(BinNode* node) {
    while(node->prev) node = node->prev;
    node = node->next;
    FreeNode(node->prev);
    node->prev = NULL;
    return node;
}

BinNode* RemoveAt(BinNode* node, BinNode* pos) {
    while(node->prev) node = node->prev;
    while(node->next && node->next->data != pos->data) node = node->next;
    if(node->next->data == pos->data) {
        BinNode* temp = node->next;
        node->next = node->next->next;
        if(node->next) node->next->prev = node;
        FreeNode(temp);
        return node;
    } 
    return NULL;
}

// Printing functions
void Show(BinNode* node) {
    while(node->prev) node = node->prev;
    while(node) {
        printf("%d ",node->data);
        node = node->next;
    }
    return;
}

void ShowBackword(BinNode* node) {
    while(node->next) node = node->next;
    while(node) {
        printf("%d ",node->data);
        node = node->prev;
    }
    return;
}

// Locating functions
BinNode* GetLast(BinNode* node) {
    while(node->next) node = node->next;
    return node;
}

BinNode* GetPosition(BinNode* node, int x) {
    while(node->prev) node = node->prev;
    while(node->next && node->next->data != x) node = node->next;
    if(node->next->data == x) return node->next;
    return NULL;
}


// Utility functions
void FreeNode(BinNode* node) {
    node->next = NULL;
    node->prev = NULL;
    free(node);
    return;
}

void FreeNodeList(BinNode* node) {
    while(node->prev) node = node->prev;
    while(node->next) {
        node = node->next;
        FreeNode(node->prev);
    }
    FreeNode(node);
    return;
}
