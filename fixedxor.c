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

	char *in1raw = hextoraw(in1);
	char *in2raw = hextoraw(in2);
	char *out = (char *) calloc(l/2, sizeof(char));

	for(i = 0; i < l/2; i++)
		out[i] = in1raw[i] ^ in2raw[i];
	out[i] = '\0';
	rawtohex(out);
	free(in1raw);
	free(in2raw);
	return out;
}

