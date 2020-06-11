#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define SIZE		19
#define PAN			0
#define BLACKSTONE	1
#define WHITESTONE	2
#define HINT1		3
#define HINT2		4
#define HINT3		5

int iOmokPan[SIZE][SIZE];
int iPlayerTurn = 1;		// black: 1   while: 2
int iX = 0;
int iY = 0;

typedef struct Hint
{
	int x = 0;
	int y = 0;
	int score = 0;
	Hint* next;
	Hint* prev;
}HINT;

// 검은색이 공격한걸 흰색이 막을 수있는 힌트
HINT* WhiteHead = (HINT*)malloc(sizeof(HINT));

void Draw();
void AutoInput();
void White_Defence();
void White_Attack();
void ResetHint();

int main()
{
	while (true)
	{
		char cSelect;
		system("cls");
		Draw();
		printf("i/I: 돌입력  h/H: 힌트  q/Q: 종료\n");
		scanf_s("%c", &cSelect);
		while (getchar() != '\n');
		switch (cSelect)
		{
		case 'I':
		case 'i':
			AutoInput();
			break;
		case 'H':
		case 'h':
			ResetHint();
			White_Defence();
			break;
		case 'q':
		case 'Q':
			return 0;
		default:
			break;
		}
		system("cls");
		Draw();
		system("pause");
	}
	return 0;
}

void Draw()
{
	printf(" ");
	for (int i = 0; i < SIZE; ++i)
	{
		if (i < 10)
			printf(" %d", i);
		else
			printf(" %c", i + 55);
	}
	printf("\n");
	for (int i = 0; i < SIZE; ++i)
	{
		if (i < 10)
			printf("%d", i);
		else
			printf("%c", i + 55);
		for (int j = 0; j < SIZE; ++j)
		{
			if (iOmokPan[i][j] == PAN)
				printf("┼ ");
			else if (iOmokPan[i][j] == BLACKSTONE)
				printf("○");
			else if (iOmokPan[i][j] == WHITESTONE)
				printf("●");
			else if (iOmokPan[i][j] == HINT1)
				printf("①");
			else if (iOmokPan[i][j] == HINT2)
				printf("②");
			else if (iOmokPan[i][j] == HINT3)
				printf("③");
		}
		printf("\n");
	}
}
void AutoInput()
{
	while (true)
	{

		printf("(x , y) : ");
		scanf_s("%d %d", &iX, &iY);
		while (getchar() != '\n');

		if ((0 <= iX) && (iX <= 18) && (0 <= iY) && (iY <= 18))
		{
			if (iOmokPan[iX][iY] != PAN && iOmokPan[iX][iY] != HINT1 && iOmokPan[iX][iY] != HINT2 && iOmokPan[iX][iY] != HINT3)
				printf("이미 돌이 놓여 있습니다.\n");
			else
			{
				if (iPlayerTurn == 1)
					iOmokPan[iX][iY] = BLACKSTONE;
				break;
			}
		}
		else
			printf("범위를 벗어났습니다. 다시 입력해주세요.\n");
	}
	White_Attack();
}


// 평가함수 - 옆에 돌이 하나가 있다면 +1
//			- 옆에 돌이 두개가 있다면 +10 
//			- 옆에 돌이 세개가 있다면 +100 
//			- 옆에 돌이 네개가 있다면 +1000
//			- 그 외의 +a 평가
//			- 필수 공격 +5 + 10단위
// 스캔을 하며 각 자리마다 점수를 매긴다 -> 힌트 연결리스트를 구현해 우선순위 1 2 3 을 정해본다.
void White_Defence()
{
	// 백돌이 방어해야함
	int score = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			score = 0;
			if (iOmokPan[i][j] == PAN || iOmokPan[i][j] == HINT1)
			{
				//----------가로-----------//
				{
					//-------------- 수비 --------------//
					// a●
					if (iOmokPan[i][j + 1] == BLACKSTONE && (j + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i][j - 1] == BLACKSTONE && (j - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i][j - 1] == BLACKSTONE && (j + 1 <= SIZE) && iOmokPan[i][j + 1] == BLACKSTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && (j + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 1 >= 0) && (j + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && (j - 2 >= 0) && (j + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && iOmokPan[i][j + 4] == BLACKSTONE && (j + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && (j - 3 >= 0) && (j + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && (j - 3 >= 0) && (j + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i][j - 4] == BLACKSTONE && iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == BLACKSTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 1 >= 0) && (j + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && (j - 1 >= 0) && (j + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 2 >= 0) && (j + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 3 >= 0) && (j + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == WHITESTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i][j + 1] == WHITESTONE && (j + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i][j - 1] == WHITESTONE && (j - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && (j + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && iOmokPan[i][j + 3] == WHITESTONE && (j + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && (j - 1 >= 0) && (j + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 2 >= 0) && (j + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i][j - 3] == WHITESTONE && iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && iOmokPan[i][j + 3] == WHITESTONE && iOmokPan[i][j + 4] == WHITESTONE && (j + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && iOmokPan[i][j + 3] == WHITESTONE && (j - 1 >= 0) && (j + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i][j - 3] == WHITESTONE && iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 3 >= 0) && (j + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i][j - 4] == WHITESTONE && iOmokPan[i][j - 3] == WHITESTONE && iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && (j - 4 >= 0))
						score += 5000;
				}
				//----------세로-----------//
				{
					// a●
					if (iOmokPan[i + 1][j] == BLACKSTONE && (i + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i - 1][j] == BLACKSTONE && (i - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && (i - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && (i + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 1 >= 0) && (i + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 2 >= 0) && (i + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && (i - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && iOmokPan[i + 4][j] == BLACKSTONE && (i + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && (i - 1 >= 0) && (i + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 3 >= 0) && (i + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i - 4][j] == BLACKSTONE && iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && (i - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 1 >= 0) && (i + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && (i - 1 >= 0) && (i + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 2 >= 0) && (i + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 3 >= 0) && (i + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == WHITESTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i + 1][j] == WHITESTONE && (i + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i - 1][j] == WHITESTONE && (i - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && (i + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && (i - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && iOmokPan[i + 3][j] == WHITESTONE && (i + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && (i - 1 >= 0) && (i + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 2 >= 0) && (i + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i - 3][j] == WHITESTONE && iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && (i - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && iOmokPan[i + 3][j] == WHITESTONE && iOmokPan[i + 4][j] == WHITESTONE && (i + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && iOmokPan[i + 3][j] == WHITESTONE && (i - 1 >= 0) && (i + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i - 3][j] == WHITESTONE && iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 3 >= 0) && (i + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i - 4][j] == WHITESTONE && iOmokPan[i - 3][j] == WHITESTONE && iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && (i - 4 >= 0))
						score += 5000;
				}
				//-------우상향대각--------//
				{
					// a●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 3 <= SIZE) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && iOmokPan[i - 4][j + 4] == BLACKSTONE && (i - 4 >= 0) && (j + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 3 <= SIZE) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i + 4][j - 4] == BLACKSTONE && iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 4 <= SIZE) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 3 <= SIZE) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && iOmokPan[i - 3][j + 3] == WHITESTONE && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i + 3][j - 3] == WHITESTONE && iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 3 <= SIZE) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && iOmokPan[i - 3][j + 3] == WHITESTONE && iOmokPan[i - 4][j + 4] == WHITESTONE && (i - 4 >= 0) && (j + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && iOmokPan[i - 3][j + 3] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i + 3][j - 3] == WHITESTONE && iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 3 <= SIZE) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i + 4][j - 4] == WHITESTONE && iOmokPan[i + 3][j - 3] == WHITESTONE && iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 4 <= SIZE) && (j - 4 >= 0))
						score += 5000;
				}
				//-------좌상향대각--------//
				{
					// a●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 2 >= 0) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 3 >= 0) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && iOmokPan[i + 4][j + 4] == BLACKSTONE && (i + 4 <= SIZE) && (j + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i - 4][j - 4] == BLACKSTONE && iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 4 >= 0) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 2 >= 0) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && iOmokPan[i + 3][j + 3] == WHITESTONE && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i - 3][j - 3] == WHITESTONE && iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 3 >= 0) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && iOmokPan[i + 3][j + 3] == WHITESTONE && iOmokPan[i + 4][j + 4] == WHITESTONE && (i + 4 <= SIZE) && (j + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && iOmokPan[i + 3][j + 3] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i - 3][j - 3] == WHITESTONE && iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i - 4][j - 4] == WHITESTONE && iOmokPan[i - 3][j - 3] == WHITESTONE && iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 4 >= 0) && (j - 4 >= 0))
						score += 5000;
				}
				// 점수 판별 및 힌트
				{
					if (WhiteHead->next == NULL)
					{
						HINT* p = (HINT*)malloc(sizeof(HINT));
						p->x = i;
						p->y = j;
						p->score = score;
						WhiteHead->next = p;
						p->next = WhiteHead->next;
						p->prev = WhiteHead->next;
					}
					else
					{
						// hint1
						if (WhiteHead->next->score < score)
						{
							HINT* p = (HINT*)malloc(sizeof(HINT));
							p->x = i;
							p->y = j;
							p->score = score;
							WhiteHead->next->prev = p;
							p->next = WhiteHead->next;
							WhiteHead->next = p;
						}
						else
						{
							// hint2
							if (WhiteHead->next->next->score < score)
							{
								HINT* p = (HINT*)malloc(sizeof(HINT));
								p->x = i;
								p->y = j;
								p->score = score;
								WhiteHead->next->next->prev = p;
								p->next = WhiteHead->next->next;
								p->prev = WhiteHead->next;
								WhiteHead->next->next = p;
							}
							else
							{
								// hint3
								if (WhiteHead->next->next->next->score < score)
								{
									HINT* p = (HINT*)malloc(sizeof(HINT));
									p->x = i;
									p->y = j;
									p->score = score;
									WhiteHead->next->next->next->prev = p;
									p->next = WhiteHead->next->next->next;
									p->prev = WhiteHead->next->next;
									WhiteHead->next->next->next = p;
								}
							}
						}
					}
				}
			}
		}
	}
	if (WhiteHead->next->score != 0)
		iOmokPan[WhiteHead->next->x][WhiteHead->next->y] = HINT1;
	if (WhiteHead->next->next->score != 0)
		iOmokPan[WhiteHead->next->next->x][WhiteHead->next->next->y] = HINT2;
	if (WhiteHead->next->next->next->score != 0)
		iOmokPan[WhiteHead->next->next->next->x][WhiteHead->next->next->next->y] = HINT3;
}
void White_Attack()
{
	ResetHint();
	int score = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			score = 0;
			if (iOmokPan[i][j] == PAN || iOmokPan[i][j] == HINT1)
			{
				//----------가로-----------//
				{
					//-------------- 수비 --------------//
					// a●
					if (iOmokPan[i][j + 1] == BLACKSTONE && (j + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i][j - 1] == BLACKSTONE && (j - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i][j - 1] == BLACKSTONE && (j + 1 <= SIZE) && iOmokPan[i][j + 1] == BLACKSTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && (j + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 1 >= 0) && (j + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && (j - 2 >= 0) && (j + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && iOmokPan[i][j + 4] == BLACKSTONE && (j + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && (j - 3 >= 0) && (j + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && (j - 3 >= 0) && (j + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i][j - 4] == BLACKSTONE && iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == BLACKSTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 1 >= 0) && (j + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && iOmokPan[i][j + 3] == BLACKSTONE && (j - 1 >= 0) && (j + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == BLACKSTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 2 >= 0) && (j + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i][j - 3] == BLACKSTONE && iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 3 >= 0) && (j + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i][j - 2] == BLACKSTONE && iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] == BLACKSTONE && iOmokPan[i][j + 2] == WHITESTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i][j + 1] == WHITESTONE && (j + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i][j - 1] == WHITESTONE && (j - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && (j + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 1 >= 0) && (j + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && iOmokPan[i][j + 3] == WHITESTONE && (j + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && (j - 1 >= 0) && (j + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 2 >= 0) && (j + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i][j - 3] == WHITESTONE && iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && iOmokPan[i][j + 3] == WHITESTONE && iOmokPan[i][j + 4] == WHITESTONE && (j + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && iOmokPan[i][j + 3] == WHITESTONE && (j - 1 >= 0) && (j + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && iOmokPan[i][j + 2] == WHITESTONE && (j - 2 >= 0) && (j + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i][j - 3] == WHITESTONE && iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] == WHITESTONE && (j - 3 >= 0) && (j + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i][j - 4] == WHITESTONE && iOmokPan[i][j - 3] == WHITESTONE && iOmokPan[i][j - 2] == WHITESTONE && iOmokPan[i][j - 1] == WHITESTONE && (j - 4 >= 0))
						score += 5000;
				}
				//----------세로-----------//
				{
					// a●
					if (iOmokPan[i + 1][j] == BLACKSTONE && (i + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i - 1][j] == BLACKSTONE && (i - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && (i - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && (i + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 1 >= 0) && (i + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 2 >= 0) && (i + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && (i - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && iOmokPan[i + 4][j] == BLACKSTONE && (i + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && (i - 1 >= 0) && (i + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 3 >= 0) && (i + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i - 4][j] == BLACKSTONE && iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && (i - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == BLACKSTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 1 >= 0) && (i + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && iOmokPan[i + 3][j] == BLACKSTONE && (i - 1 >= 0) && (i + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == BLACKSTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 2 >= 0) && (i + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i - 3][j] == BLACKSTONE && iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 3 >= 0) && (i + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i - 2][j] == BLACKSTONE && iOmokPan[i - 1][j] == BLACKSTONE && iOmokPan[i + 1][j] == BLACKSTONE && iOmokPan[i + 2][j] == WHITESTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i + 1][j] == WHITESTONE && (i + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i - 1][j] == WHITESTONE && (i - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && (i + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 1 >= 0) && (i + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && (i - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && iOmokPan[i + 3][j] == WHITESTONE && (i + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && (i - 1 >= 0) && (i + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 2 >= 0) && (i + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i - 3][j] == WHITESTONE && iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && (i - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && iOmokPan[i + 3][j] == WHITESTONE && iOmokPan[i + 4][j] == WHITESTONE && (i + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && iOmokPan[i + 3][j] == WHITESTONE && (i - 1 >= 0) && (i + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && iOmokPan[i + 2][j] == WHITESTONE && (i - 2 >= 0) && (i + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i - 3][j] == WHITESTONE && iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && iOmokPan[i + 1][j] == WHITESTONE && (i - 3 >= 0) && (i + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i - 4][j] == WHITESTONE && iOmokPan[i - 3][j] == WHITESTONE && iOmokPan[i - 2][j] == WHITESTONE && iOmokPan[i - 1][j] == WHITESTONE && (i - 4 >= 0))
						score += 5000;
				}

				//-------우상향대각--------//
				{
					// a●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 3 <= SIZE) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && iOmokPan[i - 4][j + 4] == BLACKSTONE && (i - 4 >= 0) && (j + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 3 <= SIZE) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i + 4][j - 4] == BLACKSTONE && iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && (i + 4 <= SIZE) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && iOmokPan[i - 3][j + 3] == BLACKSTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == BLACKSTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i + 3][j - 3] == BLACKSTONE && iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 3 <= SIZE) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i + 2][j - 2] == BLACKSTONE && iOmokPan[i + 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == BLACKSTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && iOmokPan[i - 3][j + 3] == WHITESTONE && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i + 3][j - 3] == WHITESTONE && iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 3 <= SIZE) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && iOmokPan[i - 3][j + 3] == WHITESTONE && iOmokPan[i - 4][j + 4] == WHITESTONE && (i - 4 >= 0) && (j + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && iOmokPan[i - 3][j + 3] == WHITESTONE && (i + 1 <= SIZE) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && iOmokPan[i - 2][j + 2] == WHITESTONE && (i + 2 <= SIZE) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i + 3][j - 3] == WHITESTONE && iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i + 3 <= SIZE) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i + 4][j - 4] == WHITESTONE && iOmokPan[i + 3][j - 3] == WHITESTONE && iOmokPan[i + 2][j - 2] == WHITESTONE && iOmokPan[i + 1][j - 1] == WHITESTONE && (i + 4 <= SIZE) && (j - 4 >= 0))
						score += 5000;
				}
				//-------좌상향대각--------//
				{
					// a●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 1;
					// ●a
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 10;
					// ●a●
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 10;
					// ●●a
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 2 >= 0) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 100;
					// ●a●●
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 100;
					// ●●a●
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 100;
					// ●●●a
					if (iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 3 >= 0) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && iOmokPan[i + 4][j + 4] == BLACKSTONE && (i + 4 <= SIZE) && (j + 4 <= SIZE))
						score += 1000;
					// ●a●●●
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 1000;
					// ●●a●●
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 1000;
					// ●●●a●
					if (iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 1000;
					// ●●●●a
					if (iOmokPan[i - 4][j - 4] == BLACKSTONE && iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && (i - 4 >= 0) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && iOmokPan[i + 3][j + 3] == BLACKSTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == BLACKSTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score -= 116;
					//       ●a○			1 + 5
					if (iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i - 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (iOmokPan[i - 3][j - 3] == BLACKSTONE && iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (iOmokPan[i - 2][j - 2] == BLACKSTONE && iOmokPan[i - 1][j - 1] == BLACKSTONE && iOmokPan[i + 1][j + 1] == BLACKSTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 5;
					//○a
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 50;
					//○a○
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 50;
					//○○a
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 2 >= 0) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && iOmokPan[i + 3][j + 3] == WHITESTONE && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 500;
					//○a○○
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 500;
					//○○a○
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 500;
					//○○○a
					if (iOmokPan[i - 3][j - 3] == WHITESTONE && iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 3 >= 0) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && iOmokPan[i + 3][j + 3] == WHITESTONE && iOmokPan[i + 4][j + 4] == WHITESTONE && (i + 4 <= SIZE) && (j + 4 <= SIZE))
						score += 5000;
					//○a○○○
					if (iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && iOmokPan[i + 3][j + 3] == WHITESTONE && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE) && (j + 3 <= SIZE))
						score += 5000;
					//○○a○○
					if (iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && iOmokPan[i + 2][j + 2] == WHITESTONE && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE) && (j + 2 <= SIZE))
						score += 5000;
					//○○○a○
					if (iOmokPan[i - 3][j - 3] == WHITESTONE && iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && iOmokPan[i + 1][j + 1] == WHITESTONE && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE) && (j + 1 <= SIZE))
						score += 5000;
					//○○○○a
					if (iOmokPan[i - 4][j - 4] == WHITESTONE && iOmokPan[i - 3][j - 3] == WHITESTONE && iOmokPan[i - 2][j - 2] == WHITESTONE && iOmokPan[i - 1][j - 1] == WHITESTONE && (i - 4 >= 0) && (j - 4 >= 0))
						score += 5000;


					//6목?
					//a○○○○○


				}


				// 점수 판별 및 힌트
				{
					if (WhiteHead->next == NULL)
					{
						HINT* p = (HINT*)malloc(sizeof(HINT));
						p->x = i;
						p->y = j;
						p->score = score;
						WhiteHead->next = p;
						p->next = WhiteHead->next;
						p->prev = WhiteHead->next;
					}
					else
					{
						// hint1
						if (WhiteHead->next->score < score)
						{
							HINT* p = (HINT*)malloc(sizeof(HINT));
							p->x = i;
							p->y = j;
							p->score = score;
							WhiteHead->next->prev = p;
							p->next = WhiteHead->next;
							WhiteHead->next = p;
						}
					}
				}
			}
		}
	}
	iOmokPan[WhiteHead->next->x][WhiteHead->next->y] = WHITESTONE;
}
void ResetHint()
{
	WhiteHead->next = NULL;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (iOmokPan[i][j] == HINT1 || iOmokPan[i][j] == HINT2 || iOmokPan[i][j] == HINT3)
				iOmokPan[i][j] = PAN;
		}
	}
}