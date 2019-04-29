#include <stdio.h>
#include "api.h"

int main(int argc, char *argv[])
{
	CGI *cgi = NULL;
	int i = 0;

	if(argc < 2) {
		printf("FAIL: Too few arguments passed.\n");
		return 1;
	}

	cgi = ParseString(argv[1]);
	int totalPairs = GetTotalPairs(cgi);
	
	for (i = 0; i < totalPairs; i++) {
		PrintPair(GetPairByNumber(cgi, i));
	}

	CleanCGI(cgi);

	return 0;
}