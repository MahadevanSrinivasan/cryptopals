#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		char *input = argv[1];
		char *key = "ICE";
		int i = 0, l = strlen(input), kl = strlen(key);
		int k = 0, j = 0;
		char *rawbuffer = (char *) calloc(l, sizeof(char));
		for(i = 0; i < l; i++)
		{
			int xor = input[i] ^ key[k];
			rawbuffer[j++] = (char) xor;
			k = (k + 1) % kl;
		}
		printf("rawtohex: %s\n", rawtohex(rawbuffer, l));
		printf("rawtobase64: %s\n", rawtobase64(rawbuffer, l));
	}
	else
	{
		printf("Usage: ./s1c5.out str\n");
	}
	return 0;
}
