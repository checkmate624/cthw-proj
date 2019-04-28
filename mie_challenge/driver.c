#include <stdio.h>
#include "api.h"

int main(int argc, char *argv[])
{
	CGI *cgi = NULL;

	if(argc < 2) {
		printf("FAIL: Too few arguments passed.\n");
		return 1;
	}

	cgi = ParseString(argv[1]);

	int i = 0;
	for (i = 0; i < GetTotalPairs(cgi); i++) {
		PrintPair(GetPairByNumber(cgi, i));
	}

	CleanCGI(cgi);

	return 0;
}