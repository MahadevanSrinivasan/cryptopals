#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "defs.h"

int isnotprintable(char x)
{
	char *notallowed = ")({}/<>+=*^%#~`#$|@_;:\\&[]";
	return ((!isprint(x) && x != '\n') || (strchr(notallowed, x) != NULL));
}

int singlebytexorcipher(char* input, int length)
{
	int i = 0, j = 0;
	/* A correct key is between 0 and 255, return -1 otherwise */
	int key = -1;
	char *out = calloc(1+length, sizeof(char));

	if(input == NULL || out == NULL)
	{
		printf("NULL pointer check failed\n");
		return key;
	}

	/* Here, we iterate over all possible characters */
	for(j = 0; j < 256; j++)
	{
		int isstring = 1;
		for (i = 0; i < length; i++)
		{
			out[i] =  input[i] ^ j;
			if(isnotprintable(out[i]))
			{
				isstring = 0;
				break;
			}
		}
		if(isstring)
		{
			key = j;
			break;
		}
	}
	free(out);

	return key;
}
