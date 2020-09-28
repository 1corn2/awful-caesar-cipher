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
void cipherF(char *cipher,int *ciph)
{
	char c;
	printf("caesar:1 other:2\n");
	if ((c=getchar())=='1'){
		strcpy(cipher,"caesar");
		printf("key value:");
		scanf("%i",ciph);
	}
	while (getchar() != '\n');
	return;
}

//ciphering
void cipherer(char *text,int ciph,FILE *f)
{
	char c=0;
	FILE *f2;
	if((f2=fopen(strcat(text,"-s"),"w+"))==NULL)
		printf("error when opening ciphertext\n");
	while((c=fgetc(f))!=EOF){
		if(!isalpha(c)){
			putc(c,f2);
			continue;
		}
		printf("%i %i %c %i %c\n",ciph,c,c,tolower(c),tolower(c));
		fputc((((((tolower(c))-97) + ciph) % 26)+97), f2);
		printf("%i %i %i %c\n",ciph,(((tolower(c))-97) + ciph),((((tolower(c))-97) + ciph) % 26),(((((tolower(c))-97) + ciph) % 26)+97));
	}
	fclose(f2);
}


void main ()
{
	char *text,*cipher;
	int ciph;
	text=calloc(sizeof(char),32);
	cipher=calloc(sizeof(char),16);
	FILE *f;

	int c=0;
	while(1){
		printf("1. enter filename: %s\n",text);
		printf("2. enter cipher: %s\n",cipher);
		printf("3. run \n",text);

		c=getchar();
		switch (c){
		case '1':
			while (getchar() != '\n');
			f=textF(text);
			break;
		case '2':
			while (getchar() != '\n');
			cipherF(cipher,&ciph);
			break;
		case '3':
			while (getchar() != '\n');
			cipherer(text,ciph,f);
			return;
		default:
			while (getchar() != '\n');
			printf("invalid option\n\n");
			break;
		}
	}
	fclose(f);
}
