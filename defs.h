#ifndef DEFS
#define DEFS

int hexchartoint(char hex);
char* hextobase64(char *input);
char *fixedxor(char *in1, char *in2);
int singlebytexorcipher(char* input, int length);
int hamming(char *in1, char *in2, int len);
char *hextoraw(char *input);
char *rawtobase64(char *input, int length);
char *rawtohex(char *input, int length);
char *base64toraw(char *input);

#endif /* DEFS */
