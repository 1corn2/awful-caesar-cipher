#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//ciphering

void cipherer(char *text,int key,FILE *f)
{
	int c=0;
	FILE *f2;
	if((f2=fopen(strcat(text,"-s"),"w+"))==NULL)
		printf("error when opening ciphertext\n");

  while((c=fgetc(f))!=EOF){
  	if(!isalpha(c)){
  		fputc(c,f2);
  		continue;
  	}
  	fputc((((((tolower(c))-97) + key) % 26)+97), f2);
	}

  fclose(f2);
}
