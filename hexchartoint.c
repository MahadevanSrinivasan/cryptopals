#include <stdio.h>
#include <ctype.h>
#include "defs.h"

int hexchartoint(char hex)
{
  hex = tolower((int)hex);
  if(hex >= '0' && hex <= '9')
    return hex - '0';
  else if(hex >= 'a' && hex <= 'f')
    return hex - 'a' + 10;

  printf("Not sure what to do with this input: %c\n", hex);
  return 0;
}
