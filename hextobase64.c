#include <stdio.h>
#include <stdlib.h> /* Needed for calloc() */
#include <string.h>
#include "defs.h"

char *hextobase64(char *input)
{
  int i, j, k = 0;
  char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  int length = strlen(input);
  char *output = (char *) calloc(length*4/3, sizeof(char));

  if(length % 6 != 0)
  {
    printf("Need to do some padding to input, not supported yet\n");
  }
  else
  {
    for(i = 0; i < length; i=i+6)
    {
      long temp = hexchartoint(input[i])*16 + hexchartoint(input[i+1]);
      temp = temp<<8 | (hexchartoint(input[i+2])*16 + hexchartoint(input[i+3]));
      temp = temp<<8 | (hexchartoint(input[i+4])*16 + hexchartoint(input[i+5]));

      for(j = 3; j >= 0; j--)
      {
        output[k++] = map[temp>>j*6&0x3F];
      }
    }
  }
  output[k] = '\0';
  return output;
}

