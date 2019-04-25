#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	printf("Value: %s\n", pair->value);
}

char HexToChar(char input[3])
{
	char decodedChar = '\0';
	if(isdigit(input[2])) {
		decodedChar += input[2] - '0';
	} else {
		decodedChar += input[2] - 'a' + 10;
	}
	if(isdigit(input[1])) {
		decodedChar += (input[1] - '0') * 16;
	} else {
		decodedChar += (input[1] - 'a' + 10) * 16;
	}
	
	return decodedChar;
}

static void ParsePair(CGI *cgi, char *input, int startingPos)
{
	Pair *pair = Pair_create(); 
	int i = startingPos;
	int stringLength = 0;

	cgi->allPairs = realloc(cgi->allPairs, (sizeof(Pair *) * (cgi->pairCount + 1)));
	cgi->allPairs[cgi->pairCount] = pair;
	cgi->pairCount += 1;
	
	// Parse key
	while(input[i] != '=') {
		pair->key = realloc(pair->key, stringLength + sizeof(char) + 1);
		pair->key[i] = input[stringLength];
		i++; stringLength++;
	}

	pair->key[stringLength] = '\0';
	i++;
	stringLength = 0;

	// Parse value
	while(input[i] != '&' && input[i] != '\0') {
		pair->value = realloc(pair->value, stringLength + sizeof(char) + 1);
		pair->value[stringLength] = input[i];
		i++; stringLength++;
	}

	pair->value[stringLength] = '\0';
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
	}
	free(cgi->allPairs);
	free(cgi);
}