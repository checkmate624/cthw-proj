#ifndef API_h_
#define API_h_

#include <stdio.h>
#include <string.h>

typedef struct {
	char *key;
	char *value;
} Pair;

typedef struct {
	Pair **allPairs;
	int pairCount;
} CGI;

CGI *ParseString(char *input);

void CleanCGI(CGI *cgi);

#endif