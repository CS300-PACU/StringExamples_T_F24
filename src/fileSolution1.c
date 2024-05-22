/****************************************************************************
 File name:  	fileSolution1.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C file Example Videos
 Purpose:			practice C file IO
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 /****************************************************************************
  Function: 	 	main

  Description: 	practice file IO

  Parameters:		argc - the number of command line argments
              	argv - the actual command line arguments

  Returned:	 		EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {

	int sum = 0, count = 0;

	int lineCount = 0, lineInt;
	int index;

	FILE *pNumbers;

	pNumbers = fopen("data/numbers.dat", "r");
	while (EOF != fscanf(pNumbers, "%d", &lineCount)) {
		count += lineCount;
		for(index = 0; index < lineCount; ++ index) {
			fscanf(pNumbers, "%d", &lineInt);
			sum += lineInt;
		}
	}
	fclose(pNumbers);

	// Sum: 142 Average: 12.909091
	printf("Sum: %d Average: %f\n\n", sum, sum/(1.0*count));

	return EXIT_SUCCESS;
}
