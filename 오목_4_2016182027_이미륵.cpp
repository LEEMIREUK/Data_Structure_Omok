#include <stdio.h>
#include <Windows.h>

#define SIZE		19
#define PAN			0
#define BLACKSTONE	1
#define WHITESTONE	2
#define BLACKSTAR	3
#define WHITESTAR	4
#define DEFENCE		5

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

void Draw();
void InputXY();
void ShowStoneNum();
void Return();
void ReturnCancel();
void Save();
void Load();
void ChangeTurn();
void ContiDoll();
void Defence();

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
		ContiDoll();
		Defence();
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
			else if (iOmokPan[i][j] == DEFENCE)
				printf("◎");
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
			if (iOmokPan[iX][iY] != PAN && iOmokPan[iX][iY] != DEFENCE)
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
			while (true)
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

void ContiDoll()
{
	// 초기화
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (iOmokPan[i][j] == BLACKSTAR)
				iOmokPan[i][j] = BLACKSTONE;
			else if (iOmokPan[i][j] == WHITESTAR)
				iOmokPan[i][j] = WHITESTONE;
			if (iOmokPan[i][j] == DEFENCE)
				iOmokPan[i][j] = PAN;
		}
	}

	int iState = 0;									// 이전을 뜻함		- pan = 0 black = 1 white = 2
	int iLen = 0;									// 현재 길이		- MAX찾으면 초기화
	int iMaxLen = 0;								// 최대 길이
	int iCntDoll = 0;								// 현재 돌개수		- MAX찾으면 초기화
	int iMaxDoll = 0;								// 최대 돌개수
	int iMaxX = 0, iMaxY = 0;						// 최대일떄 좌표
	int iDir = -1;									// 최대일때 방향	- 가로1 세로 2 우상향 3 좌상향 4
	int iSpaceCnt = 0;								// 빈공간 카운트	- MAX찾으면 초기화
	int iMaxDollColor = 0;							// 최대 돌 색깔		- black = 1 white = 2
	// 가로1
	for (int i = 0; i < SIZE; ++i)
	{
		iState = 0;
		iCntDoll = 0;
		iLen = 0;
		iSpaceCnt = 0;
		iMaxDollColor = 0;
		for (int j = 0; j < SIZE; ++j)
		{
			// 현재 빈칸
			if (iOmokPan[i][j] == PAN || iOmokPan[i][j] == DEFENCE)
			{
				// 빈 빈 ?
				if (iState == PAN)
				{
					// 빈 빈 빈
					// 빈 빈 검
					// 빈 빈 흰
				}
				// 검 빈 ?
				else if (iState == BLACKSTONE)
				{
					iSpaceCnt = 0;
					// 검 빈 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE) {}
					// 검 빈 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE)
					{
						iSpaceCnt++;
						iLen++;
					}
					// 검 빈 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE) {}
				}
				// 흰 빈 ?
				else if (iState == WHITESTONE)
				{
					iSpaceCnt = 0;
					// 흰 빈 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE) {}
					//  흰 빈 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE) {}
					// 흰 빈 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE)
					{
						iSpaceCnt++;
						iLen++;
					}
				}
				iState = PAN;
			}
			// 현재 검은돌
			else if (iOmokPan[i][j] == BLACKSTONE)
			{
				// 빈 검 ?
				if (iState == PAN)
				{
					iCntDoll++;
					iLen++;
					// 빈 검 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 1;
								iMaxDollColor = 1;
							}
						}
					}
					// 빈 검 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE) {}
					// 빈 검 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 1;
								iMaxDollColor = 1;
							}
						}
					}
				}
				// 검 검 ?
				else if (iState == BLACKSTONE)
				{
					iCntDoll++;
					iLen++;
					// 검 검 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE)
					{
						if (iOmokPan[i][j + 2] != BLACKSTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 1;
								iMaxDollColor = 1;
							}
						}
					}
					// 검 검 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE) {}
					// 검 검 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE)
					{
						if (iMaxLen < iLen)
						{
							iMaxDoll = iCntDoll;
							iMaxLen = iLen;
							iMaxX = i;
							iMaxY = j;
							iCntDoll = 0;
							iLen = 0;
							iSpaceCnt = 0;
							iDir = 1;
							iMaxDollColor = 1;
						}
					}
				}
				// 흰 검 ?
				else if (iState == WHITESTONE)
				{
					iCntDoll = 0;
					iLen = 0;
					iSpaceCnt = 0;
					// 흰 검 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE)
					{
						iCntDoll++;
						iLen++;
					}
					// 흰 검 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE)
					{
						iCntDoll++;
						iLen++;
					}
					// 흰 검 흰
					if (iOmokPan[i][j + 1] == WHITESTONE) {}
				}
				iState = BLACKSTONE;
			}
			// 현재 흰돌
			else if (iOmokPan[i][j] == WHITESTONE)
			{
				// 빈 흰 ?
				if (iState == PAN)
				{
					iCntDoll++;
					iLen++;
					// 빈 흰 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 1;
								iMaxDollColor = 2;
							}
						}
					}
					// 빈 흰 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 1;
								iMaxDollColor = 2;
							}
						}
					}
					// 빈 흰 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE) {}
				}
				// 검 흰 ?
				else if (iState == BLACKSTONE)
				{
					iCntDoll = 0;
					iLen = 0;
					iSpaceCnt = 0;
					// 검 흰 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE)
					{
						iCntDoll++;
						iLen++;
					}
					// 검 흰 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE) {}
					// 검 흰 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE)
					{
						iCntDoll++;
						iLen++;
					}
				}
				// 흰 흰 ?
				else if (iState == WHITESTONE)
				{
					iCntDoll++;
					iLen++;
					// 흰 흰 빈
					if (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE)
					{
						if(iOmokPan[i][j+2] != WHITESTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 1;
								iMaxDollColor = 2;
							}
						}
					}
					// 흰 흰 검
					else if (iOmokPan[i][j + 1] == BLACKSTONE)
					{
						if (iMaxLen < iLen)
						{
							iMaxDoll = iCntDoll;
							iMaxLen = iLen;
							iMaxX = i;
							iMaxY = j;
							iCntDoll = 0;
							iLen = 0;
							iSpaceCnt = 0;
							iDir = 1;
							iMaxDollColor = 2;
						}
					}
					// 흰 흰 흰
					else if (iOmokPan[i][j + 1] == WHITESTONE) {}
				}
				iState = WHITESTONE;
			}
		}
	}
	// 세로
	for (int i = 0; i < SIZE; ++i)
	{
		iState = 0;
		iCntDoll = 0;
		iLen = 0;
		iSpaceCnt = 0;
		iMaxDollColor = 0;
		for (int j = 0; j < SIZE; ++j)
		{
			// 현재 빈칸
			if (iOmokPan[j][i] == PAN)
			{
				// 빈 빈 ?
				if (iState == PAN)
				{
					// 빈 빈 빈
					// 빈 빈 검
					// 빈 빈 흰
				}
				// 검 빈 ?
				else if (iState == BLACKSTONE)
				{
					iSpaceCnt = 0;
					// 검 빈 빈
					if (iOmokPan[j+1][i] == PAN) {}
					// 검 빈 검
					else if (iOmokPan[j+1][i] == BLACKSTONE)
					{
						iSpaceCnt++;
						iLen++;
					}
					// 검 빈 흰
					else if (iOmokPan[j+1][i] == WHITESTONE) {}
				}
				// 흰 빈 ?
				else if (iState == WHITESTONE)
				{
					iSpaceCnt = 0;
					// 흰 빈 빈
					if (iOmokPan[j + 1][i] == PAN) {}
					//  흰 빈 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE) {}
					// 흰 빈 흰
					else if (iOmokPan[j + 1][i] == WHITESTONE)
					{
						iSpaceCnt++;
						iLen++;
					}
				}
				iState = PAN;
			}
			// 현재 검은돌
			else if (iOmokPan[j][i] == BLACKSTONE)
			{
				// 빈 검 ?
				if (iState == PAN)
				{
					iCntDoll++;
					iLen++;
					// 빈 검 빈
					if (iOmokPan[j + 1][i] == PAN)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = j;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 2;
								iMaxDollColor = 1;
							}
						}
					}
					// 빈 검 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE) {}
					// 빈 검 흰
					else if (iOmokPan[j + 1][i] == WHITESTONE)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = j;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 2;
								iMaxDollColor = 1;
							}
						}
					}
				}
				// 검 검 ?
				else if (iState == BLACKSTONE)
				{
					iCntDoll++;
					iLen++;
					// 검 검 빈
					if (iOmokPan[j + 1][i] == PAN)
					{
						if (iOmokPan[j + 2][i] != BLACKSTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = j;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 2;
								iMaxDollColor = 1;
							}
						}
					}
					// 검 검 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE) {}
					// 검 검 흰
					else if (iOmokPan[j + 1][i] == WHITESTONE)
					{
						if (iMaxLen < iLen)
						{
							iMaxDoll = iCntDoll;
							iMaxLen = iLen;
							iMaxX = j;
							iMaxY = i;
							iCntDoll = 0;
							iLen = 0;
							iSpaceCnt = 0;
							iDir = 2;
							iMaxDollColor = 1;
						}
					}
				}
				// 흰 검 ?
				else if (iState == WHITESTONE)
				{
					iCntDoll = 0;
					iLen = 0;
					iSpaceCnt = 0;
					// 흰 검 빈
					if (iOmokPan[j + 1][i] == PAN)
					{
						iCntDoll++;
						iLen++;
					}
					// 흰 검 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE)
					{
						iCntDoll++;
						iLen++;
					}
					// 흰 검 흰
					if (iOmokPan[j + 1][i] == WHITESTONE) {}
				}
				iState = BLACKSTONE;
			}
			// 현재 흰돌
			else if (iOmokPan[j][i] == WHITESTONE)
			{
				// 빈 흰 ?
				if (iState == PAN)
				{
					iCntDoll++;
					iLen++;
					// 빈 흰 빈
					if (iOmokPan[j + 1][i] == PAN)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = j;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 2;
								iMaxDollColor = 2;
							}
						}
					}
					// 빈 흰 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE)
					{
						if (iSpaceCnt == 1)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = j;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 2;
								iMaxDollColor = 2;
							}
						}
					}
					// 빈 흰 흰
					else if (iOmokPan[j + 1][i] == WHITESTONE) {}
				}
				// 검 흰 ?
				else if (iState == BLACKSTONE)
				{
					iCntDoll = 0;
					iLen = 0;
					iSpaceCnt = 0;
					// 검 흰 빈
					if (iOmokPan[j + 1][i] == PAN)
					{
						iCntDoll++;
						iLen++;
					}
					// 검 흰 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE) {}
					// 검 흰 흰
					else if (iOmokPan[j + 1][i] == WHITESTONE)
					{
						iCntDoll++;
						iLen++;
					}
				}
				// 흰 흰 ?
				else if (iState == WHITESTONE)
				{
					iCntDoll++;
					iLen++;
					// 흰 흰 빈
					if (iOmokPan[j + 1][i] == PAN)
					{
						if (iOmokPan[j + 2][i] != WHITESTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = j;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 2;
								iMaxDollColor = 2;
							}
						}
					}
					// 흰 흰 검
					else if (iOmokPan[j + 1][i] == BLACKSTONE)
					{
						if (iMaxLen < iLen)
						{
							iMaxDoll = iCntDoll;
							iMaxLen = iLen;
							iMaxX = j;
							iMaxY = i;
							iCntDoll = 0;
							iLen = 0;
							iSpaceCnt = 0;
							iDir = 2;
							iMaxDollColor = 2;
						}
					}
					// 흰 흰 흰
					else if (iOmokPan[j + 1][i] == WHITESTONE) {}
				}
				iState = WHITESTONE;
			}
		}
	}

	// 우상향대각선
	for (int j = 0; j < 37; ++j)
	{
		iState = 0;
		iCntDoll = 0;
		iLen = 0;
		iSpaceCnt = 0;
		iMaxDollColor = 0;
		if (j < 19)
		{
			for (int i = 0; i <= j; ++i)
			{
				// 현재 빈칸
				if (iOmokPan[i][j - i] == PAN)
				{
					// 빈 빈 ?
					if (iState == PAN)
					{
						// 빈 빈 빈
						// 빈 빈 검
						// 빈 빈 흰
					}
					// 검 빈 ?
					else if (iState == BLACKSTONE)
					{
						iSpaceCnt = 0;
						// 검 빈 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN) {}
						// 검 빈 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
						// 검 빈 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE) {}
					}
					// 흰 빈 ?
					else if (iState == WHITESTONE)
					{
						iSpaceCnt = 0;
						// 흰 빈 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN) {}
						//  흰 빈 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE) {}
						// 흰 빈 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
					}
					iState = PAN;
				}
				// 현재 검은돌
				else if (iOmokPan[i][j - i] == BLACKSTONE)
				{
					// 빈 검 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 검 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = j;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 3;
									iMaxDollColor = 1;
								}
							}
						}
						// 빈 검 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE) {}
						// 빈 검 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = j;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 3;
									iMaxDollColor = 1;
								}
							}
						}
					}
					// 검 검 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll++;
						iLen++;
						// 검 검 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN)
						{
							if (iOmokPan[i + 2][j - i - 2] != BLACKSTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = j;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 3;
									iMaxDollColor = 1;
								}
							}
						}
						// 검 검 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE) {}
						// 검 검 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 3;
								iMaxDollColor = 1;
							}
						}
					}
					// 흰 검 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 흰 검 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 흰
						if (iOmokPan[i + 1][j - i - 1] == WHITESTONE) {}
					}
					iState = BLACKSTONE;
				}
				// 현재 흰돌
				else if (iOmokPan[i][j - i] == WHITESTONE)
				{
					// 빈 흰 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 흰 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = j - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 3;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = j - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 3;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE) {}
					}
					// 검 흰 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 검 흰 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 검 흰 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE) {}
						// 검 흰 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE)
						{
							iCntDoll++;
							iLen++;
						}
					}
					// 흰 흰 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll++;
						iLen++;
						// 흰 흰 빈
						if (iOmokPan[i + 1][j - i - 1] == PAN)
						{
							if (iOmokPan[i + 2][j - i - 2] != WHITESTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = j - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 3;
									iMaxDollColor = 2;
								}
							}
						}
						// 흰 흰 검
						else if (iOmokPan[i + 1][j - i - 1] == BLACKSTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = j - i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 3;
								iMaxDollColor = 2;
							}
						}
						// 흰 흰 흰
						else if (iOmokPan[i + 1][j - i - 1] == WHITESTONE) {}
					}
					iState = WHITESTONE;
				}
			}
		}
		else if (j >= 19)
		{
			for (int i = 0; i < 37 - j; ++i)
			{
				// 현재 빈칸
				if (iOmokPan[i + j - 18][18 - i] == PAN)
				{
					// 빈 빈 ?
					if (iState == PAN)
					{
						// 빈 빈 빈
						// 빈 빈 검
						// 빈 빈 흰
					}
					// 검 빈 ?
					else if (iState == BLACKSTONE)
					{
						iSpaceCnt = 0;
						// 검 빈 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN) {}
						// 검 빈 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
						// 검 빈 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE) {}
					}
					// 흰 빈 ?
					else if (iState == WHITESTONE)
					{
						iSpaceCnt = 0;
						// 흰 빈 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN) {}
						//  흰 빈 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE) {}
						// 흰 빈 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
					}
					iState = PAN;
				}
				// 현재 검은돌
				else if (iOmokPan[i + j - 18][18 - i] == BLACKSTONE)
				{
					// 빈 검 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 검 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i + j - 18;
									iMaxY = 18 - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 4;
									iMaxDollColor = 1;
								}
							}
						}
						// 빈 검 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE) {}
						// 빈 검 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i + j - 18;
									iMaxY = 18 - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 4;
									iMaxDollColor = 1;
								}
							}
						}
					}
					// 검 검 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll++;
						iLen++;
						// 검 검 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN)
						{
							if (iOmokPan[i + j - 18 + 2][18 - i - 2] != BLACKSTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i + j - 18;
									iMaxY = 18 - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 4;
									iMaxDollColor = 1;
								}
							}
						}
						// 검 검 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE) {}
						// 검 검 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i + j - 18;
								iMaxY = 18 - i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 4;
								iMaxDollColor = 1;
							}
						}
					}
					// 흰 검 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 흰 검 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 흰
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE) {}
					}
					iState = BLACKSTONE;
				}
				// 현재 흰돌
				else if (iOmokPan[i + j - 18][18 - i] == WHITESTONE)
				{
					// 빈 흰 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 흰 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i + j - 18;
									iMaxY = 18 - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 4;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i + j - 18;
									iMaxY = 18 - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 4; 
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE) {}
					}
					// 검 흰 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 검 흰 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 검 흰 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE) {}
						// 검 흰 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE)
						{
							iCntDoll++;
							iLen++;
						}
					}
					// 흰 흰 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll++;
						iLen++;
						// 흰 흰 빈
						if (iOmokPan[i + j - 18 + 1][18 - i - 1] == PAN)
						{
							if (iOmokPan[i + j - 18 + 2][18 - i - 2] != WHITESTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i + j - 18;
									iMaxY = 18 - i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 4;
									iMaxDollColor = 2;
								}
							}
						}
						// 흰 흰 검
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == BLACKSTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i + j - 18;
								iMaxY = 18 - i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 4;
								iMaxDollColor = 2;
							}
						}
						// 흰 흰 흰
						else if (iOmokPan[i + j - 18 + 1][18 - i - 1] == WHITESTONE) {}
					}
					iState = WHITESTONE;
				}
			}
		}
	}

	// 좌상향대각선
	for (int j = 0; j < 37; ++j)
	{
		iState = 0;
		iCntDoll = 0;
		iLen = 0;
		iSpaceCnt = 0;
		iMaxDollColor = 0;
		if (j < 19)
		{
			for (int i = 0; i <= j; ++i)
			{
				// 현재 빈칸
				if (iOmokPan[i][18 - j + i] == PAN)
				{
					// 빈 빈 ?
					if (iState == PAN)
					{
						// 빈 빈 빈
						// 빈 빈 검
						// 빈 빈 흰
					}
					// 검 빈 ?
					else if (iState == BLACKSTONE)
					{
						iSpaceCnt = 0;
						// 검 빈 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN) {}
						// 검 빈 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
						// 검 빈 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE) {}
					}
					// 흰 빈 ?
					else if (iState == WHITESTONE)
					{
						iSpaceCnt = 0;
						// 흰 빈 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN) {}
						//  흰 빈 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE) {}
						// 흰 빈 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
					}
					iState = PAN;
				}
				// 현재 검은돌
				else if (iOmokPan[i][18 - j + i] == BLACKSTONE)
				{
					// 빈 검 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 검 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = 18 - j + i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 5;
									iMaxDollColor = 1;
								}
							}
						}
						// 빈 검 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE) {}
						// 빈 검 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = 18 - j + i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 5;
									iMaxDollColor = 1;
								}
							}
						}
					}
					// 검 검 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll++;
						iLen++;
						// 검 검 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN)
						{
							if (iOmokPan[i + 2][18 - j + i + 2] != BLACKSTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = 18 - j + i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 5;
									iMaxDollColor = 1;
								}
							}
						}
						// 검 검 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE) {}
						// 검 검 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = 18 - j + i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 5;
								iMaxDollColor = 1;
							}
						}
					}
					// 흰 검 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 흰 검 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 흰
						if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE) {}
					}
					iState = BLACKSTONE;
				}
				// 현재 흰돌
				else if (iOmokPan[i][18 - j + i] == WHITESTONE)
				{
					// 빈 흰 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 흰 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = 18 - j + i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 5;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = 18 - j + i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 5;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE) {}
					}
					// 검 흰 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 검 흰 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 검 흰 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE) {}
						// 검 흰 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE)
						{
							iCntDoll++;
							iLen++;
						}
					}
					// 흰 흰 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll++;
						iLen++;
						// 흰 흰 빈
						if (iOmokPan[i + 1][18 - j + i + 1] == PAN)
						{
							if (iOmokPan[i + 2][18 - j + i + 2] != WHITESTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = i;
									iMaxY = 18 - j + i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 5;
									iMaxDollColor = 2;
								}
							}
						}
						// 흰 흰 검
						else if (iOmokPan[i + 1][18 - j + i + 1] == BLACKSTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = i;
								iMaxY = 18 - j + i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 5;
								iMaxDollColor = 2;
							}
						}
						// 흰 흰 흰
						else if (iOmokPan[i + 1][18 - j + i + 1] == WHITESTONE) {}
					}
					iState = WHITESTONE;
				}
			}
		}
		else if (j >= 19)
		{
			for (int i = 0; i < 37 - j; ++i)
			{
				// 현재 빈칸
				if (iOmokPan[-18 + j + i][i] == PAN)
				{
					// 빈 빈 ?
					if (iState == PAN)
					{
						// 빈 빈 빈
						// 빈 빈 검
						// 빈 빈 흰
					}
					// 검 빈 ?
					else if (iState == BLACKSTONE)
					{
						iSpaceCnt = 0;
						// 검 빈 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN) {}
						// 검 빈 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
						// 검 빈 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE) {}
					}
					// 흰 빈 ?
					else if (iState == WHITESTONE)
					{
						iSpaceCnt = 0;
						// 흰 빈 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN) {}
						//  흰 빈 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE) {}
						// 흰 빈 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE)
						{
							iSpaceCnt++;
							iLen++;
						}
					}
					iState = PAN;
				}
				// 현재 검은돌
				else if (iOmokPan[-18 + j + i][i] == BLACKSTONE)
				{
					// 빈 검 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 검 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = -18 + j + i;
									iMaxY = i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 6;
									iMaxDollColor = 1;
								}
							}
						}
						// 빈 검 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE) {}
						// 빈 검 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = -18 + j + i;
									iMaxY = i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 6;
									iMaxDollColor = 1;
								}
							}
						}
					}
					// 검 검 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll++;
						iLen++;
						// 검 검 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN)
						{
							if (iOmokPan[-18 + j + i + 2][i + 2] != BLACKSTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = -18 + j + i;
									iMaxY = i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 6;
									iMaxDollColor = 1;
								}
							}
						}
						// 검 검 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE) {}
						// 검 검 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = -18 + j + i;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 6;
								iMaxDollColor = 1;
							}
						}
					}
					// 흰 검 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 흰 검 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE)
						{
							iCntDoll++;
							iLen++;
						}
						// 흰 검 흰
						if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE) {}
					}
					iState = BLACKSTONE;
				}
				// 현재 흰돌
				else if (iOmokPan[-18 + j + i][i] == WHITESTONE)
				{
					// 빈 흰 ?
					if (iState == PAN)
					{
						iCntDoll++;
						iLen++;
						// 빈 흰 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = -18 + j + i;
									iMaxY = i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 6;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE)
						{
							if (iSpaceCnt == 1)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = -18 + j + i;
									iMaxY = i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 6;
									iMaxDollColor = 2;
								}
							}
						}
						// 빈 흰 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE) {}
					}
					// 검 흰 ?
					else if (iState == BLACKSTONE)
					{
						iCntDoll = 0;
						iLen = 0;
						iSpaceCnt = 0;
						// 검 흰 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN)
						{
							iCntDoll++;
							iLen++;
						}
						// 검 흰 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE)
						{
						}
						// 검 흰 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE)
						{
							iCntDoll++;
							iLen++;
						}
					}
					// 흰 흰 ?
					else if (iState == WHITESTONE)
					{
						iCntDoll++;
						iLen++;
						// 흰 흰 빈
						if (iOmokPan[-18 + j + i + 1][i + 1] == PAN)
						{
							if (iOmokPan[-18 + j + i + 2][i + 2] != WHITESTONE)
							{
								if (iMaxLen < iLen)
								{
									iMaxDoll = iCntDoll;
									iMaxLen = iLen;
									iMaxX = -18 + j + i;
									iMaxY = i;
									iCntDoll = 0;
									iLen = 0;
									iSpaceCnt = 0;
									iDir = 6;
									iMaxDollColor = 2;
								}
							}
						}
						// 흰 흰 검
						else if (iOmokPan[-18 + j + i + 1][i + 1] == BLACKSTONE)
						{
							if (iMaxLen < iLen)
							{
								iMaxDoll = iCntDoll;
								iMaxLen = iLen;
								iMaxX = -18 + j + i;
								iMaxY = i;
								iCntDoll = 0;
								iLen = 0;
								iSpaceCnt = 0;
								iDir = 6;
								iMaxDollColor = 2;
							}
						}
						// 흰 흰 흰
						else if (iOmokPan[-18 + j + i + 1][i + 1] == WHITESTONE) {}
					}
					iState = WHITESTONE;
				}
			}
		}
	}

	////////////// 스캔 ////////////////
	// 가로
	if (iDir == 1)
	{
		printf("가장 연속으로 놓인 돌의 좌표: ");
		for (int j = iMaxY - iMaxLen + 1; j < iMaxY + 1; ++j)
		{
			if (iOmokPan[iMaxX][j] == BLACKSTONE)
			{
				iOmokPan[iMaxX][j] = BLACKSTAR;
			}
			else if (iOmokPan[iMaxX][j] == WHITESTONE)
			{
				iOmokPan[iMaxX][j] = WHITESTAR;
			}
			if (iOmokPan[iMaxX][j] != PAN)
				printf(" (%d %d) ", iMaxX, j);
		}
		printf("\n");
	}
	//세로
	else if (iDir == 2)
	{
		printf("가장 연속으로 놓인 돌의 좌표: ");
		for (int j = iMaxX - iMaxLen + 1; j < iMaxX + 1; ++j)
		{
			if (iOmokPan[j][iMaxY] == BLACKSTONE)
			{
				iOmokPan[j][iMaxY] = BLACKSTAR;
			}
			else if (iOmokPan[j][iMaxY] == WHITESTONE)
			{
				iOmokPan[j][iMaxY] = WHITESTAR;
			}
			if (iOmokPan[j][iMaxY] != PAN)
				printf(" (%d %d) ", j, iMaxY);
		}
		printf("\n");
	}
	// 우상향 대각선 위
	else if (iDir == 3)
	{
		printf("가장 연속으로 놓인 돌의 좌표: ");

		for (int i = iMaxX - iMaxLen +1; i < iMaxX+1; ++i)
		{
			for (int j = iMaxY; j < iMaxY + iMaxLen; ++j)
			{
				if (iOmokPan[i][j - i] == BLACKSTONE)
				{
					iOmokPan[i][j - i] = BLACKSTAR;
				}
				else if (iOmokPan[i][j - i] == WHITESTONE)
				{
					iOmokPan[i][j - i] = WHITESTAR;
				}
				if (iOmokPan[i][j - i] != PAN)
					printf(" (%d %d) ", i, j - i);
			}
		}
		printf("\n");
	}
	// 우상향 대각선 아래
	else if (iDir == 4)
	{
		printf("가장 연속으로 놓인 돌의 좌표: ");

		for (int i = iMaxX - iMaxLen+1; i < iMaxX+1; ++i)
		{
			for (int j = iMaxY; j < iMaxY + iMaxLen; ++j)
			{
				if (iOmokPan[i][j] == BLACKSTONE)
				{
					iOmokPan[i][j] = BLACKSTAR;
				}
				else if (iOmokPan[i][j] == WHITESTONE)
				{
					iOmokPan[i][j] = WHITESTAR;
				}
				if (iOmokPan[i][j] != PAN)
					printf(" (%d %d) ", i, j);
			}
		}
		printf("\n");
	}
	// 좌상향대각선 위 or 아래
	else if (iDir == 5 || iDir == 6)
	{
		printf("가장 연속으로 놓인 돌의 좌표: ");

		for (int i = iMaxX - iMaxLen + 1; i < iMaxX + 1; ++i)
		{
			for (int j = iMaxY - iMaxLen+1; j < iMaxY+1; ++j)
			{
				if (iOmokPan[i][j] == BLACKSTONE)
				{
					iOmokPan[i][j] = BLACKSTAR;
				}
				else if (iOmokPan[i][j] == WHITESTONE)
				{
					iOmokPan[i][j] = WHITESTAR;
				}
				if (iOmokPan[i][j] != PAN)
					printf(" (%d %d) ", i, j);
			}
		}
		printf("\n");
	}
}

void Defence()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			//----------가로-----------//
			{
				// ●●●
				if (((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i][j - 1] == BLACKSTONE || iOmokPan[i][j - 1] == BLACKSTAR)
					&& (iOmokPan[i][j + 1] == BLACKSTONE || iOmokPan[i][j + 1] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
						&& (iOmokPan[i][j - 1] == WHITESTONE || iOmokPan[i][j - 1] == WHITESTAR)
						&& (iOmokPan[i][j + 1] == WHITESTONE || iOmokPan[i][j + 1] == WHITESTAR)))
				{
					if (iOmokPan[i][j - 2] == PAN)
						iOmokPan[i][j - 2] = DEFENCE;
					if (iOmokPan[i][j + 2] == PAN)
						iOmokPan[i][j + 2] = DEFENCE;
				}
				// ●● ●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i][j + 1] == BLACKSTONE || iOmokPan[i][j + 1] == BLACKSTAR)
					&& (iOmokPan[i][j + 3] == BLACKSTONE || iOmokPan[i][j + 3] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
						&& (iOmokPan[i][j + 1] == WHITESTONE || iOmokPan[i][j + 1] == WHITESTAR)
						&& (iOmokPan[i][j + 3] == WHITESTONE || iOmokPan[i][j + 3] == WHITESTAR)))
					&& (iOmokPan[i][j + 2] == PAN || iOmokPan[i][j + 2] == DEFENCE))
				{
					if (iOmokPan[i][j + 2] == PAN)
						iOmokPan[i][j + 2] = DEFENCE;
				}
				// ● ●●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i][j + 2] == BLACKSTONE || iOmokPan[i][j + 2] == BLACKSTAR)
					&& (iOmokPan[i][j + 3] == BLACKSTONE || iOmokPan[i][j + 3] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
						&& (iOmokPan[i][j + 2] == WHITESTONE || iOmokPan[i][j + 2] == WHITESTAR)
						&& (iOmokPan[i][j + 3] == WHITESTONE || iOmokPan[i][j + 3] == WHITESTAR)))
					&& (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE))

				{
					if (iOmokPan[i][j + 1] == PAN)
						iOmokPan[i][j + 1] = DEFENCE;
				}
				// ●●● ●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i][j + 1] == BLACKSTONE || iOmokPan[i][j + 1] == BLACKSTAR)
					&& (iOmokPan[i][j + 2] == BLACKSTONE || iOmokPan[i][j + 2] == BLACKSTAR)
					&& (iOmokPan[i][j + 4] == BLACKSTONE || iOmokPan[i][j + 4] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
						&& (iOmokPan[i][j + 1] == WHITESTONE || iOmokPan[i][j + 1] == WHITESTAR)
						&& (iOmokPan[i][j + 2] == WHITESTONE || iOmokPan[i][j + 2] == WHITESTAR)
						&& (iOmokPan[i][j + 4] == WHITESTONE || iOmokPan[i][j + 4] == WHITESTAR)))
					&& (iOmokPan[i][j + 3] == PAN || iOmokPan[i][j + 3] == DEFENCE))
				{
					if (iOmokPan[i][j + 3] == PAN)
						iOmokPan[i][j + 3] = DEFENCE;
				}
				// ● ●●●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i][j + 2] == BLACKSTONE || iOmokPan[i][j + 2] == BLACKSTAR)
					&& (iOmokPan[i][j + 3] == BLACKSTONE || iOmokPan[i][j + 3] == BLACKSTAR)
					&& (iOmokPan[i][j + 4] == BLACKSTONE || iOmokPan[i][j + 4] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
						&& (iOmokPan[i][j + 2] == WHITESTONE || iOmokPan[i][j + 2] == WHITESTAR)
						&& (iOmokPan[i][j + 3] == WHITESTONE || iOmokPan[i][j + 3] == WHITESTAR)
						&& (iOmokPan[i][j + 4] == WHITESTONE || iOmokPan[i][j + 4] == WHITESTAR)))
					&& (iOmokPan[i][j + 1] == PAN || iOmokPan[i][j + 1] == DEFENCE))
				{
					if (iOmokPan[i][j + 1] == PAN)
						iOmokPan[i][j + 1] = DEFENCE;
				}
				// ●● ●●
				if ((((iOmokPan[i][j - 2] == BLACKSTONE || iOmokPan[i][j - 2] == BLACKSTAR)
					&& (iOmokPan[i][j - 1] == BLACKSTONE || iOmokPan[i][j - 1] == BLACKSTAR)
					&& (iOmokPan[i][j + 1] == BLACKSTONE || iOmokPan[i][j + 1] == BLACKSTAR)
					&& (iOmokPan[i][j + 2] == BLACKSTONE || iOmokPan[i][j + 2] == BLACKSTAR))
					|| ((iOmokPan[i][j - 2] == WHITESTONE || iOmokPan[i][j - 2] == WHITESTAR)
						&& (iOmokPan[i][j - 1] == WHITESTONE || iOmokPan[i][j - 1] == WHITESTAR)
						&& (iOmokPan[i][j + 1] == WHITESTONE || iOmokPan[i][j + 1] == WHITESTAR)
						&& (iOmokPan[i][j + 2] == WHITESTONE || iOmokPan[i][j + 2] == WHITESTAR)))
					&& (iOmokPan[i][j] == PAN || iOmokPan[i][j] == DEFENCE))
				{
					if (iOmokPan[i][j] == PAN)
						iOmokPan[i][j] = DEFENCE;
				}
			}

			//----------세로-----------//
			{
				// ●●●
				if (((iOmokPan[j][i] == BLACKSTONE || iOmokPan[j][i] == BLACKSTAR)
					&& (iOmokPan[j - 1][i] == BLACKSTONE || iOmokPan[i][j - 1] == BLACKSTAR)
					&& (iOmokPan[j + 1][i] == BLACKSTONE || iOmokPan[i][j + 1] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
						&& (iOmokPan[j - 1][i] == WHITESTONE || iOmokPan[i][j - 1] == WHITESTAR)
						&& (iOmokPan[j + 1][i] == WHITESTONE || iOmokPan[i][j + 1] == WHITESTAR)))
				{
					if (iOmokPan[j - 2][i] == PAN)
						iOmokPan[j - 2][i] = DEFENCE;
					if (iOmokPan[j + 2][i] == PAN)
						iOmokPan[j + 2][i] = DEFENCE;
				}
				// ●● ●
				if ((((iOmokPan[j][i] == BLACKSTONE || iOmokPan[j][i] == BLACKSTAR)
					&& (iOmokPan[j + 1][i] == BLACKSTONE || iOmokPan[j + 1][i] == BLACKSTAR)
					&& (iOmokPan[j + 3][i] == BLACKSTONE || iOmokPan[j + 3][i] == BLACKSTAR))
					|| ((iOmokPan[j][i] == WHITESTONE || iOmokPan[j][i] == WHITESTAR)
					&& (iOmokPan[j + 1][i] == WHITESTONE || iOmokPan[j + 1][i] == WHITESTAR)
					&& (iOmokPan[j + 3][i] == WHITESTONE || iOmokPan[j + 3][i] == WHITESTAR)))
					&& (iOmokPan[j + 2][i] == PAN || iOmokPan[j + 2][i] == DEFENCE))
				{
					if (iOmokPan[j + 2][i] == PAN)
						iOmokPan[j + 2][i] = DEFENCE;
				}
				// ● ●●
				if ((((iOmokPan[j][i] == BLACKSTONE || iOmokPan[j][i] == BLACKSTAR)
					&& (iOmokPan[j + 2][i] == BLACKSTONE || iOmokPan[j + 2][i] == BLACKSTAR)
					&& (iOmokPan[j + 3][i] == BLACKSTONE || iOmokPan[j + 3][i] == BLACKSTAR))
					|| ((iOmokPan[j][i] == WHITESTONE || iOmokPan[j][i] == WHITESTAR)
						&& (iOmokPan[j + 2][i] == WHITESTONE || iOmokPan[j + 2][i] == WHITESTAR)
						&& (iOmokPan[j + 3][i] == WHITESTONE || iOmokPan[j + 3][i] == WHITESTAR)))
					&& (iOmokPan[j + 1][i] == PAN || iOmokPan[j + 1][i] == DEFENCE))

				{
					if (iOmokPan[j + 1][i] == PAN)
						iOmokPan[j + 1][i] = DEFENCE;
				}
				// ●●● ●
				if ((((iOmokPan[j][i] == BLACKSTONE || iOmokPan[j][i] == BLACKSTAR)
					&& (iOmokPan[j + 1][i] == BLACKSTONE || iOmokPan[j + 1][i] == BLACKSTAR)
					&& (iOmokPan[j + 2][i] == BLACKSTONE || iOmokPan[j + 2][i] == BLACKSTAR)
					&& (iOmokPan[j + 4][i] == BLACKSTONE || iOmokPan[j + 4][i] == BLACKSTAR))
					|| ((iOmokPan[j][i] == WHITESTONE || iOmokPan[j][i] == WHITESTAR)
						&& (iOmokPan[j + 1][i] == WHITESTONE || iOmokPan[j + 1][i] == WHITESTAR)
						&& (iOmokPan[j + 2][i] == WHITESTONE || iOmokPan[j + 2][i] == WHITESTAR)
						&& (iOmokPan[j + 4][i] == WHITESTONE || iOmokPan[j + 4][i] == WHITESTAR)))
					&& (iOmokPan[j + 3][i] == PAN || iOmokPan[j + 3][i] == DEFENCE))
				{
					if (iOmokPan[j + 3][i] == PAN)
						iOmokPan[j + 3][i] = DEFENCE;
				}
				// ● ●●●
				if ((((iOmokPan[j][i] == BLACKSTONE || iOmokPan[j][i] == BLACKSTAR)
					&& (iOmokPan[j + 2][i] == BLACKSTONE || iOmokPan[j + 2][i] == BLACKSTAR)
					&& (iOmokPan[j + 3][i] == BLACKSTONE || iOmokPan[j + 3][i] == BLACKSTAR)
					&& (iOmokPan[j + 4][i] == BLACKSTONE || iOmokPan[j + 4][i] == BLACKSTAR))
					|| ((iOmokPan[j][i] == WHITESTONE || iOmokPan[j][i] == WHITESTAR)
					&& (iOmokPan[j + 2][i] == WHITESTONE || iOmokPan[j + 2][i] == WHITESTAR)
					&& (iOmokPan[j + 3][i] == WHITESTONE || iOmokPan[j + 3][i] == WHITESTAR)
					&& (iOmokPan[j + 4][i] == WHITESTONE || iOmokPan[j + 4][i] == WHITESTAR)))
					&& (iOmokPan[j + 1][i] == PAN || iOmokPan[j + 1][i] == DEFENCE))
				{
					if (iOmokPan[j + 1][i] == PAN)
						iOmokPan[j + 1][i] = DEFENCE;
				}
				// ●● ●●
				if ((((iOmokPan[j - 2][i] == BLACKSTONE || iOmokPan[j - 2][i] == BLACKSTAR)
					&& (iOmokPan[j - 1][i] == BLACKSTONE || iOmokPan[j - 1][i] == BLACKSTAR)
					&& (iOmokPan[j + 1][i] == BLACKSTONE || iOmokPan[j + 1][i] == BLACKSTAR)
					&& (iOmokPan[j + 2][i] == BLACKSTONE || iOmokPan[j + 2][i] == BLACKSTAR))
					|| ((iOmokPan[j - 2][i] == WHITESTONE || iOmokPan[j - 2][i] == WHITESTAR)
					&& (iOmokPan[j - 1][i] == WHITESTONE || iOmokPan[j - 1][i] == WHITESTAR)
					&& (iOmokPan[j + 1][i] == WHITESTONE || iOmokPan[j + 1][i] == WHITESTAR)
					&& (iOmokPan[j + 2][i] == WHITESTONE || iOmokPan[j + 2][i] == WHITESTAR)))
					&& (iOmokPan[j][i] == PAN || iOmokPan[j][i] == DEFENCE))
				{
					if (iOmokPan[j][i] == PAN)
						iOmokPan[j][i] = DEFENCE;
				}
			}

			//-------우상향대각--------//
			{
				// ●●●
				if (((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i - 1][j + 1] == BLACKSTONE || iOmokPan[i - 1][j + 1] == BLACKSTAR)
					&& (iOmokPan[i + 1][j - 1] == BLACKSTONE || iOmokPan[i + 1][j - 1] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i - 1][j + 1] == WHITESTONE || iOmokPan[i - 1][j + 1] == WHITESTAR)
					&& (iOmokPan[i + 1][j - 1] == WHITESTONE || iOmokPan[i + 1][j - 1] == WHITESTAR)))
				{
					if (iOmokPan[i - 2][j + 2] == PAN)
						iOmokPan[i - 2][j + 2] = DEFENCE;
					if (iOmokPan[i + 2][j - 2] == PAN)
						iOmokPan[i + 2][j - 2] = DEFENCE;
				}
				// ●● ●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 1][j - 1] == BLACKSTONE || iOmokPan[i + 1][j - 1] == BLACKSTAR)
					&& (iOmokPan[i + 3][j - 3] == BLACKSTONE || iOmokPan[i + 3][j - 3] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 1][j - 1] == WHITESTONE || iOmokPan[i + 1][j - 1] == WHITESTAR)
					&& (iOmokPan[i + 3][j - 3] == WHITESTONE || iOmokPan[i + 3][j - 3] == WHITESTAR)))
					&& (iOmokPan[i + 2][j - 2] == PAN || iOmokPan[i + 2][j - 2] == DEFENCE))
				{
					if (iOmokPan[i + 2][j - 2] == PAN)
						iOmokPan[i + 2][j - 2] = DEFENCE;
				}
				// ● ●●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 2][j - 2] == BLACKSTONE || iOmokPan[i + 2][j - 2] == BLACKSTAR)
					&& (iOmokPan[i + 3][j - 3] == BLACKSTONE || iOmokPan[i + 3][j - 3] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 2][j - 2] == WHITESTONE || iOmokPan[i + 2][j - 2] == WHITESTAR)
					&& (iOmokPan[i + 3][j - 3] == WHITESTONE || iOmokPan[i + 3][j - 3] == WHITESTAR)))
					&& (iOmokPan[i + 1][j - 1] == PAN || iOmokPan[i + 1][j - 1] == DEFENCE))
				{
					if (iOmokPan[i + 1][j - 1] == PAN)
						iOmokPan[i + 1][j - 1] = DEFENCE;
				}
				// ●●● ●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 1][j - 1] == BLACKSTONE || iOmokPan[i + 1][j - 1] == BLACKSTAR)
					&& (iOmokPan[i + 2][j - 2] == BLACKSTONE || iOmokPan[i + 2][j - 2] == BLACKSTAR)
					&& (iOmokPan[i + 4][j - 4] == BLACKSTONE || iOmokPan[i + 4][j - 4] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 1][j - 1] == WHITESTONE || iOmokPan[i + 1][j - 1] == WHITESTAR)
					&& (iOmokPan[i + 2][j - 2] == WHITESTONE || iOmokPan[i + 2][j - 2] == WHITESTAR)
					&& (iOmokPan[i + 4][j - 4] == WHITESTONE || iOmokPan[i + 4][j - 4] == WHITESTAR)))
					&& (iOmokPan[i + 3][j - 3] == PAN || iOmokPan[i + 3][j - 3] == DEFENCE))
				{
					if (iOmokPan[i + 3][j - 3] == PAN)
						iOmokPan[i + 3][j - 3] = DEFENCE;
				}
				// ● ●●●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 2][j - 2] == BLACKSTONE || iOmokPan[i + 2][j - 2] == BLACKSTAR)
					&& (iOmokPan[i + 3][j - 3] == BLACKSTONE || iOmokPan[i + 3][j - 3] == BLACKSTAR)
					&& (iOmokPan[i + 4][j - 4] == BLACKSTONE || iOmokPan[i + 4][j - 4] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 2][j - 2] == WHITESTONE || iOmokPan[i + 2][j - 2] == WHITESTAR)
					&& (iOmokPan[i + 3][j - 3] == WHITESTONE || iOmokPan[i + 3][j - 3] == WHITESTAR)
					&& (iOmokPan[i + 4][j - 4] == WHITESTONE || iOmokPan[i + 4][j - 4] == WHITESTAR)))
					&& (iOmokPan[i + 1][j - 1] == PAN || iOmokPan[i + 1][j - 1] == DEFENCE))
				{
					if (iOmokPan[i + 1][j - 1] == PAN)
						iOmokPan[i + 1][j - 1] = DEFENCE;
				}
				// ●● ●●
				if ((((iOmokPan[i - 2][j + 2] == BLACKSTONE || iOmokPan[i - 2][j + 2] == BLACKSTAR)
					&& (iOmokPan[i - 1][j + 1] == BLACKSTONE || iOmokPan[i - 1][j + 1] == BLACKSTAR)
					&& (iOmokPan[i + 1][j - 1] == BLACKSTONE || iOmokPan[i + 1][j - 1] == BLACKSTAR)
					&& (iOmokPan[i + 2][j - 2] == BLACKSTONE || iOmokPan[i + 2][j - 2] == BLACKSTAR))
					|| ((iOmokPan[i - 2][j + 2] == WHITESTONE || iOmokPan[i - 2][j + 2] == WHITESTAR)
					&& (iOmokPan[i - 1][j + 1] == WHITESTONE || iOmokPan[i - 1][j + 1] == WHITESTAR)
					&& (iOmokPan[i + 1][j - 1] == WHITESTONE || iOmokPan[i + 1][j - 1] == WHITESTAR)
					&& (iOmokPan[i + 2][j - 2] == WHITESTONE || iOmokPan[i + 2][j - 2] == WHITESTAR)))
					&& (iOmokPan[i][j] == PAN || iOmokPan[i][j] == DEFENCE))
				{
					if (iOmokPan[i][j] == PAN)
						iOmokPan[i][j] = DEFENCE;
				}
			}

			//-------좌상향대각--------//
			{
				// ●●●
				if (((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i - 1][j - 1] == BLACKSTONE || iOmokPan[i - 1][j - 1] == BLACKSTAR)
					&& (iOmokPan[i + 1][j + 1] == BLACKSTONE || iOmokPan[i + 1][j + 1] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i - 1][j - 1] == WHITESTONE || iOmokPan[i - 1][j - 1] == WHITESTAR)
					&& (iOmokPan[i + 1][j + 1] == WHITESTONE || iOmokPan[i + 1][j + 1] == WHITESTAR)))
				{
					if (iOmokPan[i - 2][j - 2] == PAN)
						iOmokPan[i - 2][j - 2] = DEFENCE;
					if (iOmokPan[i + 2][j + 2] == PAN)
						iOmokPan[i + 2][j + 2] = DEFENCE;
				}
				// ●● ●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 1][j + 1] == BLACKSTONE || iOmokPan[i + 1][j + 1] == BLACKSTAR)
					&& (iOmokPan[i + 3][j + 3] == BLACKSTONE || iOmokPan[i + 3][j + 3] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 1][j + 1] == WHITESTONE || iOmokPan[i + 1][j + 1] == WHITESTAR)
					&& (iOmokPan[i + 3][j + 3] == WHITESTONE || iOmokPan[i + 3][j + 3] == WHITESTAR)))
					&& (iOmokPan[i + 2][j + 2] == PAN || iOmokPan[i + 2][j + 2] == DEFENCE))
				{
					if (iOmokPan[i + 2][j + 2] == PAN)
						iOmokPan[i + 2][j + 2] = DEFENCE;
				}
				// ● ●●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 2][j + 2] == BLACKSTONE || iOmokPan[i + 2][j + 2] == BLACKSTAR)
					&& (iOmokPan[i + 3][j + 3] == BLACKSTONE || iOmokPan[i + 3][j + 3] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 2][j + 2] == WHITESTONE || iOmokPan[i + 2][j + 2] == WHITESTAR)
					&& (iOmokPan[i + 3][j + 3] == WHITESTONE || iOmokPan[i + 3][j + 3] == WHITESTAR)))
					&& (iOmokPan[i + 1][j + 1] == PAN || iOmokPan[i + 1][j + 1] == DEFENCE))
				{
					if (iOmokPan[i + 1][j + 1] == PAN)
						iOmokPan[i + 1][j + 1] = DEFENCE;
				}
				// ●●● ●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 1][j + 1] == BLACKSTONE || iOmokPan[i + 1][j + 1] == BLACKSTAR)
					&& (iOmokPan[i + 2][j + 2] == BLACKSTONE || iOmokPan[i + 2][j + 2] == BLACKSTAR)
					&& (iOmokPan[i + 4][j + 4] == BLACKSTONE || iOmokPan[i + 4][j + 4] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 1][j + 1] == WHITESTONE || iOmokPan[i + 1][j + 1] == WHITESTAR)
					&& (iOmokPan[i + 2][j + 2] == WHITESTONE || iOmokPan[i + 2][j + 2] == WHITESTAR)
					&& (iOmokPan[i + 4][j + 4] == WHITESTONE || iOmokPan[i + 4][j + 4] == WHITESTAR)))
					&& (iOmokPan[i + 3][j + 3] == PAN || iOmokPan[i + 3][j + 3] == DEFENCE))
				{
					if (iOmokPan[i + 3][j + 3] == PAN)
						iOmokPan[i + 3][j + 3] = DEFENCE;
				}
				// ● ●●●
				if ((((iOmokPan[i][j] == BLACKSTONE || iOmokPan[i][j] == BLACKSTAR)
					&& (iOmokPan[i + 2][j + 2] == BLACKSTONE || iOmokPan[i + 2][j + 2] == BLACKSTAR)
					&& (iOmokPan[i + 3][j + 3] == BLACKSTONE || iOmokPan[i + 3][j + 3] == BLACKSTAR)
					&& (iOmokPan[i + 4][j + 4] == BLACKSTONE || iOmokPan[i + 4][j + 4] == BLACKSTAR))
					|| ((iOmokPan[i][j] == WHITESTONE || iOmokPan[i][j] == WHITESTAR)
					&& (iOmokPan[i + 2][j + 2] == WHITESTONE || iOmokPan[i + 2][j + 2] == WHITESTAR)
					&& (iOmokPan[i + 3][j + 3] == WHITESTONE || iOmokPan[i + 3][j + 3] == WHITESTAR)
					&& (iOmokPan[i + 4][j + 4] == WHITESTONE || iOmokPan[i + 4][j + 4] == WHITESTAR)))
					&& (iOmokPan[i + 1][j + 1] == PAN || iOmokPan[i + 1][j + 1] == DEFENCE))
				{
					if (iOmokPan[i + 1][j + 1] == PAN)
						iOmokPan[i + 1][j + 1] = DEFENCE;
				}
				// ●● ●●
				if ((((iOmokPan[i - 2][j - 2] == BLACKSTONE || iOmokPan[i - 2][j - 2] == BLACKSTAR)
					&& (iOmokPan[i - 1][j - 1] == BLACKSTONE || iOmokPan[i - 1][j - 1] == BLACKSTAR)
					&& (iOmokPan[i + 1][j + 1] == BLACKSTONE || iOmokPan[i + 1][j + 1] == BLACKSTAR)
					&& (iOmokPan[i + 2][j + 2] == BLACKSTONE || iOmokPan[i + 2][j + 2] == BLACKSTAR))
					|| ((iOmokPan[i - 2][j - 2] == WHITESTONE || iOmokPan[i - 2][j - 2] == WHITESTAR)
					&& (iOmokPan[i - 1][j - 1] == WHITESTONE || iOmokPan[i - 1][j - 1] == WHITESTAR)
					&& (iOmokPan[i + 1][j + 1] == WHITESTONE || iOmokPan[i + 1][j + 1] == WHITESTAR)
					&& (iOmokPan[i + 2][j + 2] == WHITESTONE || iOmokPan[i + 2][j + 2] == WHITESTAR)))
					&& (iOmokPan[i][j] == PAN || iOmokPan[i][j] == DEFENCE))
				{
					if (iOmokPan[i][j] == PAN)
						iOmokPan[i][j] = DEFENCE;
				}
			}
		}
	}
}