/****************************************************************************
 File name:  	fileSolution2.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C file Example Videos
 Purpose:			practice C file IO
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ADD 'A'
#define SUB 'S'

 /****************************************************************************
  Function: 	 	main

  Description: 	practice file IO

  Parameters:		argc - the number of command line argments
              	argv - the actual command line arguments

  Returned:	 		EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {

	// const char ADD = 'A'; // const char won't work in case
	// const char SUB = 'S'; // you must use a #define

	const int SIZE = 1000;
	char szBuffer[SIZE];

	int sum = 0;

	char action;
	int lineInt;
	
	FILE *pNumbers;

	pNumbers = fopen("data/numberActions.dat", "r");
	while (NULL != fgets(szBuffer, SIZE, pNumbers) ) {
		
		// if you use fscanf in the while(), the \n remains
		// in the file and you appear to read each line twice!

		sscanf(szBuffer, "%c %d", &action, &lineInt);
		switch(action) {
			case ADD:
				sum += lineInt;
				break;
			case SUB:
				sum -= lineInt;
				break;
		}
		// final result: Sum: -599
		printf("Sum: %d\n", sum);

	}
	fclose(pNumbers);


	return EXIT_SUCCESS;
}
