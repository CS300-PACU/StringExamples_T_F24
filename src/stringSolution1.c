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


 /****************************************************************************
  Function: 	 main

  Description: test C Strings

  Parameters:	argc - the number of command line arguments
              argv - the actual command line arguments

  Returned:	 	EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {


	// Declare a character array of size 15
	const int SIZE = 15;
	char szData[SIZE];
	int index;

	// Ask the user to input a string from the keyboard
	printf("Input a string: ");
	scanf("%s", szData);
	// OR
	// fgets(szData, SIZE, stdin);

	// Print that string on the screen with its length
	printf("%s len: %ld\n", szData, strlen(szData));

	// Print that string on the screen backwards
	for (index = strlen(szData)-1; index >=0 ; --index) 
	{
		printf("%c", szData[index]);
	}

	// Capitalize every 'a' in the string
	for (index = 0; index < strlen(szData); ++index) 
	{
		if ('a' == szData[index])
		{
			szData[index] = 'A';
		}
	}
	printf("\n");
	
	// Print the edited string to the screen
	printf("%s\n\n", szData);

	return EXIT_SUCCESS;
}
