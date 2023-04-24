#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_CHAR 80

/*  This program offers 3 methods to use on strings, including comparing, comparing part of strings
 *  and locating a 'char'. the methods making use of loops and pointers (using the array 'structure'    
 *  of strings) to acomplish its purpose.
 *  by Elad Benjo April 2nd 2023.
 */

/*function prototype*/

int my_strcmp (const char *s1, const char *s2);
int my_strncmp (const char *s1, const char *s2, int n);
int my_strchr (const char *str, int c);
void interface (void);
void clearBuffer(void);

/*clearBuffer - consuming remaining 'chars' from the buffer*/
void clearBuffer(void)
{
	int c;
	while((c=getchar()) != '\n' && c != EOF);
}/*end of clearBuffer*/

/*my_strcmp - method gets 2 strings as an argument and compares them. if equal 
return 0, if s1 ASCII smaller than s2 return -1, else 1.*/
int my_strcmp(const char *s1, const char *s2)
{
	while (*s1==*s2)
		{
		if (*s1 == '\0')/*compared all and reached end of string*/
			{
			return 0;
			}
		s1++;
		s2++;
		}/*end of while loop*/
	return (*s1<*s2) ? -1 : 1;
}/* end of my_strcmp*/

/*my_strncmp - method gets 2 strings and an integer, then compares the 'n' 
characters of the strings. if equal return 0, if s1 ASCII smaller than s2 
return -1, else 1.*/
int my_strncmp (const char *s1, const char *s2, int n)
{
	while (*s1==*s2 && n>0 && *s1!= '\0' && *s2!= '\0')
		{
		n--;
		s1++;
		s2++;
		}/*end of while loop*/
	if (n==0 || (*s1=='\0' && *s2=='\0')) /*checked 'n' characters or strings shorter than 'n'*/
		{
		return 0;
		}
	return (*s1<*s2) ? -1 : 1;
}/*end of my_strncmp*/

/*my_strchr - method gets a string and a char, if the char appears in the string
it returns the index of it, else return (-1)*/
int my_strchr (const char *str, int c)
{
	int ptr = 0;
	while (*str != '\0')
		{
		if (*str == c)
			{
			return ptr;
			}
		str++;
		ptr++;
		}/*end of while loop*/
	return -1;
}/*end of my_strchr*/
/*interface - for user to choose and input*/
void interface (void)
{
	char choice;
	char s1[MAX_CHAR], s2[MAX_CHAR];
	int n;
	char c;
	bool valid_input;

	do
		{
		printf("Which function would you like to use?\n");
		printf("1. strcmp\n");
		printf("2. strncmp\n");
		printf("3. strchr\n");
		printf("4. quit\n");
		printf("Enter your choice (1-4):\n");
		scanf(" %c", &choice);
		clearBuffer();

		switch (choice)
			{
			case '1':
				printf("\nEnter the first string: \n");
				scanf("%s", s1);
				clearBuffer();
				printf("%s\n", s1);
				printf("Enter the second string: \n");
				scanf("%s", s2);
				clearBuffer();
				printf("%s\n", s2);
				printf("Result: %d\n\n", my_strcmp(s1,s2));
				valid_input = true;
				interface();
				break;
		
			case '2':
				printf("\nEnter the first string: \n");
				scanf("%s", s1);
				clearBuffer();
				printf("%s\n", s1);
				printf("Enter the second string: \n");
				scanf("%s", s2);
				clearBuffer();
				printf("%s\n", s2);
				printf("Enter the number of characters to compare: \n");
				if (scanf(" %d", &n) != 1){
					clearBuffer();
					printf("Invalid input! \n");
					break;}
				printf("%d\n", n);
				printf("Result: %d\n\n", my_strncmp(s1,s2,abs(n)));/*abs for negative*/
				valid_input = true;
				interface();
				break;

			case '3':
				printf("\nEnter the String: \n");
				scanf("%s", s1);
				clearBuffer();
				printf("%s\n", s1);
				printf("Enter the character to search for: \n");
				scanf(" %c", &c);
				clearBuffer();
				printf("%c\n", c);
				printf("Result: %d\n\n", my_strchr(s1,c));
				valid_input = true;
				interface();
				break;

			case '4':
				printf("\nGoodbye! \n");
				valid_input = true;
				break;

			default:
				printf("Invalid input!\n\n");
				break;
			}/*end of switch*/
		} while(!valid_input);/*loop until valid input (1-4)*/
}/* end of interface*/

/*main method*/
int main()
{
	interface();/*nice and neat capsulation*/
	return 0;
}/* end of main*/
				

				 
		
