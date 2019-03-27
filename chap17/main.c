#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *line_1;
	char *line_2;
	char *city;
	char state[2+1]; // room for 2-digit state plus null
	char zip[5+1]; // room for 5-digit zip pluls null
} Address;

static char *copy_string(char *s)
{
	if (s == NULL) {
		return strdup("");
	} else {
		return strdup(s);
	}
}

static void copy_into_string(char *destination, char *source, size_t size)
{
	char *write_this = NULL;

	if (source == NULL) {
		write_this = "";
	} else {
		write_this = source;
	}

	// fill the destination to be all zeros (null characters).
	// strncpy isn't guaranteed to write a null, so we'll do it ourselves.
	memset(destination, 0, size);
	strncpy(destination, write_this, size - 1);
}

static Address *make_address(char *line_1, char *line_2, char *city, char *state, char *zip)
{
	Address *a = NULL;

	a = calloc(1, sizeof(Address));
	if (a) {
		a->line_1 = copy_string(line_1);
		//FIX: changed from a->line_1 to a->line_2
		a->line_2 = copy_string(line_2);
		a->city = copy_string(city);
		copy_into_string(a->state, state, sizeof(a->state));
		copy_into_string(a->zip, zip, sizeof(a->zip));
	}

	return a;		
}


static void free_address(Address *a)
{
	free(a->line_1);
	free(a->line_2);
	free(a->city);
	free(a);
}

static void print_address(Address *a)
{
	printf("====\n");
	printf("Address Line 1: %s\n", a->line_1);
	printf("Address Line 2: %s\n", a->line_2);
	printf("City: %s\n", a->city);
	printf("State: %s\n", a->state);
	printf("Zip: %s\n", a->zip);
}

int main()
{
	Address *winter_home = NULL;
	Address *summer_home = NULL;

	winter_home = make_address("1234 Main St", "Apt 7", "Los Angeles", "CA", "90001");
	if (winter_home) {
		print_address(winter_home);
		free_address(winter_home);
	}

	summer_home = make_address("588 Lake Avenue", NULL, "Eagle River", "WI", "54521");
	if (summer_home) {
		print_address(summer_home);
		free_address(summer_home);
	}

	return 0;
}