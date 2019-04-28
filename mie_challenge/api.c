#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "api.h"

struct _pair {
	char *key;
	char *value;
};

struct _cgi {
	Pair **allPairs;
	int totalPairs;
};

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

int GetTotalPairs(CGI *cgi)
{
	return cgi->totalPairs;
}

Pair *GetPairByNumber(CGI *cgi, int id)
{
	return cgi->allPairs[id];
}

char *GetValueByKey(CGI *cgi, char *key)
{
	int i = 0;
	
	for(i = 0; i < cgi->totalPairs; i++) {
		if(strcmp(cgi->allPairs[i]->key, key) == 0) { 
			return cgi->allPairs[i]->value;
		}
	}

	printf("Key not stored\n");
	return NULL;
}

int HexToDec(char input)
{
	if(isdigit(input)) {
		return input - '0';
	} else {
		if(isupper(input)) {
			return input - 'A' + 10;
		} else {
			return input - 'a' + 10;
		}
	}
}

char HexToChar(char input[3])
{
	char decodedChar = '\0';
	
	decodedChar += HexToDec(input[2]);
	decodedChar += HexToDec(input[1]) * 16;
	
	return decodedChar;
}

static int ParsePair(CGI *cgi, char *input, int startingPos)
{
	Pair *pair = Pair_create(); 
	int i = startingPos;
	int stringLength = 0;

	cgi->allPairs = realloc(cgi->allPairs, (sizeof(Pair *) * (cgi->totalPairs + 1)));
	cgi->allPairs[cgi->totalPairs] = pair;
	cgi->totalPairs += 1;
	
	// Parse key
	while (input[i] != '=') {
		pair->key = realloc(pair->key, stringLength + sizeof(char) + 1);

		if (input[i] == '%') {
			char hex[3];
			sprintf(hex, "%c%c%c", input[i], input[i + 1], input[i + 2]);
			pair->key[stringLength] = HexToChar(hex);
			i += 3;
		} else if (input[i] == '+') {
			pair->key[stringLength] = ' ';
			i++;
		} else {
			pair->key[stringLength] = input[i];
			i++;
		}

		stringLength++;
	}

	pair->key[stringLength] = '\0';
	i++;
	stringLength = 0;

	// Parse value
	while (input[i] != '&' && input[i] != '\0') {
		pair->value = realloc(pair->value, stringLength + sizeof(char) + 1);

		if (input[i] == '%') {
			char hex[3];
			sprintf(hex, "%c%c%c", input[i], input[i + 1], input[i + 2]);
			pair->value[stringLength] = HexToChar(hex);
			i += 3;
		} else if (input[i] == '+') {
			pair->value[stringLength] = ' ';
			i++;
		} else {
			pair->value[stringLength] = input[i];
			i++;
		}

		stringLength++;
	}

	pair->value[stringLength] = '\0';

	return i;
}

CGI *ParseString(char *input)
{
	if(input == NULL) {
		return NULL;
	}

	int inputLength = strlen(input);
	CGI *cgi = CGI_create();

	int i = 0;
	for(i = 0; i < inputLength; i++) {
		i = ParsePair(cgi, input, i);
	}

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
	for(i = 0; i < cgi->totalPairs; i++) {
		CleanPair(cgi->allPairs[i]);
	}
	free(cgi->allPairs);
	free(cgi);
}