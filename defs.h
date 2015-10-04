#ifndef DEFS
#define DEFS

int hexchartoint(char hex);
char* hextobase64(char *input);
char *fixedxor(char *in1, char *in2);
int singlebytexorcipher(char* input);
int hamming(char *in1, char *in2);

#endif /* DEFS */
