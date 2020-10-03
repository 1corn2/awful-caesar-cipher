#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//ciphering

void cipherer(char *text,char ciph,int key1,int key2,FILE *f)
{
	int c=0;
	FILE *f2;
	if((f2=fopen(strcat(text,"-s"),"w+"))==NULL)
		printf("error when opening ciphertext\n");

  if (ciph=='1'){
  	while((c=fgetc(f))!=EOF){
  		if(!isalpha(c)){
  			fputc(c,f2);
  			continue;
  		}
  		fputc((((((tolower(c))-97) + key1) % 26)+97), f2);
  	}
  }
  else if (ciph=='2'){
    printf("unsupported right now :-( \n");
  }

  fclose(f2);
}
