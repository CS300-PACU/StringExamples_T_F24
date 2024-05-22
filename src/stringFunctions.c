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
	char szName[SIZE];
	int index = 11;

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
	printf("\n\n");

	//////////// strcmp()

	char szStr1[SIZE], szStr2[SIZE];

	printf("Please enter a string (try Hola or Aloha or Hello): ");
	scanf("%s", szStr1);
	strncpy(szStr2, "Hello", SIZE);

	if (strcmp(szStr1, "Hola") == 0) { // test for equality
		printf("szStr1 is Hola");
	} 
	else if (strcmp(szStr1, "Aloha") == 0) { 
		printf("szStr1 is Aloha!");
	} 
	if (strcmp(szStr1, szStr2) != 0) { // test for not equal
		printf("szStr1 is NOT Hello");
	}
	printf("\n\n");


	/////////////////// strncpy()
	strncpy(szName, "CS300", SIZE);
	printf(" strncpy(szName, \"CS300\", SIZE): >%s<\n", szName);

	memset(szName, 'a', SIZE); // fill szName with a, no \0
	strncpy(szName, "CS300", 2); // compiler gives a clever warning!
	printf(" strncpy(szName, \"CS300\", 2): >%s<\n", szName);
	printf("\n\n");


	//////////////////// strncat()
	const int SHORT_SIZE = 6;
	char dest[SHORT_SIZE];
	char src[SHORT_SIZE/2];


	// compiler gives a clever warning for the following line.
	// pay close attention to your compiler warnings!
	// strncpy(src, "CS", SHORT_SIZE);

	strncpy(src, "CS", SHORT_SIZE/2);

	// make sure dest is initialized to '\0'
	memset(dest, '\0', SHORT_SIZE);

	strncat(dest, src, SHORT_SIZE - 1);

	printf("strncat(dest, src, SHORT_SIZE - 1): >%s<\n", dest);

	strncat(dest, "PU", SHORT_SIZE - strlen(dest) - 1);
	printf("strncat(dest, \"PU\", SHORT_SIZE - strlen(dest) - 1): >%s<\n", dest);
	printf("\n\n");


	//////////////////// snprintf()
	const int LARGE_SIZE = 100;
	char szDestination[LARGE_SIZE];

	snprintf(szDestination, LARGE_SIZE, "%d", 100);

	printf("snprintf(szDestination, LARGE_SIZE, \"%%dn\", 100): >%s<\n", 
		szDestination);

	snprintf(szDestination, LARGE_SIZE, "int: %d double: %f", 100, 3.14159);

	printf("snprintf(szDestination, LARGE_SIZE, \"int: %%d double: %%f\", 100, 3.14159) >%s<\n", szDestination);
	printf("\n\n");


	//////////////////// sscanf()
	int intValue, number;
	char szStr[LARGE_SIZE];
	char szData[LARGE_SIZE];
	char extraNewline;

	// scanf() left a \n in the keyboard buffer
	// clear it out before we call fgets()
	extraNewline = fgetc(stdin); 

	printf("Please enter an int, a string, and an int: ");
	fgets(szStr, LARGE_SIZE, stdin);
	printf("The user's string: >%s<\n", szStr);

	sscanf(szStr, "%d %s %d", &intValue, szData, &number);
	printf("sscanf() -> int: %d string: %s int: %d\n", intValue, szData, number);

	return EXIT_SUCCESS;
}
