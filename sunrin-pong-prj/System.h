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

//fflush(stdin)과 fgets 문제 해결 대체 함수...
void inclear(void);
void fgetsclear(char * string);

//한번 멈추는 기능 원하는 문자열 출력하기
void PASstring(char * string);

//매크로 선언
#define CLS system("cls")

//system("pause") 사용 제한...
#define PAS system("pause");
#define FUS fflush(stdin)

//방향키
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define SPACE 32
#define BACKSPACE 8

#pragma warning(disable:4761) 

#define delay(n) Sleep(n)                              // n/1000초만큼 시간 지연
#define randomize() srand((unsigned)time(NULL))         // 난수 발생기 초기화
#define random(n) (rand() % (n))                        //0~n까지의 난수 발생

// 이 매크로가 정의되어 있으면 함수의 원형만 선언하고 정의는 하지 않는다.

#ifndef TURBOC_PROTOTYPE_ONLY

#define MAPSIZEW 55
#define MAPSIZEH 30

// 화면을 모두 지운다.

void clrscr()
{
	system("cls");
}

//fflush(stdin)은 VS에서만 사용가능하기때문에 만들어 놓은것...
void inclear(void)
{
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n');
}

//fgets의 문제점 해결하는 함수
void fgetsclear(char * string)
{
	if (string[strlen(string) - 1] == '\n'){
		string[strlen(string) - 1] = '\0';
	}
	else{
		inclear();
	}
}

//string을 가진 한번 멈춰주는 함수
void PASstring(char * string){
	puts(string); getch();
}

//매크로 함수 및 컬러함수
#define printmsg(x,y,str) { gotoxy(x,y) ;puts(str); }

void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};
enum {
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VIOLET,      /* 13 : 보라 */
	YELLOW,      /* 14 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

/*==== 문자열 동적 할당 반환 함수 ====*/
char * insert_dy_word(int flag){
	char buff[512];
	char * tmp;
	int cnt;

	fgets(buff, sizeof(buff), stdin);
	if (flag){ // flag가 0이 아니면, 영문자만 들어오도록 검사한다.
		if (buff[0] < 'a' || buff[0] >'z'){
			puts("잘못된 입력입니다.");
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

/*====저장 할때 주로 쓰이는 함수====*/

//스페이스를 언더바로
void sTOu(char * tmp){
	int i = 0;
	while (tmp[i] != '\0'){
		if (tmp[i] == ' '){
			tmp[i] = '_';
		}
		i++;
	}
}

// 언더바를 스페이스 바로 
void uTOs(char * tmp){
	int i = 0;
	while (tmp[i] != '\0'){
		if (tmp[i] == '_'){
			tmp[i] = ' ';
		}
		i++;
	}
}

//숫자 2개의 범위안에서 랜덤값을 출력합니다.
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

// 커서를 x,y좌표로 이동시킨다.

void gotoxy(int x, int y)

{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 커서의 x 좌표를 조사한다.
int wherex()

{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다.

int wherey()

{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}



// 커서를 숨기거나 다시 표시한다.

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
	ConsoleCursor.bVisible = false; // true 보임, false 안보임
	ConsoleCursor.dwSize = 1; // 커서사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // 설정
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
				printf("▨");
			else
				printf("  ");

		}

		printf("\n");
	}

}