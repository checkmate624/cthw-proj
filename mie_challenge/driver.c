#include <stdio.h>
#include "api.h"

int main(int argc, char *argv[])
{
	CGI *cgi = NULL;

	if(argc < 2) {
		printf("FAIL: Too few arguments passed.\n");
		return 1;
	}

	printf("%c\n", HexToChar("%6a"));

	/*cgi = ParseString(argv[1]);
	CleanCGI(cgi);*/

	return 0;
}