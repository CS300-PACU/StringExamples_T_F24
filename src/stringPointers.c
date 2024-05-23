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

	char *pszName, *pCurrChar;
	int index, length = 10;

	pszName = (char*) malloc (length * sizeof(char));
	strncpy(pszName, "CS300", length);

	printf("%s\n", pszName);

	for (index = 0; index < length && '\0' != pszName[index]; ++ index) {
		printf("%c", pszName[index]);
	}
	printf("\n");

	pCurrChar = pszName;
	while ('\0' != *pCurrChar){
		printf("%c", *pCurrChar);
		++ pCurrChar;
	}
	printf("\n");

	free(pszName);
	
	return EXIT_SUCCESS;
}
