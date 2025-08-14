#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH	128
#define ERR_MSG	"�L����̊m�ۂɎ��s���܂����B"

//*** �֐��v���g�^�C�v�錾 ***//
static char* str_dup(const char* s);
static void copy_args(const char* s[], char* p[], int n);
static void print_str(const char* p[], int n);

//*** main�֐� ***//
int main(int argc, char* argv[])
{
	char** p;

	p = calloc(argc, sizeof(char*));

	if (p == NULL)
		puts(ERR_MSG);
	else
	{
		int i;

		for (i = 0; i < argc; i++)
			p[i] = NULL;

		copy_args(argv, p, argc);

		print_str(p, argc);

	Free:
		for (i = 0; i < argc; i++)
			free(p[i]);
	}

	free(p);

	puts("���s����");

	return 0;
}

//--- ������s���R�s�[ ---//
static char* str_dup(const char* s)
{
	char* p = malloc(strlen(s) + 1);
	return (p == NULL) ? NULL : strcpy(p, s);
}

//--- ������s�𕶎���p�ɃR�s�[ ---//
static void copy_args(const char* s[], char* p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((p[i] = str_dup(s[i])) == NULL)
		{
			puts(ERR_MSG);
			return;
		}
	}
}

//--- �������\�� ---//
static void print_str(const char* p[], int n)
{
	for (int i = 0; i < n; i++)
		printf("p[%d] = %s\n", i, p[i]);
}