#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

#define MINKEYSIZE 2
#define MAXKEYSIZE 40

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		FILE *fp;
		char origbuffer[64*60];
		double distances[MAXKEYSIZE+1] = {10000.0};
		int i = 0, j = 0, k = 0;
		int top4[4];
		char *buffer;
		char *key;
		int success = 0;
		int l;
		char *tempbuffer[MAXKEYSIZE];
		char *ptr[MAXKEYSIZE];

		fp = fopen(argv[1], "r");
		fgets(origbuffer, 100, fp);
		while(fgets(&origbuffer[strlen(origbuffer)-1], 100, fp));
		origbuffer[strlen(origbuffer)-1] = '\0';

		char *temp = base64toraw(origbuffer);
		int length = strlen(origbuffer)*3/4;
		buffer = temp;

		for(i = MINKEYSIZE; i <= MAXKEYSIZE; i++)
		{
			for(j = 0; j < 4; j++)
			{
				char *in1 = &buffer[0+(j*i)];
				char *in2 = &buffer[i+(j*i)];
				distances[i] += (double) hamming(in1, in2, i)/i;
			}
			distances[i] = distances[i]/4.0;
		}

		for(i = 0; i < 4; i++)
		{
			int min = 0;
			for(j = MINKEYSIZE; j <= MAXKEYSIZE; j++)
			{
				if(distances[j] < distances[min])
					min = j;
			}
			top4[i] = min;
			distances[min] = 10000;
		}
		
		key = calloc(MAXKEYSIZE+1, sizeof(char));
		for(l = 0; l < 4; l++)
		{
			success = 1;
			k = top4[l];
			printf("Trying key size: %d\n", k);

			for(j = 0; j < k; j++)
			{
				tempbuffer[j] = (char *) calloc(1+length/k, sizeof(char));
				ptr[j] = tempbuffer[j];
			}

			for(i = 0; i < length; i++)
			{
				*ptr[i%k] = buffer[i];
				ptr[i%k]++;
			}
			for(j = 0; j < k; j++)
			{
				*ptr[j] = '\0';
				int temp = singlebytexorcipher(tempbuffer[j], length/k);
				if(temp > 255 || temp < 0)
				{
					success = 0;
					break;
				}
				else
				{
					key[j] = (char) temp;
				}
			}

			key[j] = '\0';
			//for(j = 0; j < k; j++)
			//{
			//	ptr[j] = NULL;
			//	free(tempbuffer[j]);
			//	tempbuffer[j] = NULL;
			//}
			//free(tempbuffer);
			/* We are done */
			if(success)
				break;
		}
		i = 0;
		printf("Key = %s\n", key);
		char *temp1 = temp;
		for(k = 0; k < length; k++)
		{
			printf("%c", temp1[k] ^ key[i]);
			i = (i + 1) % strlen(key);
		}
		printf("\n");
	}
	else
	{
		printf("Usage: ./s1c6.out filename\n");
	}
	return 0;
}
