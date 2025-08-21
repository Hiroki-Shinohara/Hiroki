#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH	20

//*** 型定義 ***//

//*** 関数プロトタイプ宣言 ***//
static void memswap(void* x, void* y, size_t n);
static void quicksort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
static int int_cmp(const void* a, const void* b);

//*** main関数 ***//
int main(void)
{
	int i;
	int a[LENGTH] = { 0 };
	int na = sizeof(a) / sizeof(a[0]);

	srand(time(NULL));

	for (i = 0; i < na; i++)
	{
		a[i] = rand() % 101;
		printf("a[%2d] = %3d\n", i, a[i]);
	}

	quicksort(a, na, sizeof(int), int_cmp);

	puts("\nソート後");
	for (i = 0; i < na; i++)
	{
		printf("a[%2d] = %3d\n", i, a[i]);
	}

	return 0;
}

//--- x、yの指すnバイトの領域を交換 ---//
static void memswap(void* x, void* y, size_t n)
{
	unsigned char* a = (unsigned char*)x;
	unsigned char* b = (unsigned char*)y;

	for (; n--; a++, b++)
	{
		unsigned char c = *a;
		*a = *b;
		*b = c;
	}
}

//--- 汎用クイックソート ---//
static void quicksort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	if (nmemb > 0)
	{
		size_t pl = 0;					// 左カーソル
		size_t pr = nmemb - 1;			// 右カーソル
		size_t pv = nmemb;				// 枢軸
		size_t pt = (pl + pr) / 2;		// 枢軸の更新値
		char* v = (char*)base;			// 戦闘要素へのポインタ
		char* x = NULL;					// 枢軸へのポインタ

		do {
			if (pv != pt) x = &v[(pv = pt) * size];
			while (compar(&v[pl * size], x) < 0) pl++;
			while (compar(&v[pr * size], x) > 0) pr--;
			if (pl <= pr)
			{
				pt = (pl == pv) ? pr : ((pr == pv) ? pl : pv);
				memswap(&v[pl * size], &v[pr * size], size);
				pl++;
				if (pr == 0)
					goto QuickRignt;
				pr--;
			}

		} while (pl <= pr);

		if (0 < pr) quicksort(&v[0], pr + 1, size, compar);
	QuickRignt:
		if (pl < nmemb - 1) quicksort(&v[pl * size], nmemb - pl, size, compar);
	}
}

//--- int型の比較関数 ---//
static int int_cmp(const void* a, const void* b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;

	return x < y ? -1 : (x > y ? 1 : 0);
}
