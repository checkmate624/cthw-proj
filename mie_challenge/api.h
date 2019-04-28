#ifndef API_h_
#define API_h_

#include <stdio.h>
#include <string.h>

typedef struct _pair Pair;

typedef struct _cgi CGI;

int GetTotalPairs(CGI *cgi);

void CleanCGI(CGI *cgi);

void PrintPair(Pair *pair);

char *GetValueByKey(CGI *cgi, char *key);

CGI *ParseString(char *input);

Pair *GetPairByNumber(CGI *cgi, int id);

#endif