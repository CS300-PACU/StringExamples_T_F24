/****************************************************************************
 File name:  	stringSolution1.c
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

	// Copy the string “HELLO CS!” into the array
	strncpy(szData, "HELLO CS!", SIZE);
	
	// Print that string on the screen
	printf("%s\n", szData);

	// Ask the user to input a string from the keyboard
	printf("Input a string: ");
	scanf("%s", szData);
	// OR
	// fgets(szData, SIZE, stdin);

	// Print that string on the screen with its length
	printf("%s len: %ld\n", szData, strlen(szData));

	// Print the last character before the \0 on the screen
	printf("Last character %c\n\n", szData[strlen(szData) - 1]);

	return EXIT_SUCCESS;
}
