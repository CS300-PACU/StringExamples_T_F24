/****************************************************************************
 File name:  	stringSolution2.c
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

  Description: test C string functions

  Parameters:	argc - the number of command line arguments
              argv - the actual command line arguments

  Returned:	 	EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {

	const int SIZE = 100;
	char szStr1[SIZE], szStr2[SIZE], szTemp[SIZE];
	int intOne, intTwo;

	printf("Enter two strings: ");
	scanf("%s %s", szStr1, szStr2);

	if ( 0 == strcmp(szStr1, szStr2)) {
		printf("The strings are the same!\n");
	}
	else {
		printf("The strings are different!\n");
	}

	if ( SIZE - strlen(szStr1) - 1 >= strlen(szStr2))
	{
		strncat(szStr1, szStr2,  SIZE - strlen(szStr1) - 1);
	}
	printf("After strncat: %s\n\n", szStr1);

	printf("Enter two integers: ");
	scanf("%d %d", &intOne, &intTwo);

	snprintf(szStr2, SIZE, "int1: %d int2: %d", intOne, intTwo);
	intOne = 0;
	intTwo = 0;
	sscanf(szStr2, "%s %d %s %d", szStr1, &intOne, szTemp, &intTwo);

	printf("szStr2: %s\n", szStr2);
	printf("intOne: %d intTwo: %d\n\n", intOne, intTwo);

	return EXIT_SUCCESS;
}
