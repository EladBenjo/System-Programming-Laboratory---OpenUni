#ifndef LIST_H
#define LIST_H

#include "numNode.h"

typedef struct list {
    struct Node* first;
    struct Node* last;
} list;

list* createList(Node* node);

#endif /* LIST_H */

