#include <stdio.h>
#include "defs.h"

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		char *in1 = argv[1];
		char *in2 = argv[2]; 
		printf("Hamming distance = %d\n", hamming(in1, in2));
	}
	else
	{
		printf("Usage: ./s1c5.out str1 str2\n");
	}
	return 0;
}
