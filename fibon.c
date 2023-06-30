#include <string.h>
#include "numNode.h"
#include "list.h"

/* function prototypes */
struct list* fibMaker(int num);
void fibPrinter(struct Node* ptr, FILE* file);
void freeNodes(struct list* fibList);

/* fibMaker gets a number and create a linked list for it's fibonacci series.
 * for 0 and 1 it is manually done, greater - the program will add the value
 * from the last 2 nodes to crate the new one. finish with connecting the first
 * node to the last one to create a 'circle'.
 * the user is limited to 0<=n<=46 as input due to unsigned long limitations,
 * the 47th memeber would be wrong.
 * @param n the number of members in the series excluding fib 0.
 * @return the new fib series as a linked list
 */
struct list* fibMaker(int num)
{
	struct Node* node = createNode(1,0);
	struct list* list = createList(node);
	struct Node* ptr = node;

	for (int i = 1; i<= num; i++)
	{
		if (i == 1)
		{
			node = createNode(1, i);
			node-> next = list-> first;
			list->last = node;
			ptr = node;
		}
		
		else
		{
			unsigned long x = ptr-> next-> val;
			unsigned long y = ptr-> val;
			node = createNode(x+y,i);
			node-> next = ptr;
			list->last = node;
			ptr = node;
		}
	}
	list->first->next = list->last;
	return list;
}

/* fibPrinter gets the last node of the series and prints all the members from
 * it down to fib 0 - both to the screen and the file.
 * @param ptr is the last node of the series
 * @param file is the file to print into
 */
void fibPrinter(struct Node* ptr, FILE* file)
{
	int i = ptr-> index;
	
	/* to file*/
	fprintf(file, "This program creates a fibonacci series, from 0 to your input.\n");
	fprintf(file, "For your input %d, here is the series:\n", i);
	
	/* to the screen*/
	printf("Fibonacci Series:\n");
	
	/*iterating down the list from n to 0*/
	while(i>=0)
		{
			if (i == 0) /* means we at the last node -fib 0 */
			{
				printf("%lu.", ptr->val);
				fprintf(file, "%lu.", ptr->val);
				break;
			}
			else
			printf("%lu, ", ptr-> val);
			fprintf(file, "%lu, ", ptr->val);
			ptr = ptr-> next;
			i = ptr-> index;
		}
	printf("\n");
    fprintf(file, "\n");
}

/* freeNodes iterates through the linked list to free up the memory
 * @param fibList is a list that was built by fibMaker and we want to free it nodes
 */
void freeNodes(struct list* fibList) 
{
    struct Node* current = fibList->last;
    while (current != NULL) 
    {
    	if (current-> index == 0)
    	{
    		free(current);
    		break;
    	}
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

/* the main method deals with the file the user given to it, if it does'nt exist
 * it creates one. main used as user interface for inputing the desired size of
 * the fibonacci series and ties between the functions that create the list, 
 * print it and free up the memory.
 */
int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	
	char* fileName = argv[1];
	
	FILE* file = fopen (fileName, "a+");
	if (file == NULL)
	{
		file = fopen(fileName, "w");
		if (file == NULL)
		{
			printf("Unable to open\\create file.\n");
			return 1;
		}
	}
	
	int n;
	
	printf("This program creates a fibonacci series, insert you number (0-46):\n");
	while (!scanf("%d", &n) || n < 0 || n > 46)
	{
    	printf("Invalid input. Please enter a value between 0 and 46: ");
    	// Clear the input buffer
    	while (getchar() != '\n')
        	continue;
	}
	
	struct list* fibList = fibMaker(n);
	struct Node* ptr = fibList-> last;

    fibPrinter(ptr, file);

    fclose(file);

	freeNodes(fibList);
    free(fibList);
    free(ptr);
    return 0;

}
