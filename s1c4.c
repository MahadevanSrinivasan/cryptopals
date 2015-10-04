#include <stdio.h>
#include <string.h>
#include "defs.h"

int main(int argc, char* argv[])
{
	if(argc == 2)
	{
		FILE *fp;
		char input[100];
		fp = fopen(argv[1], "r");

		while(fgets(input, 100, fp) != NULL)
		{
			input[strlen(input)-1] = '\0';
			singlebytexorcipher(input);
		}

		fclose(fp);
	}
	else
	{
		printf("Usage: ./s1c4.out filename\n");
	}

	return 0;
}
