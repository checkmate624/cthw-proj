#include <stdio.h>
#include <stdlib.h>

int main()
{
	int8_t position = 0;
	int8_t array[] = { 3, 0, 5, 0, 1, 0, -5, 0, 1, 0};
	
	//Convert the size of the array to a signed 8 bit int
	int8_t arraySize = (int8_t) sizeof(array);

	//If the position is a valid index of the array
	while(position > -1 && position < arraySize)
	{
		if(array[position] == 0)
		{
			printf("%d\n", position);
			position += 1;
		}
		else
		{
			position += array[position];
		}
	}

	printf("DONE\n");

	return 0;
}

