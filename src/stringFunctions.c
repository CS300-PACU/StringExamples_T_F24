/****************************************************************************
 File name:  	stringFunctions.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C String Example Videos
 Purpose:			practice C strings
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

	const int SIZE = 10;
	char szName[SIZE];
	int index;

	// fill a character array
	memset(szName, 'a', SIZE);
	memset(szName, '\0', SIZE);

	// walk through a NULL terminated string
	// check for \0 and make sure index does
	// not walk off the end of the array!
	strncpy(szName, "CS300", SIZE);
	for (index = 0; '\0' != szName[index] && index < SIZE; ++index) {
		printf("%c", szName[index]);
	}

	////////////

	char szStr1[SIZE], szStr2[SIZE];

	scanf("%s", szStr1);
	strncpy(szStr2, "Hello", SIZE);

	if (strcmp(szStr1, "Hola") == 0) { // test for equality
		printf("szStr1 is Hola");
	} 
	else if (strcmp(szStr1, "Aloha") == 0) { 
		printf("szStr1 is Aloha!");
	} 
	else if (strcmp(szStr1, szStr2) != 0) { // test for not equal
		printf("szStr1 is NOT Hello");
	}

	///////////////////

	strncpy(szName, "CS300", SIZE);
	printf(" strncpy(szName, \"CS300\", SIZE): >%s<\n", szName);

	strncpy(szName, "CS300", 2);
	printf(" strncpy(szName, \"CS300\", 2): >%s<\n", szName);


	return EXIT_SUCCESS;
}
