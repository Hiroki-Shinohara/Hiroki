#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH	10
#define swap(type, x, y)	do {type t = x; x = y; y = t;} while (0);

//*** 型定義 ***//
typedef struct
{
	int		x;
	long	y;
	double	z;
} xyz;

//*** 関数プロトタイプ宣言 ***//
static void set_xyz(xyz* p);
static void print_xyz(const xyz v[], size_t n);
static int cmp_xyz(const void* a, const void* b);

//*** main関数 ***//
int main(void)
{
	int i;
	xyz p[LENGTH] = { {0, 0, 0.0} };
	int np = sizeof(p) / sizeof(p[0]);

	srand(time(NULL));
	for (i = 0; i < np; i++)
	{
		set_xyz(&p[i]);
	}

	print_xyz(p, np);

	qsort(p, np, sizeof(xyz), cmp_xyz);

	puts("ソート後");
	print_xyz(p, np);

	return 0;
}

//---  ---//
static void set_xyz(xyz* p)
{
	p->x = rand() % 100;
	p->y = (long)(rand() % 10000);
	p->z = (rand() % 1000) / 100.0;
}

//---  ---//
static void print_xyz(const xyz v[], size_t n)
{
	for (int i = 0; i < n; i++)
	{
		printf("p[%d].x = %d\n", i, v[i].x);
		printf("p[%d].y = %ld\n", i, v[i].y);
		printf("p[%d].z = %.2f\n\n", i, v[i].z);
	}
}

//---  ---//
static int cmp_xyz(const void* a, const void* b)
{
	const xyz* pa = (const xyz*)a;
	const xyz* pb = (const xyz*)b;
	return (pa->x < pb->x) ? -1 : (pa->x > pb->x) ? 1 : 0;
}

