#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"

int main(int argc, char *argv[])
{
	int key;

	if(argc == 2)
	{
		singlebytexorcipher(argv[1]);
	}
	else
	{
		printf("Usage: ./s1c3.out input_hex_string\n");
	}
	return 0;
}
