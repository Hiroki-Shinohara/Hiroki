/* 演習7-4の解答例 */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH	10		/* 文字列の長さ */

int main(void)
{
	int  num;			/* 文字列の個数 */
	char (*p)[LENGTH];	/* 文字数は定数10 */

	printf("文字列は何個：");
	scanf("%d", &num);

	p = malloc(num * LENGTH);

	if (p == NULL) 
		puts("記憶域の確保に失敗しました。");
	else {
		int  i;
		char temp[100];

		for (i = 0; i < num; i++) {			/* 文字列を読み込む */
			printf("p[%d] : ", i);
			scanf("%s", temp);
			sprintf(p[i], "%.9s", temp);
		}

		for (i = 0; i < num; i++)			/* 文字列を表示 */
			printf("p[%d] = %s\n", i, p[i]);

		free(p);							/* 記憶域を解放 */
	}

	return 0;
}