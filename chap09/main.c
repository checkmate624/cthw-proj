#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Seed for random number
	srand(time(0));
	
	//Set these to change the render
	int rows = 8;
	int columns = 12;

	int rowsDrawn = 0;
	int columnsDrawn = 0;
	int randomNumber;
	int finalNumber;

	//Define symbols to be drawn
	char *symbols[] = {
		" ", "+", "*",
	};
	
	//Draw rows
	while(rowsDrawn < rows)
	{
		columnsDrawn = 0;
		
		//Draw columns
		while(columnsDrawn < columns)
		{
			//Generate random number
			randomNumber = rand();

			//Limit random number to 0-2
			finalNumber = (randomNumber % 10) / 3.1;

			printf("%s", symbols[finalNumber]);
			columnsDrawn++;
		}
		
		rowsDrawn++;
		printf("\n");
	}

	return 0;
}
