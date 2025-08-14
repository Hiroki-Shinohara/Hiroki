#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//*** �֐��v���g�^�C�v�錾 ***//
static int isA(int x);
static int isB(int x);
static int isC(int x);
static int isD(int x);
static int put_list(const int a[], int n, int (*fit)(int), const char* label);

//*** main�֐� ***//
int main(void)
{
	int i;
	int a[15];
	int n = sizeof(a) / sizeof(a[0]);
	int count;

	srand(time(NULL));

	// 0�`100�̃����_���_���𐶐�
	for (i = 0; i < n; i++)
		a[i] = rand() % 101;

	// �����N�ʂɕ\��&�W�v
	printf("=== �]���ʈꗗ ===\n");
	count = put_list(a, n, isA, "�D(A)");
	printf("�D(A)�l���F%d\n\n", count);

	count = put_list(a, n, isB, "��(B)");
	printf("��(B)�l���F%d\n\n", count);

	count = put_list(a, n, isC, "��(C)");
	printf("��(C)�l���F%d\n\n", count);

	count = put_list(a, n, isD, "�s��(D)");
	printf("�s��(D)�l���F%d\n\n", count);

	return 0;
}

//--- �]������֐� ---//
static int isA(int x) { return x >= 80 && x <= 100; }
static int isB(int x) { return x >= 70 && x <= 79; }
static int isC(int x) { return x >= 60 && x <= 69; }
static int isD(int x) { return x < 60; }

//--- �����ɍ����v�f���o�͂��A������Ԃ� ---//
static int put_list(const int a[], int n, int (*fit)(int), const char* label)
{
	int i, count = 0;
	printf("[%s]\n", label);

	for (i = 0; i < n; i++)
	{
		if (fit(a[i]))
		{
			printf("�� a[%2d] = %3d\n", i, a[i]);
			count++;
		}
		else
		{
			printf("   a[%2d] = %3d\n", i, a[i]);
		}
	}


	return count;
}