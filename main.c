#include<stdio.h>
#include<string.h>
#include "encrypt.h"  
void encryptFile(char input[], char output[]);
void decryptFile(char input[], char output[]);
int main(int argc, char*argv[])
{
	NoteInfo file;
	if(argc!=4)
	{
		printf("./tool -e input.txt encrypted.enc\n");
		printf("./tool -d encrypted.enc output.txt\n");
		return 1;
	}
	strcpy(file.input, argv[2]);
	strcpy(file.output, argv[3]);
	if(strcmp(argv[1],"-e")==0)
	{
		file.mode = ENCRYPT;
		encryptFile(file.input, file.output);
	}
	else if(strcmp(argv[1],"-d")==0)
		{
			file.mode = DECRYPT;
			decryptFile(file.input, file.output);
		}
	else
	{
		printf("Invalid Option\n");
	}
	return 0;
}
