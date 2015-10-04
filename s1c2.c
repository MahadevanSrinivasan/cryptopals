#include <stdio.h>
#include "defs.h"

int main(int argc, char* argv[])
{
	if(argc != 3)
		printf("Usage: ./s1c2.out input_hex_string input_hex_string_2\n");
	else
		printf("%s\n", fixedxor(argv[1], argv[2]));
	return 0;
}
