#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int index;
    unsigned long val;
    struct Node* next;
} Node;

Node* createNode(unsigned long value, int i);

#endif /* NODE_H */

