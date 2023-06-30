#include "numNode.h"

/* numNode is a node in a linked list, storing index, value and a pointer to next*/

Node* createNode(unsigned long value, int i) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->index = i;
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

