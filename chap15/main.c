#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank", "Mary", "John", "Lisa"
	};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	for (i = 0; i < count; i++) {
		printf("%s has been alive %d years \n", names[i], ages[i]);
	}

	printf("---\n");
		
	return 0;
}
