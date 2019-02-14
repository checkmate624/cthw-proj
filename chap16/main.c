#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char *name;
	int age;
	int height;
	int weight;
};

void Person_print(struct Person who)
{
	printf("%s is at memory location %p:\n", who.name, &who);
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}

int main()
{
	struct Person joe;
	joe.name = "Joe";
	joe.age = 32;
	joe.height =  64;
	joe.weight = 140;

	struct Person frank;
	frank.name = "Frank";
	frank.age = 20;
	frank.height =  72;
	frank.weight = 180;
	
	Person_print(joe);
	Person_print(frank);
}