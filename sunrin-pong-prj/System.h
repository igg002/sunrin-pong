#ifndef TURBOC_HEADER
#define TURBOC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);

//fflush(stdin)�� fgets ���� �ذ� ��ü �Լ�...
void inclear(void);
void fgetsclear(char * string);

//�ѹ� ���ߴ� ��� ���ϴ� ���ڿ� ����ϱ�
void PASstring(char * string);

//��ũ�� ����
#define CLS system("cls")

//system("pause") ��� ����...
#define PAS system("pause");
#define FUS fflush(stdin)

//����Ű
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define SPACE 32
#define BACKSPACE 8

#pragma warning(disable:4761) 

#define delay(n) Sleep(n)                              // n/1000�ʸ�ŭ �ð� ����
#define randomize() srand((unsigned)time(NULL))         // ���� �߻��� �ʱ�ȭ
#define random(n) (rand() % (n))                        //0~n������ ���� �߻�

// �� ��ũ�ΰ� ���ǵǾ� ������ �Լ��� ������ �����ϰ� ���Ǵ� ���� �ʴ´�.

#ifndef TURBOC_PROTOTYPE_ONLY

#define MAPSIZEW 55
#define MAPSIZEH 30

// ȭ���� ��� �����.

void clrscr()
{
	system("cls");
}

//fflush(stdin)�� VS������ ��밡���ϱ⶧���� ����� ������...
void inclear(void)
{
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n');
}

//fgets�� ������ �ذ��ϴ� �Լ�
void fgetsclear(char * string)
{
	if (string[strlen(string) - 1] == '\n'){
		string[strlen(string) - 1] = '\0';
	}
	else{
		inclear();
	}
}

//string�� ���� �ѹ� �����ִ� �Լ�
void PASstring(char * string){
	puts(string); getch();
}

//��ũ�� �Լ� �� �÷��Լ�
#define printmsg(x,y,str) { gotoxy(x,y) ;puts(str); }

void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};
enum {
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VIOLET,      /* 13 : ���� */
	YELLOW,      /* 14 : ��� */
	WHITE,      /* 15 : �Ͼ� */
};

/*==== ���ڿ� ���� �Ҵ� ��ȯ �Լ� ====*/
char * insert_dy_word(int flag){
	char buff[512];
	char * tmp;
	int cnt;

	fgets(buff, sizeof(buff), stdin);
	if (flag){ // flag�� 0�� �ƴϸ�, �����ڸ� �������� �˻��Ѵ�.
		if (buff[0] < 'a' || buff[0] >'z'){
			puts("�߸��� �Է��Դϴ�.");
			return NULL;
		}
	}
	cnt = strlen(buff);
	if (buff[cnt - 1] == '\n'){
		buff[cnt - 1] = '\0';
	}

	tmp = (char*)malloc(cnt*sizeof(char));
	strcpy(tmp, buff);

	return tmp;
}

/*====���� �Ҷ� �ַ� ���̴� �Լ�====*/

//�����̽��� ����ٷ�
void sTOu(char * tmp){
	int i = 0;
	while (tmp[i] != '\0'){
		if (tmp[i] == ' '){
			tmp[i] = '_';
		}
		i++;
	}
}

// ����ٸ� �����̽� �ٷ� 
void uTOs(char * tmp){
	int i = 0;
	while (tmp[i] != '\0'){
		if (tmp[i] == '_'){
			tmp[i] = ' ';
		}
		i++;
	}
}

//���� 2���� �����ȿ��� �������� ����մϴ�.
int baserand(int x, int y){
	static int z = 0;
	int tmp;
	if (z == 0){
		srand((int)time(NULL));
		rand(); rand(); rand(); rand();
		srand(rand());
		z = 1;
	}
	tmp = rand() % (y - x + 1) + x;
	return tmp;
}

// Ŀ���� x,y��ǥ�� �̵���Ų��.

void gotoxy(int x, int y)

{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// Ŀ���� x ��ǥ�� �����Ѵ�.
int wherex()

{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// Ŀ���� y��ǥ�� �����Ѵ�.

int wherey()

{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}



// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.

void setcursortype(CURSOR_TYPE c)

{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;

	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;

	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void setCursor(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // true ����, false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ��������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
}



#endif // TURBOC_PROTOTYPE_ONLY
#endif // TURBOC_HEADER

void DrawMap(){
	system("mode con:cols=120 lines=30");
	for (int i = 0; i<MAPSIZEH; i++)
	{
		for (int j = 0; j< MAPSIZEW; j++)
		{
			if (i == 0 || i == MAPSIZEH - 1 || j == 0 || j == MAPSIZEW - 1)
				printf("��");
			else
				printf("  ");

		}

		printf("\n");
	}

}