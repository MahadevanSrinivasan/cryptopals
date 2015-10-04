#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		char *input = argv[1]; 
		char *key = "ICE";
		int i = 0, l = strlen(input), kl = strlen(key);
		int k = 0;
		for(i = 0; i < l; i++)
		{	
			int xor = input[i] ^ key[k];
			if(xor <= 0xF) 
				printf("0");
			printf("%x", xor); 
			k = (k + 1) % kl;
		}
		printf("\n");
	}
	else
	{
		printf("Usage: ./s1c5.out str\n");
	}
	return 0;
}
