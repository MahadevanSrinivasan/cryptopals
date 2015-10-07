#include <stdio.h>
#include <string.h>
#include "defs.h"

int hamming(char *in1, char *in2, int len)
{
	int i = 0;
	//int len = strlen(in1);
	int distance = 0;
	for(i = 0; i < len; i++)
	{
		int xor = in1[i] ^ in2[i];
		while(xor != 0)
		{
			if((xor & 0x1) == 1)
				distance++;
			xor = xor >> 1;
		}
	}
	return distance;
}

