#include <stdio.h>

void print_address_and_value(int *var)
{
	printf("%p:%d\n", &*var, *var);
}

int main()
{
	int var = 10;
	int array[] = { 1, 2, 3 };
	int var2 = 20;
	int i = 0;
	
	//Pass the address of the variable
	print_address_and_value(&var);

	//Print every item in the array
	for(i = 0; i <= 2; i++)
	{
		print_address_and_value(&array[i]);
	}

	print_address_and_value(&var2);
	
	return 0;
}

