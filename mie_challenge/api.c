#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "api.h"

static Pair *Pair_create()
{
	Pair *NewPair = calloc(1, sizeof(Pair));
	return NewPair;
}

static CGI *CGI_create()
{
	CGI *cgi = calloc(1, sizeof(CGI));
	return cgi;
}

void PrintPair(Pair *pair)
{
	printf("Key: %s\n", pair->key);
	printf("Value: %s\n\n", pair->value);
}

char DecodeSpecialCharactor(char *charactor);

static void ParsePair(CGI *cgi, char *input, int startingPos)
{
	Pair *pair = Pair_create(); 

	cgi->allPairs = realloc(cgi->allPairs, (sizeof(Pair *) * (cgi->pairCount + 1)));
	cgi->allPairs[cgi->pairCount] = pair;
	cgi->pairCount += 1;

	pair->key = strdup("a");
	pair->value = strdup("b");

	PrintPair(pair);
}

CGI *ParseString(char *input)
{
	if(input == NULL) {
		return NULL;
	}
	
	CGI *cgi = CGI_create();
	ParsePair(cgi, input, 0);

	return cgi;
}

void CleanPair(Pair *pair)
{
	free(pair->key);
	free(pair->value);
	free(pair);
}

void CleanCGI(CGI *cgi)
{
	int i = 0;
	for(i = 0; i < cgi->pairCount; i++) {
		CleanPair(cgi->allPairs[i]);
		printf("%d\n", i);
	}
	free(cgi->allPairs);
	free(cgi);
}