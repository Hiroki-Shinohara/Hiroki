#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** �^��` ***//

//*** �֐��v���g�^�C�v�錾 ***//
static int cmp_int_debug(const void* a, const void* b);
static int cmp_str_debug(const void* a, const void* b);

//*** main�֐� ***//
int main(void)
{
	//�����z��
	int arr[] = { 30, 10, 50, 20, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("=== �����z��\�[�g ===\n");
	qsort(arr, n, sizeof(int), cmp_int_debug);

	printf("�\�[�g��\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	// ������z��
	char* p[] = { "LISP", "C", "Ada", "Git", "Word", "Excel", "UTF-8" };
	int m = sizeof(p) / sizeof(p[0]);

	printf("=== ������|�C���^�z��\�[�g ===\n");
	qsort(p, m, sizeof(char*), cmp_str_debug);

	printf("�\�[�g��\n");
	for (int i = 0; i < n; i++)
		printf("%s ", p[i]);
	printf("\n");

	return 0;
}

//--- ��r�֐��i�����p�j ---//
static int cmp_int_debug(const void* a, const void* b)
{
	const int* ia = (const int*)a;
	const int* ib = (const int*)b;

	printf("[������r] a�A�h���X=%p, b�A�h���X=%p, *a=%d, *b=%d\n",
		(void*)a, (void*)b, *ia, *ib);

	return *ia - *ib;
}

//--- ��r�֐��i������|�C���^�p�j ---//
static int cmp_str_debug(const void* a, const void* b)
{
	const char* sa = *(const char* const*)a;
	const char* sb = *(const char* const*)b;

	printf("[�������r] a�A�h���X=%p, b�A�h���X=%p, *a=%p, b=%p, sa=%s, sb=%s\n",
		a, b, *(const char* const*)a, *(const char* const*)b, sa, sb);

	return strcmp(sa, sb);
}