#include <stdio.h>
#include <stdlib.h> /* Needed for calloc() */
#include <string.h>
#include <ctype.h>
#include "defs.h"


int hexchartoint(char hex)
{
  hex = tolower((int)hex);
  if(hex >= '0' && hex <= '9')
    return hex - '0';
  else if(hex >= 'a' && hex <= 'f')
    return hex - 'a' + 10;

  printf("Not sure what to do with this input: %x\n", hex);
  return 0;
}

char *base64toraw(char *input)
{
	int i, j, k = 0;
	char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int length = strlen(input);
	char *output = (char *) calloc(length*3/4, sizeof(char));

	for(i = 0; i < length; i+=4)
	{
		int temp = ((int) (strchr(map, input[i]) - map) << 18) |
			   ((int) (strchr(map, input[i+1]) - map) << 12) |
			   ((int) (strchr(map, input[i+2]) - map) << 6) |
			   ((int) (strchr(map, input[i+3]) - map));
		for(j = 2; j >= 0; j--)
		{
			output[k++] = temp>>j*8&0xFF;
		}

	}
	output[k] = '\0';
	return output;
}


char *hextoraw(char *input)
{
	int i, j, k = 0;
	int length = strlen(input);
	char *output = (char *) calloc(length/2, sizeof(char));

	if(length % 2 != 0)
	{
		printf("Need to do some padding to input, not supported yet\n");
	}
	else
	{
		for(i = 0; i < length; i=i+2)
			output[k++] = hexchartoint(input[i])*16 + hexchartoint(input[i+1]);
	}
	output[k] = '\0';
	return output;
}

char *rawtobase64(char *input, int length)
{
	int i = 0, j = 0, k = 0;
  	char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char *out = calloc(length*4/3, sizeof(char));
	
	for(i = 0; i < length; i+=3)
	{
		int temp = (input[i] << 16) | (input[i+1] << 8) | (input[i+2]);
		for(j = 3; j >= 0; j--)
		{
			out[k++] = map[temp>>j*6&0x3F];
		}
	}
	out[k] = '\0';
	return out;
}

char *rawtohex(char *input, int length)
{
	int i = 0, k = 0;
	char *out = (char *) calloc(length*2, sizeof(char));

	for(i = 0; i < length; i++)
	{
		if(input[i] < 0xF) {
			out[k++] = '0';
		}
		sprintf(&out[k++], "%x", input[i]); 
		if(input[i] > 0xF)
			k++;
	}
	out[k] = '\0';
	return out;
}

