#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** 関数プロトタイプ宣言 ***//
static void* recalloc(void* ptr, size_t size, size_t old_size);

//*** main関数 ***//
int main(void)
{
	int n1;
	int* p;

	printf("確保する配列の要素数：");
	scanf("%d", &n1);

	if ((p = calloc(n1, sizeof(int))) == NULL)
		puts("記憶域の確保に失敗しました。");
	else
	{
		int i, n2;
		int no = n1;
		int* temp = NULL;

		for (i = 0; i < n1; i++)
			p[i] = i;

		printf("要素数をいくつにしますか：");
		scanf("%d", &n2);

		if ((temp = recalloc(p, n2 * sizeof(int), n1 * sizeof(int))) == NULL)
			puts("領域の大きさの変更に失敗しました。");
		else
		{
			p = temp;
			/*for (i = n1; i < n2; i++)
				p[i] = i;*/
			no = n2;
		}

		for (i = 0; i < no; i++)
			printf("p[%d] = %d\n", i, p[i]);
		free(p);
	}

	return 0;
}

//---  ---//
static void* recalloc(void* ptr, size_t size, size_t old_size)
{
	void* tmp;

	if (size == 0)
		return NULL;

	tmp = realloc(ptr, size);
	if (tmp != NULL && size > old_size)
		memset((char*)tmp + old_size, 0, size - old_size);
	
	return tmp;
}
