/****************************************************************************
 File name:  	stringPointers.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C String Example Videos
 Purpose:			practice C strings and pointers
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 /****************************************************************************
  Function: 	 main

  Description: test C Strings & pointers

  Parameters:	argc - the number of command line arguments
              argv - the actual command line arguments

  Returned:	 	EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {

	const int SIZE = 100;
	char *pszData;
	char *pszDouble;
	int doubleLen;

	pszData = (char*) malloc (SIZE * sizeof(char));

	printf("Please enter a string: ");
	scanf("%s", pszData);
	printf("Your string: %s\n", pszData);

	/*
		Use this in the Watch Panel in the debugger to see the entire array.

		/nat *(char(*)[100])pszData
	*/

	doubleLen = (strlen(pszData)*2 + 1);
	pszDouble = (char*) malloc(sizeof(char) * doubleLen);
	strncpy(pszDouble, pszData, doubleLen);

	/*
		Use this in the Watch Panel in the debugger.

		/nat *(char(*)[###])pszDouble
		-> change ### to the value of doubleLen
	*/
	strncat(pszDouble, pszData, doubleLen - strlen(pszDouble) - 1);
	printf("Your string doubled: %s\n", pszDouble);

	free(pszData);
	free(pszDouble);
	
	return EXIT_SUCCESS;
}
