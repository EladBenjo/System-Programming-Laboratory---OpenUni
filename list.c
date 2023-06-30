#include "list.h"

/* a linked list with 'first' and 'last' pointers*/

list* createList(Node* node) {
    list* newList = (list*)malloc(sizeof(list));
    if (newList == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newList->first = node;
	newList->last = node;
    return newList;
}
