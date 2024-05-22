/****************************************************************************
 File name:  	fileReading.c
 Author:
 Date:
 Class:				CS 300
 Assignment:	C File Reading Example Videos
 Purpose:			practice C strings
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for isspace()


 /****************************************************************************
  Function: 	 main

  Description: test file reading

  Parameters:	argc - the number of command line arguments
              argv - the actual command line arguments

  Returned:	 	EXIT_SUCCESS
  ****************************************************************************/
int main (int argc, char* argv[]) {

	const int SIZE = 100;
	FILE *pActions;
	char action;
	pActions = fopen("data/actions.dat", "r");

	while (EOF != fscanf(pActions, "%c", &action) )
	{
		//if(! isspace(action)) {
			printf("%c\n", action);
		//}
	}
	fclose(pActions);

	printf("\n ----data/values.dat----- \n\n");
	int value;
	char szName[SIZE];
	pActions = fopen("data/values.dat", "r");

	while (EOF != fscanf(pActions, "%c %d %s", &action, &value, szName) )
	{
		//if (! isspace(action)) {
			printf("action: >%c< value: %d string: %s\n", action, value, szName);
		//}
	}
	fclose(pActions);

	printf("\n ----data/values_intFirst.dat----- \n\n");
	pActions = fopen("data/values_intFirst.dat", "r");

	while (EOF != fscanf(pActions, "%d %c %s", &value, &action, szName) )
	{
		printf("action: %c value: %d string: %s\n", action, value, szName);
	}
	fclose(pActions);

	printf("\n ----data/values_intFirst.dat----- \n\n");
	
	char *szBuffer = NULL;
	size_t bytesRead;
	pActions = fopen("data/actions.dat", "r");

	while (-1 != getline(&szBuffer, &bytesRead, pActions) )
	{
		printf("line: >%s<", szBuffer);
		free(szBuffer);
		szBuffer = NULL;
	}
	fclose(pActions);

	printf("\n ----fgets() data/values.dat----- \n\n");
	pActions = fopen("data/values.dat", "r");

	while (NULL != fgets(szBuffer, SIZE, pActions) )
	{
		sscanf(szBuffer, "%c %d %s", &action, &value, szName);
		printf("action: %c value: %d string: %s\n", action, value, szName);
	}
	fclose(pActions);

	return EXIT_SUCCESS;
}
