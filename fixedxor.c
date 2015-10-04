#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* Needed for calloc() */
#include "defs.h"

char *fixedxor(char *in1, char *in2)
{
	int l = strlen(in1);
	int i = 0;
	char map[] = "0123456789abcdef";
	if(l != strlen(in2))
	{
      		printf("Input lengths need to be the same\n");
		return NULL;
	}
	char *out = (char *) calloc(l, sizeof(char));
	int k = 0;

	for(i = 0; i < l; i++)
	{
		out[k++] = map[hexchartoint(in1[i]) ^ hexchartoint(in2[i])];
	}
	out[k] = '\0';
	return out;
}

