#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//*** 関数プロトタイプ宣言 ***//
static int isA(int x);
static int isB(int x);
static int isC(int x);
static int isD(int x);
static int put_list(const int a[], int n, int (*fit)(int), const char* label);

//*** main関数 ***//
int main(void)
{
	int i;
	int a[15];
	int n = sizeof(a) / sizeof(a[0]);
	int count;

	srand(time(NULL));

	// 0～100のランダム点数を生成
	for (i = 0; i < n; i++)
		a[i] = rand() % 101;

	// ランク別に表示&集計
	printf("=== 評価別一覧 ===\n");
	count = put_list(a, n, isA, "優(A)");
	printf("優(A)人数：%d\n\n", count);

	count = put_list(a, n, isB, "良(B)");
	printf("良(B)人数：%d\n\n", count);

	count = put_list(a, n, isC, "可(C)");
	printf("可(C)人数：%d\n\n", count);

	count = put_list(a, n, isD, "不可(D)");
	printf("不可(D)人数：%d\n\n", count);

	return 0;
}

//--- 評価判定関数 ---//
static int isA(int x) { return x >= 80 && x <= 100; }
static int isB(int x) { return x >= 70 && x <= 79; }
static int isC(int x) { return x >= 60 && x <= 69; }
static int isD(int x) { return x < 60; }

//--- 条件に合う要素を出力し、件数を返す ---//
static int put_list(const int a[], int n, int (*fit)(int), const char* label)
{
	int i, count = 0;
	printf("[%s]\n", label);

	for (i = 0; i < n; i++)
	{
		if (fit(a[i]))
		{
			printf("★ a[%2d] = %3d\n", i, a[i]);
			count++;
		}
		else
		{
			printf("   a[%2d] = %3d\n", i, a[i]);
		}
	}


	return count;
}
