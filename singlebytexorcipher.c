#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

int isnotprintable(char x)
{
	char *notallowed = ")({}/<>+=*^%#~`#$";
	return ((!isprint(x) && x != '\n') || (strchr(notallowed, x) != NULL));
}

int singlebytexorcipher(char* input)
{
	int count[256] = {0};
	int i = 0, j = 0;
	int max = 0, maxindex = 0;
	int key = 0;
	int length = strlen(input);
	int av_arr[length/2];
	char *out = (char *) calloc(length/2, sizeof(char));


	if(input == NULL || out == NULL)
	{
		printf("NULL pointer check failed\n");
		return -1;
	}

	for (i = 0; i < length; i+=2)
	{
		av_arr[i/2] = hexchartoint(input[i]) * 16 +
			      hexchartoint(input[i+1]);
		count[av_arr[i/2]]++;
	}

	for(i = 0; i < 256; i++)
	{
		if(count[i] != 0 && count[i] > max)
		{
			max = count[i];
			maxindex = i;
		}
	}

	/* We could assume ' ' appears most number of times */
	// key = ' ' ^ maxindex;
	/* Here, we iterate over all possible characters */ 
	for(j = 0; j < 256; j++)
	{
		key = j; 
		int isstring = 1;
		for (i = 0; i < length/2; i++)
		{
			out[i] =  av_arr[i] ^ key;
			if(isnotprintable(out[i]))
			{
				isstring = 0;
				break;
			}
		}
		if(isstring)
		{
			printf("Key = %d\t", key);
			for(i = 0; i < length/2; i++)
			{
				printf("%c", out[i]);
			}
			printf("\n");
			break;
		}
	}

	return key;
}

