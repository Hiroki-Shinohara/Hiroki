/* ���K7-4�̕ʉ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH	10

//*** �֐��v���g�^�C�v�錾 ***//

//*** main�֐� ***//
int main(void)
{
	int num;
	char (*p)[LENGTH];


	printf("������͉��F");
	scanf("%d", &num);

	p = malloc(num * LENGTH);

	if (p == NULL)
		puts("�L����̊m�ۂɎ��s���܂����B");
	else
	{
		int i;
		char tmp[128] = "";

		for (i = 0; i < num; i++)
		{
			printf("p[%d]�F", i);
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
