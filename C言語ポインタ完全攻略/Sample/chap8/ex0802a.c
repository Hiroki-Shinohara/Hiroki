#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** 型定義 ***//

//*** 関数プロトタイプ宣言 ***//
static int cmp_int_debug(const void* a, const void* b);
static int cmp_str_debug(const void* a, const void* b);

//*** main関数 ***//
int main(void)
{
	//整数配列
	int arr[] = { 30, 10, 50, 20, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("=== 整数配列ソート ===\n");
	qsort(arr, n, sizeof(int), cmp_int_debug);

	printf("ソート後\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	// 文字列配列
	char* p[] = { "LISP", "C", "Ada", "Git", "Word", "Excel", "UTF-8" };
	int m = sizeof(p) / sizeof(p[0]);

	printf("=== 文字列ポインタ配列ソート ===\n");
	qsort(p, m, sizeof(char*), cmp_str_debug);

	printf("ソート後\n");
	for (int i = 0; i < n; i++)
		printf("%s ", p[i]);
	printf("\n");

	return 0;
}

//--- 比較関数（整数用） ---//
static int cmp_int_debug(const void* a, const void* b)
{
	const int* ia = (const int*)a;
	const int* ib = (const int*)b;

	printf("[整数比較] aアドレス=%p, bアドレス=%p, *a=%d, *b=%d\n",
		(void*)a, (void*)b, *ia, *ib);

	return *ia - *ib;
}

//--- 比較関数（文字列ポインタ用） ---//
static int cmp_str_debug(const void* a, const void* b)
{
	const char* sa = *(const char* const*)a;
	const char* sb = *(const char* const*)b;

	printf("[文字列比較] aアドレス=%p, bアドレス=%p, *a=%p, b=%p, sa=%s, sb=%s\n",
		a, b, *(const char* const*)a, *(const char* const*)b, sa, sb);

	return strcmp(sa, sb);
}