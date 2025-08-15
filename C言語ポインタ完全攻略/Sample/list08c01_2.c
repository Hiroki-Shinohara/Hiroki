#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum { Dog, Cat, Mohkey, Crow, Invalid } Animal;
typedef void (*AnimalFP)(void);

//*** 関数プロトタイプ宣言 ***//
static void dog(void);
static void cat(void);
static void monkey(void);
static void crow(void);
static AnimalFP selected_animal(void);

//*** main関数 ***//
int main(void)
{
	while (1)
	{
		void (*animal)(void) = selected_animal();
		if (animal == NULL)
			break;
		animal();
	}

	return 0;
}

//--- 動物の鳴き声 ---//
static void dog(void) { puts("ワンワン！！"); }
static void cat(void) { puts("ニャ～オ！！"); }
static void monkey(void) { puts("キッキッ！！"); }
static void crow(void) { puts("カ～カ～！！"); }

//--- 動物を選ぶ ---//
static AnimalFP selected_animal(void)
{
	int temp;

	while (1)
	{
		printf("(0)...犬 (1)...猫 (2)...猿 (3)...カラス (4)...終了： ");
		scanf("%d", &temp);
		switch (temp)
		{
		case Dog:		return dog;
		case Cat:		return cat;
		case Mohkey:	return monkey;
		case Crow:		return crow;
		case Invalid:	return NULL;
		}

	}
}

