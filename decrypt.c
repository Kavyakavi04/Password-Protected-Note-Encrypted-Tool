#include<stdio.h>
#include<string.h>
static unsigned int passwordHash(char password[])
{
	unsigned int hash = 53;
	int i = 0;
	while(password[i] != '\0')
	{
		hash = hash * 33 + (unsigned char)password[i];
		i++;
	}
	return hash;
}
void decryptFile(char input[], char output[])
{
	FILE *fin, *fout;
	char password[10];
	char ch, key;
	unsigned int storedHash;
	unsigned int enteredHash;
	printf("Enter Password:");
	scanf("%s", password);

	key=password[0];
	enteredHash = passwordHash(password);
	fin = fopen(input, "r");
	if(fin == NULL)
	{
		printf("Encrypted file not open:\n");
		return;
	}
	/*read the hash saved by encrypt.c */
	if(fread(&storedHash, sizeof(storedHash), 1, fin)!=1)
	{
		printf("Invalid encrypted file\n");
		fclose(fin);
		return;
	}
	if(enteredHash != storedHash)
	{
		printf("Wrong password\n");
		fclose(fin);
		return;
	}
	fout = fopen(output,"w");
	if(fout==NULL)
	{
		printf("cannot create output file\n");
		fclose(fin);
		return;
	}
	while((ch = fgetc(fin)) != EOF)
	{
		fputc(ch^key, fout);
	}
	fclose(fin);
	fclose(fout);
	printf("Decryption Successful\n");
}
