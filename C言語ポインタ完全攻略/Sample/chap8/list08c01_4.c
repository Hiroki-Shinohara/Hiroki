#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ANIMALS	10

//*** 型定義 ***//
typedef void (*AnimalFuncPtr)(void);	// 鳴き声型関数

typedef struct
{
	const char* name;		// 動物名
	AnimalFuncPtr speak;	// 鳴き声関数
} Animal;

typedef struct
{
	const char* name;		// カテゴリ名
	const Animal* list;		// 動物配列
	int count;				// 動物数
} Category;

//*** 関数プロトタイプ宣言 ***//
static void dog(void);
static void cat(void);
static void monkey(void);
static void crow(void);
static void parrot(void);
static void eagle(void);
static int select_menu(const char* title, const char* exit_label,
	int count, const char* names[]);

// 動物データ
static const Animal mammals[] = {
	{"犬", dog},
	{"猫", cat},
	{"猿", monkey},
};

static const Animal birds[] = {
	{"カラス", crow},
	{"オウム", parrot},
	{"ワシ", eagle},
};

// カテゴリデータ
static const Category categories[] = {
	{ "哺乳類", mammals, sizeof(mammals) / sizeof(mammals[0]) },
	{ "鳥類",   birds,   sizeof(birds) / sizeof(birds[0])   },
};

//*** main関数 ***//
int main(void)
{
	const cat_num = sizeof(categories) / sizeof(categories[0]);

	while (1)
	{
		// カテゴリ名リスト作成
		const char* cat_names[sizeof(categories) / sizeof(categories[0])];
		for (int i = 0; i < (int)(sizeof(categories) / sizeof(categories[0])); i++)
		{
			cat_names[i] = categories[i].name;
		}

		// カテゴリ選択
		int cat_choice = select_menu("カテゴリ選択", "終了",
			sizeof(categories) / sizeof(categories[0]), cat_names);
		if (cat_choice == (int)(sizeof(categories) / sizeof(categories[0]))) break;

		// 動物名リスト作成
		const Category* cat = &categories[cat_choice];
		const char* animal_names[MAX_ANIMALS];
		for (int i = 0; i < cat->count; i++)
		{
			animal_names[i] = cat->list[i].name;
		}

		// 動物選択
		int ani_choice = select_menu(cat->name, "戻る", cat->count, animal_names);
		if (ani_choice == cat->count) continue;

		cat->list[ani_choice].speak();
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
static void eagle(void) { puts("ピーヒョロロ！！"); }

//--- メニュー表示と選択 ---//
static int select_menu(const char* title, const char* exit_label,
	int count, const char* names[])
{
	int choice;
	while (1)
	{
		printf("\n%s\n", title);
		for (int i = 0; i < count; i++)
		{
			printf("（%d）%s\n", i, names[i]);
		}
		printf("（%d）%s\n", count, exit_label);
		printf("選択：");
		if (scanf("%d", &choice) != 1) return count;	// 終了扱い
		if (choice >= 0 && choice <= count) return choice;
	}
}