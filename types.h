#ifndef TYPES_H
#define TYPES_H
typedef enum
{	ENCRYPT,
	DECRYPT
}EncryptionMode;
typedef struct
{
	char input[100];
	char output[100];
	EncryptionMode mode;
}NoteInfo;
#endif
