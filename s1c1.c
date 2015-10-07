#include <stdio.h>
#include "defs.h"

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("Usage: ./s1_c1.out input_hex_string\n");
  }
  else
  {
    char *input = argv[1];
    rawtobase64(hextoraw(input));
  }
  return 0;
}
