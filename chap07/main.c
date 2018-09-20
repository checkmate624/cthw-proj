#include <stdio.h>
#include <inttypes.h>

int main()
{
	int i = 0;
	
	uint8_t integer = 0;
	float floatingPoint = 0;
	double decimal = 0;
	
	while(i < 10)
	{
		i ++;
		floatingPoint++;
		decimal++;
		
		printf("float: %e, double: %f\n", floatingPoint, decimal);
	}

	integer = 255;
	printf("\nInt: %i\n", integer);
	integer++;
	printf("Int: %i\n", integer);
}
