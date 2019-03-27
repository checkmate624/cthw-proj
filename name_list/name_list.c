#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **add_string(char **array,  char *string, int totalStrings)
{
	array = realloc(array, (totalStrings + 1) * sizeof(char*));
	array[totalStrings] = string;
	return array;
}

int main ()
{
	char **firstNames = NULL;
	int totalNames = 0;
	char *newName = NULL;

	while(1) {
		printf("Enter first name or type quit ot exit: ");
		scanf("%ms", &newName);
		printf("%zu\n", strlen(newName));
		printf("%s\n", newName);
		if(strcmp(newName, "quit") == 0) {
			break;
		}

		printf("%p\n", firstNames);
		firstNames = add_string(firstNames, newName, totalNames);
		printf("%p\n", firstNames);		

		printf("Added '%s'\n", firstNames[totalNames]);
		totalNames += 1;
		printf("Now storing (%d) records.\n", totalNames);	
	}
	
   
	return(0);
}