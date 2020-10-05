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
void cipherF(char *cipher,char *ciph,int *key1,int *key2)
{
	char c;
	printf("caesar:1 other?:2\n");
	if ((c=getchar())=='1'){
		*ciph=c;
		strcpy(cipher,"caesar");
		printf("key1 value:");
		scanf("%i",key1);
		*key1=(*key1 % 26);
	}
	else if((c=getchar())=='2'){
		strcpy(cipher,"other?");
		printf("key1 value:");
		scanf("%i",key1);
		*key1=(*key1 % 26);
		}



	while (getchar() != '\n');
	return;
}
//ciphering
void cipherer();

void main ()
{
	char *text,*cipher,ciph;
	int key1,key2;
	text=calloc(sizeof(char),32);
	cipher=calloc(sizeof(char),16);
	FILE *f;

	int c=0;
	while(1){
		printf("1. enter filename: %s\n",text);
		printf("2. enter cipher: %s\n",cipher);
		printf("3. run \n");

		c=getchar();
		switch (c){
		case '1':
			while (getchar() != '\n');
			f=textF(text);
			break;
		case '2':
			while (getchar() != '\n');
			cipherF(cipher,&ciph,&key1,&key2);
			break;
		case '3':
			while (getchar() != '\n');
			cipherer(text,ciph,key1,key2,f);
			return;
		default:
			while (getchar() != '\n');
			printf("invalid option\n\n");
			break;
		}
	}
	fclose(f);
}
