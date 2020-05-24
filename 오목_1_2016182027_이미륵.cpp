#include <stdio.h>
#include <Windows.h>
#define SIZE 19
#define PAN 0
#define BLACKSTONE 1
#define WHITESTONE 2

int iOmokPan[SIZE][SIZE];
int iPlayerTurn = 1;		// black: 1   while: 2
int iBlackNum = 0;			// 검은돌 개수
int iWhiteNum = 0;			// 하얀돌 개수

void Draw();
void InputXY();
void ShowStoneNum();

int main()
{
	while (true)
	{
		system("cls");
		Draw();
		ShowStoneNum();
		InputXY();
		system("pause");
	}

	return 0;
}

void Draw()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (iOmokPan[i][j] == PAN)
				//printf("┼ ");
				printf("+ ");
			else if (iOmokPan[i][j] == BLACKSTONE)
				printf("○");
			else if (iOmokPan[i][j] == WHITESTONE)
				printf("●");
		}
		printf("\n");
	}
}

void InputXY()
{
	int iX, iY = 0;

	while (true)
	{
		printf("(x , y) : ");
		scanf_s("%d %d", &iX, &iY);

		if ((0 <= iX) && (iX <= 18) && (0 <= iY) && (iY <= 18))
		{
			if (iOmokPan[iX][iY] != PAN)
				printf("이미 돌이 놓여 있습니다.\n");
			else
				break;
		}
		else
			printf("범위를 벗어났습니다. 다시 입력해주세요.\n");
	}
	if (iPlayerTurn == 1)
	{
		iOmokPan[iX][iY] = BLACKSTONE;
		iBlackNum++;
	}
	else if (iPlayerTurn == 2)
	{
		iOmokPan[iX][iY] = WHITESTONE;
		iWhiteNum++;
	}

	if (iPlayerTurn == 1)
		iPlayerTurn = 2;
	else if (iPlayerTurn == 2)
		iPlayerTurn = 1;
}

void ShowStoneNum()
{
	printf("검은돌 개수: ");
	printf("%d", iBlackNum);

	printf("\t횐돌 개수: ");
	printf("%d", iWhiteNum);
	printf("\n");
}