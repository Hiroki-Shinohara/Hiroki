#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum { Dog, Cat, Mohkey, Crow, Invalid } Animal;
typedef void (*AnimalFP)(void);

//*** �֐��v���g�^�C�v�錾 ***//
static void dog(void);
static void cat(void);
static void monkey(void);
static void crow(void);
static AnimalFP selected_animal(void);

//*** main�֐� ***//
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

//--- �����̖��� ---//
static void dog(void) { puts("���������I�I"); }
static void cat(void) { puts("�j���`�I�I�I"); }
static void monkey(void) { puts("�L�b�L�b�I�I"); }
static void crow(void) { puts("�J�`�J�`�I�I"); }

//--- ������I�� ---//
static AnimalFP selected_animal(void)
{
	int temp;

	while (1)
	{
		printf("(0)...�� (1)...�L (2)...�� (3)...�J���X (4)...�I���F ");
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

