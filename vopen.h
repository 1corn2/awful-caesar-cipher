#include<unistd.h>
#include<string.h>

FILE *vopen(const char* filename,const char* mode)
{
	char *cwd;
	FILE *f;
	cwd = getcwd(NULL,100);
    strcat(cwd, "\\");
	strcat(cwd, filename);
	strcat(cwd, ".txt");
	return (f=fopen(cwd,mode));
	
}