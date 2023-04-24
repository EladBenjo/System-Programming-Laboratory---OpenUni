#include <stdio.h>
#include <stdlib.h>

/**
 * this program takes an unsigned long num, using bitwise '&' with 0xAAAAAAAA and the number
 * counting the even bits that are on and return the count.
 * by Elad Benjo April 2nd 2023.
 **/

/**function prototype**/
void clearBuffer(void); 
int count_bits(unsigned long num);
int main();

/**clearBuffer - consuming remaining 'chars' from the buffer**/
void clearBuffer(void)
{
	int c;
	while((c=getchar()) != '\n' && c != EOF);
}/*end of clearBuffer*/

/** count_bits - the method gets an unsigned long as argument, then using even bits mask and '&'
 *  to mark all the on even bits of the argument, in the end it returns the counter.
 **/ 
int count_bits(unsigned long num)
{
	int counter = 0;
	unsigned long even_bits_mask = 0xAAAAAAAA;/* 01's variable*/
	unsigned long even_bits = num & even_bits_mask;
	
	while (even_bits > 0)
	{
		if ((even_bits & 1) == 1)
			{
			counter++;
			}
		even_bits = even_bits >> 1;
	}/* end of while*/
	
	return counter;
}/* end of count bits*/

/** main - user interface, validators will eliminate program in case of invalid input **/
int main()
{
	unsigned long num;

	printf("Please insert your number: \n");
	if (scanf("%lu", &num) != 1){ /*not a number*/
		clearBuffer();
		printf("Invalid input! \n");
		return 0;}
	clearBuffer();
	printf("The number you entered is: %lu\n", num);
	printf("The amount of even bits that are on: %d\n\n", count_bits(num));

	printf("Goodbye! \n\n");
	return 0;
}/*end of main*/

