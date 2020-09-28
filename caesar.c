#include <stdio.h>
#include <stdlib.h>
#include "vopen.h"


//otevirani a testovani souboru na sifru
FILE *souborf(char *soubor)
{
	char c;
	printf("\n \n nacitani souboru:\n");
	scanf("%32s",soubor);
	while (getchar() != '\n');

	FILE *f;
	if((f=vopen(soubor,"r"))==NULL)
		printf("soubor se nepovedlo otevrit\n");
	else
		printf("soubor byl uspesne nacten\n");
	return f;
}

//vybirani sifry
void sifraf(char *sifra,int *sifr)
{
	char c;
	printf("cesar:1 jina:2\n");
	if ((c=getchar())=='1'){
		strcpy(sifra,"cesar");
		printf("klic:");
		scanf("%i",sifr);
	}
	while (getchar() != '\n');
	return;
}

//samotne sifrovcani
void sifrovac(char *soubor,int sifr,FILE *f)
{
	char c=0;
	FILE *f2;
	if((f2=vopen(strcat(soubor,"-s"),"w+"))==NULL)
		printf("chyba pri vytvareni souboru");
	while((c=fgetc(f))!=EOF){
		if(c==' '){
			putc(' ',f2);
			continue;
		}
		//printf("X: %c %i\n",c,c);
		fputc(((c-97 + sifr) % 26)+97, f2);
		//printf("Y: %c %i\n",(((c-97 + sifr) % 26)+97),(((c-97 + sifr) % 26)+97));
	}
	fclose(f2);
}


void main ()
{
	char *soubor,*sifra;
	int sifr;
	soubor=calloc(sizeof(char),32);
	sifra=calloc(sizeof(char),16);
	FILE *f;

	int c=0;
	while(1){
		printf("1. zadej soubor: %s\n",soubor);
		printf("2. zadej sifru: %s\n",sifra);
		printf("3. spustit \n",soubor);

		c=getchar();
		switch (c){
		case '1':
			getchar();
			f=souborf(soubor);
			break;
		case '2':
			getchar();
			sifraf(sifra,&sifr);
			break;
		case '3':
			getchar();
			sifrovac(soubor,sifr,f);
			return;
		default:
			printf("neplatna moznost\n\n");
			break;
		}
	}
	fclose(f);
}
