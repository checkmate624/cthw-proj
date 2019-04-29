#ifndef API_h_
#define API_h_

#include <stdio.h>
#include <string.h>

typedef struct _pair Pair;

typedef struct _cgi CGI;

// Returns the total numbers of pairs stored in the cgi struct
int GetTotalPairs(CGI *cgi);

// Frees all allocated memory
void CleanCGI(CGI *cgi);

// Prints the key and the value of a pair struct
void PrintPair(Pair *pair);

// Returns the value of a stored key
const char *GetValueByKey(CGI *cgi, char *key);

// Takes in a cgi encoded string and returns a struct with all the pairs found stored inside
CGI *ParseString(char *input);

// Returns the value of a stored key, retrieved by the id in the array 
Pair *GetPairByNumber(CGI *cgi, int id);

#endif