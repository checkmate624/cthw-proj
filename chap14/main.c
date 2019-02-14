#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int steps = 0;
double value = 0;
double precision = .001;

double generate_number()
{
	//return rand() % 1000;
	return 148.00;
}

double find_square_root(double num, double precision)
{
	//If the function received valid arguments
	if(num > 0 && precision > 0)
	{ 
		printf("Your starting number is %f\n", num);
		value = num / 2;

		//While the difference is larger than the allotted value
		while(fabs((value*value) - num) > precision)
		{
			value = (value + (num / value)) / 2;
			steps++;
			printf("Squared: %lf\n", value * value);
			printf("Difference: %lf\n", (value * value) - num);

		}

		printf("It took %i steps to find\n", steps);
		return value;
	}
	else
	{
		printf("Pass better arguments\n");
		return 0;
	}
}

int main(int argc, char *argv[])
{
	srand(time(0));

	printf("The square root is %lf\n", find_square_root(generate_number(), precision));

	return 0;
}
