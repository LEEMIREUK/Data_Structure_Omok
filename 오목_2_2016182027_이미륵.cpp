#include <stdio.h>
#include <Windows.h>
#define SIZE 19
#define PAN 0
#define BLACKSTONE 1
#define WHITESTONE 2
#define BLACKSTAR 3
#define WHITESTAR 4

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
bool CheckBlackStone();
bool CheckWhiteStone();

int main()
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		Draw();
		ShowStoneNum();
		InputXY();

		system("cls");
		Draw();
		PrintDoll();
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
				if (iOmokPan[i][j - 1] == BLACKSTONE && (j - 1 >= 0))
				{
					iBlackLen++;

				}
				if (iOmokPan[i][j - 1] == BLACKSTONE && (j - 1 >= 0) && iOmokPan[i][j + 1] != BLACKSTONE)
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
				if (iOmokPan[i][j - 1] == WHITESTONE && (j - 1 >= 0))
				{
					iWhiteLen++;
				}
				if (iOmokPan[i][j - 1] == WHITESTONE && (j - 1 >= 0) && iOmokPan[i][j + 1] != WHITESTONE)
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
				if (iOmokPan[i][j - i] == BLACKSTONE || iOmokPan[i][j - i] == BLACKSTAR)
				{
					iBlackAllCnt++;
					if (iBlackMax == 0)
						iBlackMax++;
					if (iOmokPan[i - 1][j - i + 1] == BLACKSTONE || iOmokPan[i - 1][j - i + 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[i - 1][j - i + 1] == BLACKSTONE && iOmokPan[i + 1][j - i - 1] != BLACKSTONE) || (iOmokPan[i - 1][j - i + 1] == BLACKSTAR && iOmokPan[i + 1][j - i - 1] != BLACKSTAR))
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
					if ((iOmokPan[i - 1][j - i + 1] == BLACKSTONE || iOmokPan[i - 1][j - i + 1] == BLACKSTAR) && (iOmokPan[i + 1][j - i - 1] != BLACKSTONE && iOmokPan[i + 1][j - i - 1] != BLACKSTAR))
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
					if ((iOmokPan[i - 1][j - i + 1] == WHITESTONE && iOmokPan[i + 1][j - i - 1] != WHITESTONE) || (iOmokPan[i - 1][j - i + 1] == WHITESTAR && iOmokPan[i + 1][j - i - 1] != WHITESTAR))
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
					if ((iOmokPan[i - 1][j - i + 1] == WHITESTONE || iOmokPan[i - 1][j - i + 1] == WHITESTAR) && (iOmokPan[i + 1][j - i - 1] != WHITESTONE && iOmokPan[i + 1][j - i - 1] != WHITESTAR))
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
					if (iOmokPan[18 - i + 1][i + j - 18 - 1] == BLACKSTONE || iOmokPan[18 - i + 1][i + j - 18 - 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[18 - i + 1][i + j - 18 - 1] == BLACKSTONE && iOmokPan[18 - i - 1][i + j - 18 + 1] != BLACKSTONE) || (iOmokPan[18 - i + 1][i + j - 18 - 1] == BLACKSTAR && iOmokPan[18 - i - 1][i + j - 18 + 1] != BLACKSTAR))
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
					if ((iOmokPan[18 - i + 1][i + j - 18 - 1] == BLACKSTONE || iOmokPan[18 - i + 1][i + j - 18 - 1] == BLACKSTAR) && (iOmokPan[18 - i - 1][i + j - 18 + 1] != BLACKSTONE && iOmokPan[18 - i - 1][i + j - 18 + 1] != BLACKSTAR))
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
					if (iOmokPan[18 - i + 1][i + j - 18 - 1] == WHITESTONE || iOmokPan[18 - i + 1][i + j - 18 - 1] == WHITESTAR)
					{
						iWhiteLen++;
						if (iWhiteLen > iWhiteMax)
							iWhiteMax = iWhiteLen;
					}
					if ((iOmokPan[18 - i + 1][i + j - 18 - 1] == WHITESTONE && iOmokPan[18 - i - 1][i + j - 18 + 1] != WHITESTONE) || (iOmokPan[18 - i + 1][i + j - 18 - 1] == WHITESTAR && iOmokPan[18 - i - 1][i + j - 18 + 1] != WHITESTAR))
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
					if ((iOmokPan[18 - i + 1][i + j - 18 - 1] == WHITESTONE || iOmokPan[18 - i + 1][i + j - 18 - 1] == WHITESTAR) && (iOmokPan[18 - i - 1][i + j - 18 + 1] != WHITESTONE && iOmokPan[18 - i - 1][i + j - 18 + 1] != WHITESTAR))
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
					if ((iOmokPan[i - 1][18 - j + i - 1] == BLACKSTONE && iOmokPan[i + 1][18 - j + i + 1] != BLACKSTONE) || (iOmokPan[i - 1][18 - j + i - 1] == BLACKSTAR && iOmokPan[i + 1][18 - j + i + 1] != BLACKSTAR))
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
					if ((iOmokPan[i - 1][18 - j + i - 1] == BLACKSTONE || iOmokPan[i - 1][18 - j + i - 1] == BLACKSTAR) && (iOmokPan[i - 1][18 - j + i - 1] != BLACKSTONE && iOmokPan[i - 1][18 - j + i - 1] != BLACKSTAR))
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
					if ((iOmokPan[i - 1][18 - j + i - 1] == WHITESTONE && iOmokPan[i + 1][18 - j + i + 1] != WHITESTONE) || (iOmokPan[i - 1][18 - j + i - 1] == WHITESTAR && iOmokPan[i + 1][18 - j + i + 1] != WHITESTAR))
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
					if ((iOmokPan[i - 1][18 - j + i - 1] == WHITESTONE || iOmokPan[i - 1][18 - j + i - 1] == WHITESTAR) && (iOmokPan[i - 1][18 - j + i - 1] != WHITESTONE && iOmokPan[i - 1][18 - j + i - 1] != WHITESTAR))
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
					if (iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTONE || iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTAR)
					{
						iBlackLen++;
						if (iBlackLen > iBlackMax)
							iBlackMax = iBlackLen;
					}
					if ((iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTONE && iOmokPan[-18 + j + i + 1][i + 1] != BLACKSTONE) || (iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTAR && iOmokPan[-18 + j + i + 1][i + 1] != BLACKSTAR))
					{
						if (iBlackLen + 1 > iBlackMax)
						{
							iBlackMax = iBlackLen + 1;
						}
						iBlackLen = 0;
					}
					if ((iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTONE || iOmokPan[-18 + j + i - 1][i - 1] == BLACKSTAR) && (iOmokPan[-18 + j + i - 1][i - 1] != BLACKSTONE && iOmokPan[-18 + j + i - 1][i - 1] != BLACKSTAR))
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
					if (iOmokPan[-18 + j + i - 1][i - 1] == WHITESTONE || iOmokPan[-18 + j + i - 1][i - 1] == WHITESTAR)
					{
						iWhiteLen++;
						if (iWhiteLen > iWhiteMax)
							iWhiteMax = iWhiteLen;
					}
					if ((iOmokPan[-18 + j + i - 1][i - 1] == WHITESTONE && iOmokPan[-18 + j + i + 1][i + 1] != WHITESTONE) || (iOmokPan[-18 + j + i - 1][i - 1] == WHITESTAR && iOmokPan[-18 + j + i + 1][i + 1] != WHITESTAR))
					{
						if (iWhiteLen + 1 > iWhiteMax)
						{
							iWhiteMax = iWhiteLen + 1;
						}
						iWhiteLen = 0;
					}
					if ((iOmokPan[-18 + j + i - 1][i - 1] == WHITESTONE || iOmokPan[-18 + j + i - 1][i - 1] == WHITESTAR) && (iOmokPan[-18 + j + i - 1][i - 1] != WHITESTONE && iOmokPan[-18 + j + i - 1][i - 1] != WHITESTAR))
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