/****************************************************************************
 File name:  	practiceStringBasics.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C String Example Videos
 Purpose:			practice C strings
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define LETTERS_SIZE 3


int functionWithUnitializedCharArray (int update)
{
	const int SIZE = 10;
	char szUnitializedLocalArray[SIZE];
	int value;

	value += update;
	return value;
}

int functionWithLotsOfLocalVars(int update)
{
	const int SIZE = 100;
	int intArray[SIZE];
	char szUnitializedLocalArray[SIZE];
	int value;
	double doubleNumber;
	int secondIntArray[SIZE];

	value += update;
	memset(intArray, 0x11, SIZE*sizeof(int));
	memset(secondIntArray, 0x13, SIZE*sizeof(int));
	memset(szUnitializedLocalArray, 0x11, SIZE*sizeof(char));

	doubleNumber = 100.8 * value;
	value -= doubleNumber;
	return value;
}



 /****************************************************************************
  Function: 	 main

  Description: test C Strings

  Parameters:	argc - the number of command line arguments
              argv - the actual command line arguments

  Returned:	 	EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {

	const int SIZE = 10;
	const int ARRAY_SIZE = 4;
	char szLetters[ARRAY_SIZE];
	char letters[LETTERS_SIZE] = {'A', 'B', 'C'};
	char szName[SIZE];
	char szUnitialized[SIZE];

	// szLetters = "ABC";

	strncpy(szLetters, "ABC", ARRAY_SIZE);

	printf("szLetter, a null terminated character array:\n");
	printf("%c", szLetters[1]);
	printf("\n\n");
  printf("%s", szLetters);

	printf("\n\n");
	printf("letters, a character array:\n");
	printf("%c", letters[1]);
	printf("\n\n");
	printf("%s", letters);

	/////////////////////////
	printf("\n\nszName, after using strncpy():\n");
	strncpy(szName, "CS300", SIZE);
	printf("\n%ld %s\n\n", strlen(szName), szName);

	printf("Using scanf to read a string: ");
	scanf("%s", szName);
	printf("%s\n", szName);

	// scanf leaves the \n in the keyboard buffer so
	// we need to read it before we use fgets() or getline()
	getc(stdin); 

	printf("Using fgets to read a string: ");
	fgets(szName, SIZE, stdin);
	printf(">%s<\n", szName);


	printf("Printing an unitialized string: ");
	printf(">%s<\n", szUnitialized);

	functionWithUnitializedCharArray(2);
	functionWithLotsOfLocalVars(11);
	functionWithUnitializedCharArray(4);

	return EXIT_SUCCESS;
}
