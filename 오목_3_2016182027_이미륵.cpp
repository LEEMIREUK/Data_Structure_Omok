#include <stdio.h>
#include <Windows.h>

#define SIZE 19
#define PAN 0
#define BLACKSTONE 1
#define WHITESTONE 2
#define BLACKSTAR 3
#define WHITESTAR 4

typedef struct stack
{
	int iX, iY;
	int iDollColor;
	stack* pNext;
}NODE;

NODE* pSp = (NODE*)malloc(sizeof(NODE));
NODE* pSp_BackUp = (NODE*)malloc(sizeof(NODE));

int iOmokPan[SIZE][SIZE];
int iPlayerTurn = 1;		// black: 1   while: 2
int iBlackNum = 0;			// 검은돌 개수
int iWhiteNum = 0;			// 하얀돌 개수
int iBlackBigMax = 0;
int iWhiteBigMax = 0;
int iBlackBigMaxPos_j = 0;
int iWhiteBigMaxPos_j = 0;	
int iBlackBigMaxPos_i = 0;
int iWhiteBigMaxPos_i = 0;

void Draw();
void InputXY();
void ShowStoneNum();
void PrintDoll();
void Return();
void ReturnCancel();
void Save();
void Load();
void ChangeTurn();

int main()
{
	pSp = NULL;
	pSp_BackUp = NULL;

	while (true)
	{
		char cSelect;
		system("cls");

		Draw();
		printf("i/I: 돌입력  u/U: 무르기  r/R: 무르기 취소  s/S: 저장  c/C: 불러오기  q/Q: 종료\n");
		scanf_s("%c", &cSelect);
		while (getchar() != '\n');
		switch (cSelect)
		{
		case 'I':
		case 'i':
			InputXY();
			break;
		case 'u':
		case 'U':
			Return();
			break;
		case 'r':
		case 'R':
			ReturnCancel();
			break;
		case 's':
		case 'S':
			Save();
			break;
		case 'c':
		case 'C':
			Load();
			break;
		case 'q':
		case 'Q':
			return 0;
		default:
			break;
		}

		system("cls");
		Draw();
		ShowStoneNum();
		PrintDoll();
		system("pause");
	}
	free(pSp);
	free(pSp_BackUp);
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
			else if (iOmokPan[i][j] == BLACKSTAR)
				printf("☆");
			else if (iOmokPan[i][j] == WHITESTAR)
				printf("★");
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
		while (getchar() != '\n');

		if ((0 <= iX) && (iX <= 18) && (0 <= iY) && (iY <= 18))
		{
			if (iOmokPan[iX][iY] != PAN)
				printf("이미 돌이 놓여 있습니다.\n");
			else
			{
				NODE* pNew = (NODE*)malloc(sizeof(NODE));
				pNew->iX = iX;
				pNew->iY = iY;

				if (iPlayerTurn == 1)
					pNew->iDollColor = 1;
				else
					pNew->iDollColor = 2;
				pNew->pNext = pSp;
				pSp = pNew;

				pSp_BackUp = NULL;
				break;
			}
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

	ChangeTurn();
}

void ShowStoneNum()
{
	printf("검은돌 개수: ");
	printf("%d", iBlackNum);

	printf("\t횐돌 개수: ");
	printf("%d", iWhiteNum);
	printf("\n");
}

void PrintDoll()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (iOmokPan[i][j] == BLACKSTAR)
				iOmokPan[i][j] = BLACKSTONE;
			else if (iOmokPan[i][j] == WHITESTAR)
				iOmokPan[i][j] = WHITESTONE;
		}
	}
	// 가로 출력
	printf("-------가로-------\n");
	for (int i = 0; i < SIZE; ++i)
	{
		int iScanMax = 0;
		int iBlackMax = 0;
		int iWhiteMax = 0;
		int iBlackPosS = 0;
		int iBlackPosE = 0;
		int iWhitePosS = 0;
		int iWhitePosE = 0;
		int iBlackAllCnt = 0;
		int iWhiteAllCnt = 0;
		int iBlackLen = 0;
		int iWhiteLen = 0;
		for (int j = 0; j < SIZE; ++j)
		{
			// 검은색이면?
			if (iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
			{
				iBlackAllCnt++;
				if (iBlackMax == 0)
					iBlackMax++;
				// 이전것이 검은색이면?
				if (iOmokPan[i][j - 1] == BLACKSTONE || iOmokPan[i][j - 1] == BLACKSTAR)
				{
					iBlackLen++;
					if (iBlackLen > iBlackMax)
						iBlackMax = iBlackLen;
				}
				// 이전것이 검은색, 다음게 검은색이 아니면?
				if ((iOmokPan[i][j - 1] == BLACKSTONE || iOmokPan[i][j - 1] == BLACKSTAR) && iOmokPan[i][j + 1] != BLACKSTONE && iOmokPan[i][j + 1] != BLACKSTAR)
				{
					if (iBlackLen + 1 > iBlackMax)
					{
						iBlackMax = iBlackLen + 1;
						iBlackPosE = j;
						iBlackPosS = j - iBlackLen;
					}
					iBlackLen = 0;
				}
			}
			else if (iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
			{
				iWhiteAllCnt++;
				if (iWhiteMax == 0)
					iWhiteMax++;
				if (iOmokPan[i][j - 1] == WHITESTONE || iOmokPan[i][j - 1] == WHITESTAR)
				{
					iWhiteLen++;
					if (iWhiteLen > iWhiteMax)
						iWhiteMax = iWhiteLen;
				}
				if ((iOmokPan[i][j - 1] == WHITESTONE || iOmokPan[i][j - 1] == WHITESTAR) && iOmokPan[i][j + 1] != WHITESTONE && iOmokPan[i][j + 1] != WHITESTAR)
				{
					if (iWhiteLen + 1 > iWhiteMax)
					{
						iWhiteMax = iWhiteLen + 1;
						iWhitePosE = j;
						iWhitePosS = j - iWhiteLen;
					}
					iWhiteLen = 0;
				}
			}
		}
		// 스캔 끝 
		for (int j = 0; j < SIZE; ++j)
		{
			if (iOmokPan[i][j] == BLACKSTONE)
			{
				if (iOmokPan[i][j - 1] == BLACKSTONE)
				{
					iBlackLen++;

				}
				if (iOmokPan[i][j - 1] == BLACKSTONE && iOmokPan[i][j + 1] != BLACKSTONE)
				{
					if (iBlackLen + 1 == iBlackMax)
					{
						if (iBlackMax >= iWhiteMax)
						{
							for (int k = iBlackPosE; k > iBlackPosS - 1; --k)
								iOmokPan[i][k] = BLACKSTAR;
						}
					}
					iBlackLen = 0;
				}
			}
			else if (iOmokPan[i][j] == WHITESTONE)
			{
				if (iOmokPan[i][j - 1] == WHITESTONE)
				{
					iWhiteLen++;
				}
				if (iOmokPan[i][j - 1] == WHITESTONE && iOmokPan[i][j + 1] != WHITESTONE)
				{
					if (iWhiteLen + 1 == iWhiteMax)
					{
						if (iBlackMax <= iWhiteMax)
						{
							for (int k = iWhitePosE; k > iWhitePosS - 1; --k)
								iOmokPan[i][k] = WHITESTAR;
						}
					}
					iWhiteLen = 0;
				}
			}
		}
		if (iBlackMax < iWhiteMax)
		{
			if (i < 10)
			{
				printf("%d  B%d  W%d  MAX W%d\n", i, iBlackAllCnt, iWhiteAllCnt, iWhiteMax);
			}
			else
			{
				printf("%c  B%d  W%d  MAX W%d\n", i + 55, iBlackAllCnt, iWhiteAllCnt, iWhiteMax);
			}
		}
		else if (iBlackMax > iWhiteMax)
		{
			if (i < 10)
			{
				printf("%d  B%d  W%d  MAX B%d\n", i, iBlackAllCnt, iWhiteAllCnt, iBlackMax);
			}
			else
			{
				printf("%c  B%d  W%d  MAX B%d\n", i + 55, iBlackAllCnt, iWhiteAllCnt, iBlackMax);
			}
		}
		else
		{
			if (i < 10)
			{
				printf("%d  B%d  W%d  MAX B%d  W%d\n", i, iBlackAllCnt, iWhiteAllCnt, iBlackMax, iWhiteMax);
			}
			else
			{
				printf("%c  B%d  W%d  MAX B%d  W%d\n", i + 55, iBlackAllCnt, iWhiteAllCnt, iBlackMax, iWhiteMax);
			}
		}
	}
	// 세로 출력	
	printf("-------세로-------\n");
	for (int i = 0; i < SIZE; ++i)
	{
		int iBlackMax = 0;
		int iWhiteMax = 0;
		int iBlackAllCnt = 0;
		int iWhiteAllCnt = 0;
		int iBlackLen = 0;
		int iWhiteLen = 0;
		for (int j = 0; j < SIZE; ++j)
		{
			// 검은색이면?
			if (iOmokPan[j][i] == BLACKSTONE || iOmokPan[j][i] == BLACKSTAR)
			{
				iBlackAllCnt++;
				if (iBlackMax == 0)
					iBlackMax++;
				// 이전것이 검은색이면?
				if (iOmokPan[j - 1][i] == BLACKSTONE || iOmokPan[j - 1][i] == BLACKSTAR)
				{
					iBlackLen++;
					if (iBlackLen > iBlackMax)
						iBlackMax = iBlackLen;
				}
				// 이전것이 검은색, 다음게 검은색이 아니면?
				if ((iOmokPan[j - 1][i] == BLACKSTONE || iOmokPan[j - 1][i] == BLACKSTAR) && iOmokPan[j + 1][i] != BLACKSTONE && iOmokPan[j + 1][i] != BLACKSTAR)
				{
					if (iBlackLen + 1 > iBlackMax)
					{
						iBlackMax = iBlackLen + 1;
					}
					iBlackLen = 0;
				}
			}
			else if (iOmokPan[j][i] == WHITESTONE || iOmokPan[j][i] == WHITESTAR)
			{
				iWhiteAllCnt++;
				if (iWhiteMax == 0)
					iWhiteMax++;
				if (iOmokPan[j - 1][i] == WHITESTONE || iOmokPan[j - 1][i] == WHITESTAR)
				{
					iWhiteLen++;
					if (iWhiteLen > iWhiteMax)
						iWhiteMax = iWhiteLen;
				}
				if ((iOmokPan[j - 1][i] == WHITESTONE || iOmokPan[j - 1][i] == WHITESTAR) && iOmokPan[j + 1][i] != WHITESTONE && iOmokPan[j + 1][i] != WHITESTAR)
				{
					if (iWhiteLen + 1 > iWhiteMax)
					{
						iWhiteMax = iWhiteLen + 1;
					}
					iWhiteLen = 0;
				}
			}
		}

		if (iBlackMax < iWhiteMax)
		{
			if (i < 10)
			{
				printf("%d  B%d  W%d  MAX W%d\n", i, iBlackAllCnt, iWhiteAllCnt, iWhiteMax);
			}
			else
			{
				printf("%c  B%d  W%d  MAX W%d\n", i + 55, iBlackAllCnt, iWhiteAllCnt, iWhiteMax);
			}
		}
		else if (iBlackMax > iWhiteMax)
		{
			if (i < 10)
			{
				printf("%d  B%d  W%d  MAX B%d\n", i, iBlackAllCnt, iWhiteAllCnt, iBlackMax);
			}
			else
			{
				printf("%c  B%d  W%d  MAX B%d\n", i + 55, iBlackAllCnt, iWhiteAllCnt, iBlackMax);
			}
		}
		else
		{
			if (i < 10)
			{
				printf("%d  B%d  W%d  MAX B%d  W%d\n", i, iBlackAllCnt, iWhiteAllCnt, iBlackMax, iWhiteMax);
			}
			else
			{
				printf("%c  B%d  W%d  MAX B%d  W%d\n", i + 55, iBlackAllCnt, iWhiteAllCnt, iBlackMax, iWhiteMax);
			}
		}
	}
	//우상향 대각
	printf("-------우상향대각선-------\n");
	for (int j = 0; j < 37; ++j)
	{
		int iBlackMax = 0;
		int iWhiteMax = 0;
		int iBlackAllCnt = 0;
		int iWhiteAllCnt = 0;
		int iBlackLen = 0;
		int iWhiteLen = 0;
		if (j < 19)
		{
			for (int i = 0; i <= j; ++i)
			{
				// 검은색인가?
				if (iOmokPan[i][j - i] == BLACKSTONE || iOmokPan[i][j - i] == BLACKSTAR)
				{
					iBlackAllCnt++;
					if (iBlackMax == 0)
						iBlackMax++;
					// 오른쪽 위 대각선이 검은색인가?
					if (iOmokPan[i - 1][j - i + 1] == BLACKSTONE || iOmokPan[i - 1][j - i + 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[i - 1][j - i + 1] == BLACKSTONE || iOmokPan[i - 1][j - i + 1] == BLACKSTAR) && iOmokPan[i + 1][j - i - 1] != BLACKSTONE && iOmokPan[i + 1][j - i - 1] != BLACKSTAR)
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
				}
				else if (iOmokPan[i][j - i] == WHITESTONE || iOmokPan[i][j - i] == WHITESTAR)
				{
					iWhiteAllCnt++;
					if (iWhiteMax == 0)
						iWhiteMax++;
					if (iOmokPan[i - 1][j - i + 1] == WHITESTONE || iOmokPan[i - 1][j - i + 1] == WHITESTAR)
					{
						iWhiteLen++;
						if (iWhiteLen > iWhiteMax)
							iWhiteMax = iWhiteLen;
					}
					if ((iOmokPan[i - 1][j - i + 1] == WHITESTONE || iOmokPan[i - 1][j - i + 1] == WHITESTAR) && iOmokPan[i + 1][j - i - 1] != WHITESTONE && iOmokPan[i + 1][j - i - 1] != WHITESTAR)
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
				}
			}
		}
		else if (j >= 19)
		{
			for (int i = 0; i < 37 - j; ++i)
			{
				if (iOmokPan[18 - i][i + j - 18] == BLACKSTONE || iOmokPan[18 - i][i + j - 18] == BLACKSTAR)
				{
					iBlackAllCnt++;
					if (iBlackMax == 0)
						iBlackMax++;
					if (iOmokPan[18 - i - 1][i + j - 18 + 1] == BLACKSTONE || iOmokPan[18 - i - 1][i + j - 18 + 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[18 - i - 1][i + j - 18 + 1] == BLACKSTONE || iOmokPan[18 - i - 1][i + j - 18 + 1] == BLACKSTAR) && iOmokPan[18 - i + 1][i + j - 18 - 1] != BLACKSTONE && iOmokPan[18 - i + 1][i + j - 18 - 1] != BLACKSTAR)
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
				}
				if (iOmokPan[18 - i][i + j - 18] == WHITESTONE || iOmokPan[18 - i][i + j - 18] == WHITESTAR)
				{
					iWhiteAllCnt++;
					if (iWhiteMax == 0)
						iWhiteMax++;
					if (iOmokPan[18 - i - 1][i + j - 18 + 1] == WHITESTONE || iOmokPan[18 - i - 1][i + j - 18 + 1] == WHITESTAR)
					{
						iWhiteLen++;
						if (iWhiteLen > iWhiteMax)
							iWhiteMax = iWhiteLen;
					}
					if ((iOmokPan[18 - i - 1][i + j - 18 + 1] == WHITESTONE || iOmokPan[18 - i - 1][i + j - 18 + 1] == WHITESTAR) && iOmokPan[18 - i + 1][i + j - 18 - 1] != WHITESTONE && iOmokPan[18 - i + 1][i + j - 18 - 1] != WHITESTAR)
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
				}
			}
		}

		// 출력
		if (iBlackMax < iWhiteMax)
		{
			if (j <= 9)
				printf(" (%d,%d) (%d,%d)  MAX W%d\n", j, 0, 0, j, iWhiteMax);
			else if (j < 19 && j > 9)
				printf(" (%c,%d) (%d,%c)  MAX W%d\n", j + 55, 0, 0, j + 55, iWhiteMax);
			else if (j >= 19 && j < 27)
				printf(" (%c,%d) (%d,%c)  MAX W%d\n", 18 + 55, j - 18, j - 18, 18 + 55, iWhiteMax);
			else if (j > 27)
				printf(" (%c,%c) (%c,%c)  MAX W%d\n", 18 + 55, j - 18 + 55, j - 18 + 55, 18 + 55, iWhiteMax);
		}
		else if (iBlackMax > iWhiteMax)
		{
			if (j <= 9)
				printf(" (%d,%d) (%d,%d)  MAX B%d\n", j, 0, 0, j, iBlackMax);
			else if (j < 19 && j > 9)
				printf(" (%c,%d) (%d,%c)  MAX B%d\n", j + 55, 0, 0, j + 55, iBlackMax);
			else if (j >= 19 && j < 27)
				printf(" (%c,%d) (%d,%c)  MAX B%d\n", 18 + 55, j - 18, j - 18, 18 + 55, iBlackMax);
			else if (j > 27)
				printf(" (%c,%c) (%c,%c)  MAX B%d\n", 18 + 55, j - 18 + 55, j - 18 + 55, 18 + 55, iBlackMax);
		}
		else
		{
			if (j <= 9)
				printf(" (%d,%d) (%d,%d)  MAX B%d  W%d\n", j, 0, 0, j, iBlackMax, iWhiteMax);
			else if (j < 19 && j > 9)
				printf(" (%c,%d) (%d,%c)  MAX B%d  W%d\n", j + 55, 0, 0, j + 55, iBlackMax, iWhiteMax);
			else if (j >= 19 && j < 27)
				printf(" (%c,%d) (%d,%c)  MAX B%d  W%d\n", 18 + 55, j - 18, j - 18, 18 + 55, iBlackMax, iWhiteMax);
			else if (j > 27)
				printf(" (%c,%c) (%c,%c)  MAX B%d  W%d\n", 18 + 55, j - 18 + 55, j - 18 + 55, 18 + 55, iBlackMax, iWhiteMax);
		}
	}
	// 좌상향대각
	printf("-------좌상향대각선-------\n");
	for (int j = 0; j < 37; ++j)
	{
		int iBlackMax = 0;
		int iWhiteMax = 0;
		int iBlackAllCnt = 0;
		int iWhiteAllCnt = 0;
		int iBlackLen = 0;
		int iWhiteLen = 0;
		if (j < 19)
		{
			for (int i = 0; i <= j; ++i)
			{
				if (iOmokPan[i][18 - j + i] == BLACKSTONE || iOmokPan[i][18 - j + i] == BLACKSTAR)
				{
					iBlackAllCnt++;
					if (iBlackMax == 0)
						iBlackMax++;
					if (iOmokPan[i - 1][18 - j + i - 1] == BLACKSTONE || iOmokPan[i - 1][18 - j + i - 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[i - 1][18 - j + i - 1] == BLACKSTONE || iOmokPan[i - 1][18 - j + i - 1] == BLACKSTAR) && iOmokPan[i + 1][18 - j + i + 1] != BLACKSTONE && iOmokPan[i + 1][18 - j + i + 1] != BLACKSTAR)
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
				}
				else if (iOmokPan[i][18 - j + i] == WHITESTONE || iOmokPan[i][18 - j + i] == WHITESTAR)
				{
					iWhiteAllCnt++;
					if (iWhiteMax == 0)
						iWhiteMax++;
					if (iOmokPan[i - 1][18 - j + i - 1] == WHITESTONE || iOmokPan[i - 1][18 - j + i - 1] == WHITESTAR)
					{
						iWhiteLen++;
						if (iWhiteLen > iWhiteMax)
							iWhiteMax = iWhiteLen;
					}
					if ((iOmokPan[i - 1][18 - j + i - 1] == WHITESTONE || iOmokPan[i - 1][18 - j + i - 1] == WHITESTAR) && iOmokPan[i + 1][18 - j + i + 1] != WHITESTONE && iOmokPan[i + 1][18 - j + i + 1] != WHITESTAR)
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
				}
			}
		}
		else if (j >= 19)
		{
			for (int i = 0; i < 37 - j; ++i)
			{
				if (iOmokPan[-18 + j + i][i] == BLACKSTONE || iOmokPan[-18 + j + i][i] == BLACKSTAR)
				{
					iBlackAllCnt++;
					if (iBlackMax == 0)
						iBlackMax++;
					if (iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTONE || iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTONE || iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTAR) && iOmokPan[-18 + j + i + 1][i + 1] != BLACKSTONE && iOmokPan[-18 + j + i + 1][i + 1] != BLACKSTAR)
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
				}
				else if (iOmokPan[-18 + j + i][i] == WHITESTONE || iOmokPan[-18 + j + i][i] == WHITESTAR)
				{
					iWhiteAllCnt++;
					if (iWhiteMax == 0)
						iWhiteMax++;
					if (iOmokPan[-18 + j + i - 1][i - 1] == WHITESTONE || iOmokPan[-18 + j + i - 1][i - 1] == WHITESTAR)
					{
						iWhiteLen++;
						if (iWhiteLen > iWhiteMax)
							iWhiteMax = iWhiteLen;
					}
					if ((iOmokPan[-18 + j + i - 1][i - 1] == WHITESTONE || iOmokPan[-18 + j + i - 1][i - 1] == WHITESTAR) && iOmokPan[-18 + j + i + 1][i + 1] != WHITESTONE && iOmokPan[-18 + j + i + 1][i + 1] != WHITESTAR)
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
				}
			}
		}
		// 출력
		if (iBlackMax < iWhiteMax)
		{
			if (j < 9)
				printf(" (%d,%c) (%d,%c)  MAX W%d\n", 0, (18 - j) + 55, j, 18 + 55, iWhiteMax);
			else if (j == 9)
				printf(" (%d,%d) (%d,%c)  MAX W%d\n", 0, 18 - j, j, 18 + 55, iWhiteMax);
			else if (j < 19 && j > 9)
				printf(" (%d,%d) (%c,%c)  MAX W%d\n", 0, 18 - j, j + 55, 18 + 55, iWhiteMax);
			else if (j >= 19 && j < 27)
				printf(" (%d,%d) (%c,%c)  MAX W%d\n", j - 18, 0, 18 + 55, (37 - j - 1) + 55, iWhiteMax);
			else if (j == 27)
				printf(" (%d,%d) (%c,%d)  MAX W%d\n", j - 18, 0, 18 + 55, 37 - j - 1, iWhiteMax);
			else if (j > 27)
				printf(" (%c,%d) (%c,%d)  MAX W%d\n", (j - 18) + 55, 0, 18 + 55, 37 - j - 1, iWhiteMax);
		}
		else if (iBlackMax > iWhiteMax)
		{
			if (j < 9)
				printf(" (%d,%c) (%d,%c)  MAX B%d\n", 0, (18 - j) + 55, j, 18 + 55, iBlackMax);
			else if (j == 9)
				printf(" (%d,%d) (%d,%c)  MAX B%d\n", 0, 18 - j, j, 18 + 55, iBlackMax);
			else if (j < 19 && j > 9)
				printf(" (%d,%d) (%c,%c)  MAX B%d\n", 0, 18 - j, j + 55, 18 + 55, iBlackMax);
			else if (j >= 19 && j < 27)
				printf(" (%d,%d) (%c,%c)  MAX B%d\n", j - 18, 0, 18 + 55, (37 - j - 1) + 55, iBlackMax);
			else if (j == 27)
				printf(" (%d,%d) (%c,%d)  MAX B%d\n", j - 18, 0, 18 + 55, 37 - j - 1, iBlackMax);
			else if (j > 27)
				printf(" (%c,%d) (%c,%d)  MAX B%d\n", (j - 18) + 55, 0, 18 + 55, 37 - j - 1, iBlackMax);
		}
		else
		{
			if (j < 9)
				printf(" (%d,%c) (%d,%c)  MAX B%d  W%d\n", 0, (18 - j) + 55, j, 18 + 55, iBlackMax, iWhiteMax);
			else if (j == 9)
				printf(" (%d,%d) (%d,%c)  MAX B%d  W%d\n", 0, 18 - j, j, 18 + 55, iBlackMax, iWhiteMax);
			else if (j < 19 && j > 9)
				printf(" (%d,%d) (%c,%c)  MAX B%d  W%d\n", 0, 18 - j, j + 55, 18 + 55, iBlackMax, iWhiteMax);
			else if (j >= 19 && j < 27)
				printf(" (%d,%d) (%c,%c)  MAX B%d  W%d\n", j - 18, 0, 18 + 55, (37 - j - 1) + 55, iBlackMax, iWhiteMax);
			else if (j == 27)
				printf(" (%d,%d) (%c,%d)  MAX B%d  W%d\n", j - 18, 0, 18 + 55, 37 - j - 1, iBlackMax, iWhiteMax);
			else if (j > 27)
				printf(" (%c,%d) (%c,%d)  MAX B%d  W%d\n", (j - 18) + 55, 0, 18 + 55, 37 - j - 1, iBlackMax, iWhiteMax);
		}
	}
}

void Return()
{
	if (pSp != NULL)
	{
		NODE* pNew_BackUp = (NODE*)malloc(sizeof(NODE));
		NODE* pTarget = (NODE*)malloc(sizeof(NODE));
		pNew_BackUp->iX = pSp->iX;
		pNew_BackUp->iY = pSp->iY;
		pNew_BackUp->iDollColor = pSp->iDollColor;

		pNew_BackUp->pNext = pSp_BackUp;
		pSp_BackUp = pNew_BackUp;

		pTarget = pSp;
		pSp = pSp->pNext;
		iOmokPan[pTarget->iX][pTarget->iY] = PAN;
		pTarget->pNext = NULL;

		ChangeTurn();
	}
}

void ReturnCancel()
{
	if (pSp_BackUp != NULL)
	{
		NODE* pNew = (NODE*)malloc(sizeof(NODE));
		NODE* pTarget = (NODE*)malloc(sizeof(NODE));
		pNew->iX = pSp_BackUp->iX;
		pNew->iY = pSp_BackUp->iY;
		pNew->iDollColor = pSp_BackUp->iDollColor;
		pNew->pNext = pSp;
		pSp = pNew;

		if (iPlayerTurn == 1)
			iOmokPan[pSp->iX][pSp->iY] = BLACKSTONE;
		else
			iOmokPan[pSp->iX][pSp->iY] = WHITESTONE;

		pTarget = pSp_BackUp;
		pSp_BackUp = pSp_BackUp->pNext;
		pTarget->pNext = NULL;

		ChangeTurn();
	}
}

void Save()
{
	if (pSp != NULL)
	{
		FILE* fp = NULL;
		errno_t err = fopen_s(&fp, "../Data.txt", "wt");

		if (err == 0)
		{
			printf("저장성공\n");
			NODE* q = (NODE*)malloc(sizeof(NODE));
			q = NULL;
			while(true)
			{
				for (NODE* p = pSp; p != NULL; p = p->pNext)
				{
					if (p->pNext == q)
					{
						fprintf(fp, "%d %d %d\n", p->iX, p->iY, p->iDollColor);
						q = p;
					}
				}
				if (q == pSp)
					break;
			}
		}
		fclose(fp);
	}

	if (pSp_BackUp != NULL)
	{
		FILE* fp_back = NULL;
		errno_t err_back = fopen_s(&fp_back, "../BackUpData.txt", "wt");

		if (err_back == 0)
		{
			printf("저장성공\n");
			NODE* q_back = (NODE*)malloc(sizeof(NODE));
			q_back = NULL;
			while (true)
			{
				for (NODE* p_back = pSp_BackUp; p_back != NULL; p_back = p_back->pNext)
				{
					if (p_back->pNext == q_back)
					{
						fprintf(fp_back, "%d %d %d\n", p_back->iX, p_back->iY, p_back->iDollColor);
						q_back = p_back;
					}
				}
				if (q_back == pSp_BackUp)
					break;
			}
		}
		fclose(fp_back);
	}
}

void Load()
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			iOmokPan[i][j] = PAN;

	int iBlackCnt = 0, iWhiteCnt = 0;

	FILE* fp = NULL;
	errno_t err = fopen_s(&fp, "../Data.txt", "rt");

	if (err == 0)
	{
		printf("불러오기 성공\n");
		pSp = NULL;
		while (feof(fp) == 0)
		{
			NODE* pNew = (NODE*)malloc(sizeof(NODE));
			fscanf_s(fp, "%d %d %d\n", &pNew->iX, &pNew->iY, &pNew->iDollColor);
			pNew->pNext = pSp;
			pSp = pNew;

			iOmokPan[pSp->iX][pSp->iY] = pSp->iDollColor;

			if (iOmokPan[pNew->iX][pNew->iY] == BLACKSTONE)
				iBlackCnt++;
			else if (iOmokPan[pNew->iX][pNew->iY] == WHITESTONE)
				iWhiteCnt++;
		}
		if (iBlackCnt <= iWhiteCnt)
			iPlayerTurn = 1;
		else
			iPlayerTurn = 2;
	}
	fclose(fp);

	FILE* fp_back = NULL;
	errno_t err_back = fopen_s(&fp_back, "../BackUpData.txt", "rt");

	if (err_back == 0)
	{
		printf("불러오기 성공\n");
		pSp_BackUp = NULL;
		while (feof(fp_back) == 0)
		{
			NODE* pNew_BackUp = (NODE*)malloc(sizeof(NODE));
			fscanf_s(fp_back, "%d %d %d\n", &pNew_BackUp->iX, &pNew_BackUp->iY, &pNew_BackUp->iDollColor);
			pNew_BackUp->pNext = pSp_BackUp;
			pSp_BackUp = pNew_BackUp;
		}
	}
	fclose(fp_back);

}

void ChangeTurn()
{
	if (iPlayerTurn == 1)
		iPlayerTurn = 2;
	else if (iPlayerTurn == 2)
		iPlayerTurn = 1;
}