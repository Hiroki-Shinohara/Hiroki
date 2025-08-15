#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ANIMALS	10

//*** �^��` ***//
typedef void (*AnimalFuncPtr)(void);	// �����^�֐�

typedef struct
{
	const char* name;		// ������
	AnimalFuncPtr speak;	// �����֐�
} Animal;

typedef struct
{
	const char* name;		// �J�e�S����
	const Animal* list;		// �����z��
	int count;				// ������
} Category;

//*** �֐��v���g�^�C�v�錾 ***//
static void dog(void);
static void cat(void);
static void monkey(void);
static void crow(void);
static void parrot(void);
static void eagle(void);
static int select_menu(const char* title, const char* exit_label,
	int count, const char* names[]);

// �����f�[�^
static const Animal mammals[] = {
	{"��", dog},
	{"�L", cat},
	{"��", monkey},
};

static const Animal birds[] = {
	{"�J���X", crow},
	{"�I�E��", parrot},
	{"���V", eagle},
};

// �J�e�S���f�[�^
static const Category categories[] = {
	{ "�M����", mammals, sizeof(mammals) / sizeof(mammals[0]) },
	{ "����",   birds,   sizeof(birds) / sizeof(birds[0])   },
};

//*** main�֐� ***//
int main(void)
{
	const cat_num = sizeof(categories) / sizeof(categories[0]);

	while (1)
	{
		// �J�e�S�������X�g�쐬
		const char* cat_names[sizeof(categories) / sizeof(categories[0])];
		for (int i = 0; i < (int)(sizeof(categories) / sizeof(categories[0])); i++)
		{
			cat_names[i] = categories[i].name;
		}

		// �J�e�S���I��
		int cat_choice = select_menu("�J�e�S���I��", "�I��",
			sizeof(categories) / sizeof(categories[0]), cat_names);
		if (cat_choice == (int)(sizeof(categories) / sizeof(categories[0]))) break;

		// ���������X�g�쐬
		const Category* cat = &categories[cat_choice];
		const char* animal_names[MAX_ANIMALS];
		for (int i = 0; i < cat->count; i++)
		{
			animal_names[i] = cat->list[i].name;
		}

		// �����I��
		int ani_choice = select_menu(cat->name, "�߂�", cat->count, animal_names);
		if (ani_choice == cat->count) continue;

		cat->list[ani_choice].speak();
	}

	puts("�I�����܂��B");
	return 0;
}

//--- �����̖��� ---//
static void dog(void) { puts("���������I�I"); }
static void cat(void) { puts("�j���`�I�I�I"); }
static void monkey(void) { puts("�L�b�L�b�I�I"); }
static void crow(void) { puts("�J�`�J�`�I�I"); }
static void parrot(void) { puts("�R���j�`�n�I�I"); }
static void eagle(void) { puts("�s�[�q�������I�I"); }

//--- ���j���[�\���ƑI�� ---//
static int select_menu(const char* title, const char* exit_label,
	int count, const char* names[])
{
	int choice;
	while (1)
	{
		printf("\n%s\n", title);
		for (int i = 0; i < count; i++)
		{
			printf("�i%d�j%s\n", i, names[i]);
		}
		printf("�i%d�j%s\n", count, exit_label);
		printf("�I���F");
		if (scanf("%d", &choice) != 1) return count;	// �I������
		if (choice >= 0 && choice <= count) return choice;
	}
}