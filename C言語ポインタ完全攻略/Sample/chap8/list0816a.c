#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH	20

//*** �^��` ***//

//*** �֐��v���g�^�C�v�錾 ***//
static void memswap(void* x, void* y, size_t n);
static void quicksort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
static int int_cmp(const void* a, const void* b);

//*** main�֐� ***//
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

	puts("\n�\�[�g��");
	for (i = 0; i < na; i++)
	{
		printf("a[%2d] = %3d\n", i, a[i]);
	}

	return 0;
}

//--- x�Ay�̎w��n�o�C�g�̗̈������ ---//
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

//--- �ėp�N�C�b�N�\�[�g ---//
static void quicksort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	if (nmemb > 0)
	{
		size_t pl = 0;					// ���J�[�\��
		size_t pr = nmemb - 1;			// �E�J�[�\��
		size_t pv = nmemb;				// ����
		size_t pt = (pl + pr) / 2;		// �����̍X�V�l
		char* v = (char*)base;			// �퓬�v�f�ւ̃|�C���^
		char* x = NULL;					// �����ւ̃|�C���^

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

//--- int�^�̔�r�֐� ---//
static int int_cmp(const void* a, const void* b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;

	return x < y ? -1 : (x > y ? 1 : 0);
}
