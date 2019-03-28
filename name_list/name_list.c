#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **add_string(int totalNames, char **array,  char *string)
{
	array = realloc(array, (totalNames + 1) * sizeof(char*));
	array[totalNames] = string;
	return array;
}

void ListNames(int totalNames, char **firstNames, char **lastNames)
{
	if (totalNames == 0) {
		printf("No records currently stored.\n");
		return;
	 }

	for (int i = 0; i < totalNames; i++) {
		printf("(%d) %s %s\n", (i + 1), firstNames[i], lastNames[i]);
	}
	printf("\n");
}

int main ()
{
	char **firstNames = NULL;
	char **lastNames = NULL;
	char *newName = NULL;
	int totalNames = 0;	

	while (1) {
		printf("Enter first name, type 'l' to List, or 'e' to Exit: ");
		scanf("%ms", &newName);

		// Proccess Input
		if (strcmp(newName, "e") == 0) {
			// Free everything
			for(int i =0; i < totalNames; i++) {
				free(firstNames[i]);
				free(lastNames[i]);
			}

			free(firstNames);
			free(lastNames);
			free(newName);
			break;
		} else if (strcmp(newName, "l") == 0) {
			ListNames(totalNames, firstNames, lastNames);
		} else {
			// Add first name
			firstNames = add_string(totalNames, firstNames, newName);
			printf("Added '%s'\n", firstNames[totalNames]);

			// Add last Name
			printf("Enter last name: ");
			scanf("%ms", &newName);
			lastNames = add_string(totalNames, lastNames, newName);
			printf("Added '%s'\n", lastNames[totalNames]);

			totalNames += 1;

			// Print total records
			if (totalNames == 1) {
				printf("Now storing (1) record.\n\n");
			} else {	
				printf("Now storing (%d) records.\n\n", totalNames);
			}
		}	
	}
	return(0);
}