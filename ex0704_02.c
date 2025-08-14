/* 演習7-4の別解 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH	10

//*** 関数プロトタイプ宣言 ***//

//*** main関数 ***//
int main(void)
{
	int num;
	char (*p)[LENGTH];


	printf("文字列は何個：");
	scanf("%d", &num);

	p = malloc(num * LENGTH);

	if (p == NULL)
		puts("記憶域の確保に失敗しました。");
	else
	{
		int i;
		char tmp[128] = "";

		for (i = 0; i < num; i++)
		{
			printf("p[%d]：", i);
			scanf("%s", tmp);

			if (strlen(tmp) > 9)
			{
				tmp[9] = '\0';
				strcpy(p[i], tmp);
			}
		}

		for (i = 0; i < num; i++)
			printf("p[%d] = %s\n", i, p[i]);

		free(p);
	}

	return 0;
}

//---  ---//
