#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH	10

//*** 型定義 ***//

//*** 関数プロトタイプ宣言 ***//
static int scmp(const void* x, const void* y);
static int pcmp(const void* x, const void* y);

//*** main関数 ***//
int main(void)
{
	char s[][LENGTH] = { "LISP", "C++", "Ada", "Pascal", "Microsoft", "Linux", "OneNote" };
	char* p[] = { "LISP", "C++", "Ada", "Pascal", "Microsoft", "Linux", "OneNote" };
	int i;

	int ns, np;
	ns = np = sizeof(s) / sizeof(s[0]);

	qsort(s, ns, sizeof(char[LENGTH]), scmp);
	puts("配列s昇順ソート後");
	for (i = 0; i < ns; i++)
		printf("s[%d] = \"%s\"\n", i, s[i]);

	qsort(p, np, sizeof(char*), pcmp);
	puts("\n配列p昇順ソート後");
	for (i = 0; i < ns; i++)
		printf("p[%d] = \"%s\"\n", i, p[i]);

	return 0;
}

//--- 配列sの比較関数 ---//
static int scmp(const void* x, const void* y)
{
	// qsort関数には「Char (*)[LENGTH]」型が渡されているので
	const char (*px)[LENGTH] = (const char (*)[LENGTH])x;
	const char (*py)[LENGTH] = (const char (*)[LENGTH])y;

	// strcmpに渡すのは文字列の先頭へのポインタ（Char*型）
	return strcmp(*px, *py);
}

//--- 配列pの比較関数 ---//
static int pcmp(const void* x, const void* y)
{
	// qsort関数には「Char**」型が渡されているので
	const char** px = (const char**)x;
	const char** py = (const char**)y;

	// strcmpに渡すのは文字列の先頭へのポインタ（Char*型）
	return strcmp(*px, *py);
}
