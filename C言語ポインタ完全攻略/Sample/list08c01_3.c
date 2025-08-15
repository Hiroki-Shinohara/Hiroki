#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �^��`
typedef void (*AnimalFuncPtr)(void);
typedef AnimalFuncPtr(*ChooseFuncPtr)(void);

//*** �֐��v���g�^�C�v�錾 ***//
static void dog(void);
static void cat(void);
static void monkey(void);
static void crow(void);
static void parrot(void);
static AnimalFuncPtr choose_mammal(void);
static AnimalFuncPtr choose_bird(void);
static ChooseFuncPtr choose_category(void);

//*** main�֐� ***//
int main(void)
{
	while (1)
	{
		// �J�e�S���I��
		ChooseFuncPtr chooser = choose_category();
		if (chooser == NULL) break;

		// �����I��
		AnimalFuncPtr animal = chooser();
		if (animal == NULL) continue;

		animal();	// ����
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

//--- �����I���֐��i�M���ށj ---//
static AnimalFuncPtr choose_mammal(void)
{
	int temp;

	while (1)
	{
		printf("�M���ށF(0)�� (1)�L (2)�� (3)�߂�F");
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

//--- �����I���֐��i���ށj ---//
static AnimalFuncPtr choose_bird(void)
{
	int temp;

	while (1)
	{
		printf("���ށF(0)�J���X (1)�I�E�� (2)�߂�F");
		if (scanf("%d", &temp) != 1) return NULL;
		switch (temp)
		{
		case 0:	return crow;
		case 1:	return parrot;
		case 2: return NULL;
		}
	}
}

//--- �J�e�S���I���i�����I���֐���Ԃ��j ---//
static ChooseFuncPtr choose_category(void)
{
	int temp;
	while (1)
	{
		printf("�J�e�S���I���F(0)�M���� (1)���� (2)�I���F");
		if (scanf("%d", &temp) != 1) return NULL;
		switch (temp)
		{
		case 0:	return choose_mammal;
		case 1:	return choose_bird;
		case 2:	return NULL;
		}
	}
}