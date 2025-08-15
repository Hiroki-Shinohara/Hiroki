#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 型定義
typedef void (*AnimalFuncPtr)(void);
typedef AnimalFuncPtr(*ChooseFuncPtr)(void);

//*** 関数プロトタイプ宣言 ***//
static void dog(void);
static void cat(void);
static void monkey(void);
static void crow(void);
static void parrot(void);
static AnimalFuncPtr choose_mammal(void);
static AnimalFuncPtr choose_bird(void);
static ChooseFuncPtr choose_category(void);

//*** main関数 ***//
int main(void)
{
	while (1)
	{
		// カテゴリ選択
		ChooseFuncPtr chooser = choose_category();
		if (chooser == NULL) break;

		// 動物選択
		AnimalFuncPtr animal = chooser();
		if (animal == NULL) continue;

		animal();	// 鳴き声
	}

	puts("終了します。");

	return 0;
}

//--- 動物の鳴き声 ---//
static void dog(void) { puts("ワンワン！！"); }
static void cat(void) { puts("ニャ～オ！！"); }
static void monkey(void) { puts("キッキッ！！"); }
static void crow(void) { puts("カ～カ～！！"); }
static void parrot(void) { puts("コンニチハ！！"); }

//--- 動物選択関数（哺乳類） ---//
static AnimalFuncPtr choose_mammal(void)
{
	int temp;

	while (1)
	{
		printf("哺乳類：(0)犬 (1)猫 (2)猿 (3)戻る：");
		if (scanf("%d", &temp) != 1) return NULL;
		switch (temp)
		{
		case 0:	return dog;
		case 1:	return cat;
		case 2: return monkey;
		case 3:	return NULL;
		}
	}
}

//--- 動物選択関数（鳥類） ---//
static AnimalFuncPtr choose_bird(void)
{
	int temp;

	while (1)
	{
		printf("鳥類：(0)カラス (1)オウム (2)戻る：");
		if (scanf("%d", &temp) != 1) return NULL;
		switch (temp)
		{
		case 0:	return crow;
		case 1:	return parrot;
		case 2: return NULL;
		}
	}
}

//--- カテゴリ選択（動物選択関数を返す） ---//
static ChooseFuncPtr choose_category(void)
{
	int temp;
	while (1)
	{
		printf("カテゴリ選択：(0)哺乳類 (1)鳥類 (2)終了：");
		if (scanf("%d", &temp) != 1) return NULL;
		switch (temp)
		{
		case 0:	return choose_mammal;
		case 1:	return choose_bird;
		case 2:	return NULL;
		}
	}
}
