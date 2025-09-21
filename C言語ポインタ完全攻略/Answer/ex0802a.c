#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH	10

//*** �^��` ***//

//*** �֐��v���g�^�C�v�錾 ***//
static int scmp(const void* x, const void* y);
static int pcmp(const void* x, const void* y);

//*** main�֐� ***//
int main(void)
{
	char s[][LENGTH] = { "LISP", "C++", "Ada", "Pascal", "Microsoft", "Linux", "OneNote" };
	char* p[] = { "LISP", "C++", "Ada", "Pascal", "Microsoft", "Linux", "OneNote" };
	int i;

	int ns, np;
	ns = np = sizeof(s) / sizeof(s[0]);

	qsort(s, ns, sizeof(char[LENGTH]), scmp);
	puts("�z��s�����\�[�g��");
	for (i = 0; i < ns; i++)
		printf("s[%d] = \"%s\"\n", i, s[i]);

	qsort(p, np, sizeof(char*), pcmp);
	puts("\n�z��p�����\�[�g��");
	for (i = 0; i < ns; i++)
		printf("p[%d] = \"%s\"\n", i, p[i]);

	return 0;
}

//--- �z��s�̔�r�֐� ---//
static int scmp(const void* x, const void* y)
{
	// qsort�֐��ɂ́uChar (*)[LENGTH]�v�^���n����Ă���̂�
	const char (*px)[LENGTH] = (const char (*)[LENGTH])x;
	const char (*py)[LENGTH] = (const char (*)[LENGTH])y;

	// strcmp�ɓn���͕̂�����̐擪�ւ̃|�C���^�iChar*�^�j
	return strcmp(*px, *py);
}

//--- �z��p�̔�r�֐� ---//
static int pcmp(const void* x, const void* y)
{
	// qsort�֐��ɂ́uChar**�v�^���n����Ă���̂�
	const char** px = (const char**)x;
	const char** py = (const char**)y;

	// strcmp�ɓn���͕̂�����̐擪�ւ̃|�C���^�iChar*�^�j
	return strcmp(*px, *py);
}
