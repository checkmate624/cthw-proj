#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Generate random seed
	srand(time(0));
	
	//Define array of numbers spelled out in english
	char *words[] = {
		"One", "Two", "Three", "Four", "Five", "Six", "Seven",
		"Eight", "Nine", "Ten"
	};
	
	//Generate random number
	int randomNumber = rand();

	//Get last digit of random number
	int lastDigitOfRandom = randomNumber % 10;

	//Print random item of the words array
	printf("%s\n", words[lastDigitOfRandom]);

	return 0;
}
