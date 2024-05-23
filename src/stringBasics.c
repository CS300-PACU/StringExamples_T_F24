/****************************************************************************
 File name:  	stringBasics.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C String Example Videos
 Purpose:			practice C strings
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTERS_SIZE 3

 /****************************************************************************
  Function: 	 	functionWithUnitializedCharArray

  Description: 	This function contains an unitialized char array

  Parameters:		update - a value to be used in the function

  Returned:	 		int - after a small calculation
  ****************************************************************************/
int functionWithUnitializedCharArray (int update)
{
	const int SIZE = 10;
	char szUnitializedLocalArray[SIZE];

	int value = 0;

	value += update;
	return value;
}

 /****************************************************************************
  Function: 	 	functionWithLotsOfLocalVars

  Description: 	This function creates and updates a large amount of local
								variables - data on the stack

  Parameters:		update - a value to be used in the function

  Returned:	 		int - after a small calculation
  ****************************************************************************/
int functionWithLotsOfLocalVars(int update)
{
	const int SIZE = 100;
	int intArray[SIZE];
	char szUnitializedLocalArray[SIZE];
	int value = 1;
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
  Function: 	 	receiveStringArray

  Description: 	This function receives a NULL terminated string as a parameter

  Parameters:		szName - the NULL terminated character array
								LENGTH - the size of the character array

  Returned:	 		NONE
  ****************************************************************************/
void receiveStringArray(char szName[], const int LENGTH) {
	printf("%s\n", szName);

	printf("%c -> %c\n", szName[0], szName[strlen(szName)-1]);
}

/****************************************************************************
  Function: 	 	receiveStringPtr

  Description: 	This function receives a NULL terminated string as a parameter

  Parameters:		pszName - a pointer to the NULL terminated character array
								LENGTH - the size of the character array

  Returned:	 		NONE
  ****************************************************************************/
void receiveStringPtr(char *pszName, const int LENGTH) {
	printf("%s\n", pszName);

	printf("%c -> %c\n", pszName[0], pszName[strlen(pszName)-1]);
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

	// you can't use a const int to size an array
	// if you initialize that array at declaration
	// use a #define
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

	// replace the \n read by fgets by a \0
	printf("replace the \\n read by fgets by a \\0\n");
	if ('\n' == szName[strlen(szName) - 1]) {
		szName[strlen(szName) - 1 ] = '\0';
	}
	printf("szName: >%s<\n", szName);

	printf("Printing an unitialized string: ");
	printf(">%s<\n", szUnitialized);

	functionWithUnitializedCharArray(2);
	functionWithLotsOfLocalVars(11);
	functionWithUnitializedCharArray(4);

	/////////////////
	receiveStringArray(szName, SIZE);
	receiveStringPtr(szName, SIZE);

	return EXIT_SUCCESS;
}