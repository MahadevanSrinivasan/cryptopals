#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		return 0;
	}
		
	FILE *fp;
	char input[100];
	fp = fopen(argv[1], "r");
	while(fgets(input, 100, fp) != NULL)
	{
		input[strlen(input)-1] = '\0';
		printf("%s", input);
	}
	printf("\n");
	fclose(fp);
}

