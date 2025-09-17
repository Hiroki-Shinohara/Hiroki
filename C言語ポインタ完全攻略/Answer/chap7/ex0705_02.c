#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MSG		"記憶域の確保に失敗しました。"

//*** 型定義 ***//

//*** 関数プロトタイプ宣言 ***//
static int strary_dup(const char* s[], char* d[], size_t n);
static void strary_print(const char* a[], size_t n);
static void strary_free(char* a[], size_t n);

//*** main関数 ***//
int main(int argc, char* argv[])
{
	size_t n = (size_t)argc;
	char** p = calloc(n, sizeof(char*));
	int i;

	if (!p)
	{
		puts(ERR_MSG);
		return 1;
	}

	for (i = 0; i < argc; i++)
		printf("argv[%d] = \"%s\"\n", i, argv[i]);

	if (strary_dup((const char**)argv, p, n) == 0)
		strary_print((const char**)p, n);

	strary_free(p, n);
	free(p);

	return 0;
}

//--- 文字列配列sを配列dに複製する ---//
static int strary_dup(const char* s[], char* d[], size_t n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		d[i] = malloc(strlen(s[i]) + 1);

		if (d[i] == NULL)
		{
			puts(ERR_MSG);
			for (size_t j = 0; j < i; j++)
				free(d[j]);
			return 1;
		}

		strcpy(d[i], s[i]);		// 文字列sをpにコピー
	}

	return 0;
}

//--- 文字列配列aを表示 ---//
static void strary_print(const char* a[], size_t n)
{
	for (int i = 0; i < n; i++)
	{
		printf("p[%d] = \"%s\"\n", i, a[i]);
	}
}

//--- メモリ解放 ---//
static void strary_free(char* a[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		free(a[i]);
}
