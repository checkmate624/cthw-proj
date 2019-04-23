#include <stdio.h>
#include "api.h"

int main(int argc, char *argv[])
{
	CGI *cgi = NULL;

	if(argc < 2) {
		return 1;
	}

	cgi = ParseString(argv[1]);
	CleanCGI(cgi);

	return 0;
}