#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//opening and testing file
FILE *textF(char *text)
{
	char c;
	printf("insert filename:");
	scanf("%32s",text);
	while (getchar() != '\n');

	FILE *f;
	if((f=fopen(text,"r+"))==NULL)
		printf("unable to open file\n");
	else
		printf("file opened succesfully\n");
	return f;
}

//choosing a cipher
void cipherF(int *key)
{
	printf("key value:");
	scanf("%i",key);
	*key=(*key % 26);
	while (getchar() != '\n');
	return;
}
//ciphering
void cipherer();

void main ()
{
	char *text;
	int key;
	text=calloc(sizeof(char),32);
	FILE *f;

	int c=0;
	while(1){
		printf("[1.] enter filename: %s\n",text);
		printf("[2.] enterkey value: %i\n",key);
		printf("[3.] run \n",text);

		c=getchar();
		switch (c){
		case '1':
			while (getchar() != '\n');
			f=textF(text);
			break;
		case '2':
			while (getchar() != '\n');
			cipherF(&key);
			break;
		case '3':
			while (getchar() != '\n');
			cipherer(text,key,f);
			return;
		default:
			while (getchar() != '\n');
			printf("invalid option\n\n");
			break;
		}
	}
	fclose(f);
}
