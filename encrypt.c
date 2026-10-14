#include<stdio.h>
static unsigned int passwordHash(char password[])
{
	unsigned int hash =53;
	int i=0;
	while(password[i] != '\0')
	{
		hash = hash * 33 + (unsigned char)password[i];
		i++;
	}
	return hash;
}
void encryptFile(char input[], char output[])
{
	FILE *fin, *fout;
	char password[10];
	char ch, key;
	unsigned int hash;
	printf("Enter Password:");
	scanf("%s",password);
	key = password[0];
	hash = passwordHash(password);
	fin = fopen(input,"r");
	if(fin==NULL)
	{
		printf("Input file not found\n");
		return;
	}
	fout = fopen(output,"wb");
	if(fout==NULL)
	{
		printf("cannot create output file:\n");
		fclose(fin);
		return;
	}
	/* save a hash value, not the actual password */
	fwrite(&hash, sizeof(hash), 1, fout);
	while((ch = fgetc(fin)) != EOF)
	{
		fputc(ch^key, fout);
	}
	fclose(fin);
	fclose(fout);
	printf("Encryption successful\n");
}
