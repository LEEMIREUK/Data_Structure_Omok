#pragma once
#include <stdio.h>
#include <memory>
#include <time.h>

#define SIZE_2016182027 19
#define PAN_2016182027 0
#define BLACKSTONE_2016182027 1
#define WHITESTONE_2016182027 2

void WhiteAttack_2016182027(int*, int*);
void WhiteDefence_2016182027(int, int);
void BlackAttack_2016182027(int*, int*);
void BlackDefence_2016182027(int, int);
void Initialize();

int OmokPan_2016182027[SIZE_2016182027][SIZE_2016182027];
int x_2016182027 = 0;
int y_2016182027 = 0;
bool first = true;

typedef struct Hint
{
	int x;
	int y;
	int score;
	Hint* next;
	Hint* prev;
}HINT;

HINT* WhiteHead_2016182027 = (HINT*)malloc(sizeof(HINT));
HINT* BlackHead_2016182027 = (HINT*)malloc(sizeof(HINT));


// 흑일때는 룰에 어긋날 가능성이 있으므로 공격형으로 가면서 룰을 피해가자
void BlackAttack_2016182027(int* x, int* y)
{
	Initialize();
	int score = 0;
	for (int i = 0; i < SIZE_2016182027; ++i)
	{
		for (int j = 0; j < SIZE_2016182027; ++j)
		{
			score = 0;
			if (OmokPan_2016182027[i][j] == PAN_2016182027)
			{
				{
					//----------가로-----------//
					// a●
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j + 1 <= SIZE_2016182027))
 						score += 1;
					// ●a
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j + 1 <= SIZE_2016182027) && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && (j + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 3 >= 0))
						score += 100;
					// a●●●●
 					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 4] == WHITESTONE_2016182027 && (j + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i][j - 4] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 4 >= 0))
						score += 1000;

					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//   a●●●○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
						score -= 116;
					//   ○●●●a			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 4 >= 0))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
						score += 100000;
					//○a○○○
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 100000;
					//○○a○○
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 100000;
					//○○○a○
					if (OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 100000;
					//○○○○a
					if (OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 4 >= 0))
						score += 100000;
					//----------세로-----------//
					// a●							
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 4][j] == WHITESTONE_2016182027 && (i + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i - 4][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 4 >= 0))
						score += 1000;

					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score -= 116;
					//   a●●●○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
						score -= 116;
					//   ○●●●a			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 4 >= 0))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
						score += 100000;
					//○a○○○
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 3 <= SIZE_2016182027))
						score += 100000;
					//○○a○○
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 100000;
					//○○○a○
					if (OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 100000;
					//○○○○a
					if (OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
						score += 100000;
					//-------우상향대각--------//
					// a●
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == WHITESTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i + 4][j - 4] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//   a●●●○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
						score -= 116;
					//   ○●●●a			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
						score += 100000;
					//○a○○○
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 100000;
					//○○a○○
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 100000;
					//○○○a○
					if (OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 100000;
					//○○○○a
					if (OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
						score += 100000;
					//-------좌상향대각--------//
					// a●
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == WHITESTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
 					if (OmokPan_2016182027[i - 4][j - 4] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//   a●●●○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
						score -= 116;
					//   ○●●●a		1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
						score += 5000;
					//○a○○○
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 100000;
					//○○a○○
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 100000;
					//○○○a○
					if (OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 100000;
					//○○○○a
					if (OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
						score += 100000;
				}

				//-------------- 금지 --------------//
				{
					// 33막기
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
					{
						if ((OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && (j - 2 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0)))
						{
							score -= 10000;
						}
					}

					// 44 막기
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
			
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027)))
						{
							score -= 10000;
						}
					}
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
					{
						if ((OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027) && (j - 1 >= 0))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && (j - 4 >= 0))
							|| (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (i - 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))

							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027) && (i + 3 <= SIZE_2016182027) && (j + 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027) && (i + 1 <= SIZE_2016182027) && (j + 1 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))

							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
							|| (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
							|| (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0)))
						{
							score -= 10000;
						}
					}
				}

				// 6목 방지
				// 가로
				// a○○○○○
				if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 5] == BLACKSTONE_2016182027 && (j + 5 <= SIZE_2016182027))
					score -= 1000000;
				// ○a○○○○
				if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 4 <= SIZE_2016182027))
					score -= 1000000;
				// ○○a○○○
				if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 3 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○a○○
				if (OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 2 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○a○
				if (OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 4 >= 0) && (j + 1 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○○a
				if (OmokPan_2016182027[i][j - 5] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 5 >= 0))
					score -= 1000000;
				// 세로
				// a○○○○○
				if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 5][j] == BLACKSTONE_2016182027 && (i + 5 <= SIZE_2016182027))
					score -= 1000000;
				// ○a○○○○
				if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 4 <= SIZE_2016182027))
					score -= 1000000;
				// ○○a○○○
				if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 3 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○a○○
				if (OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 2 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○a○
				if (OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (i + 1 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○○a
				if (OmokPan_2016182027[i - 5][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 5 >= 0))
					score -= 1000000;
				// 우상향
				// a○○○○○
				if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 5][j + 5] == BLACKSTONE_2016182027 && (i - 5 >= 0) && (j + 5 <= SIZE_2016182027))
					score -= 1000000;
				// ○a○○○○
				if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
					score -= 1000000;
				// ○○a○○○
				if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○a○○
				if (OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○a○
				if (OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○○a
				if (OmokPan_2016182027[i + 5][j - 5] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 5 <= SIZE_2016182027) && (j - 5 >= 0))
					score -= 1000000;
				// 좌상향
				// a○○○○○
				if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 5][j + 5] == BLACKSTONE_2016182027 && (i + 5 <= SIZE_2016182027) && (j + 5 <= SIZE_2016182027))
					score -= 1000000;
				// ○a○○○○
				if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
					score -= 1000000;
				// ○○a○○○
				if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○a○○
				if (OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○a○
				if (OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
					score -= 1000000;
				// ○○○○○a
				if (OmokPan_2016182027[i - 5][j - 5] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 5 >= 0) && (j - 5 >= 0))
					score -= 1000000;
			}

			// 점수 판별 및 힌트
			{
				if (BlackHead_2016182027->next == NULL)
				{
					HINT* p = (HINT*)malloc(sizeof(HINT));
					p->x = i;
					p->y = j;
					p->score = score;
					BlackHead_2016182027->next = p;
					p->next = BlackHead_2016182027->next;
					p->prev = BlackHead_2016182027->next;
				}
				else
				{
					// hint1
					if (BlackHead_2016182027->next->score < score)
					{
						HINT* p = (HINT*)malloc(sizeof(HINT));
						p->x = i;
						p->y = j;
						p->score = score;
						BlackHead_2016182027->next->prev = p;
						p->next = BlackHead_2016182027->next;
						BlackHead_2016182027->next = p;
					}
				}
			}
		}
	}

	if (first)
	{
		*x = 9;
		*y = 9;
		OmokPan_2016182027[*x][*y] = BLACKSTONE_2016182027;
		first = false;
	}
	else
	{
		*x = BlackHead_2016182027->next->x;
		*y = BlackHead_2016182027->next->y;

		OmokPan_2016182027[BlackHead_2016182027->next->x][BlackHead_2016182027->next->y] = BLACKSTONE_2016182027;
	}
}
void BlackDefence_2016182027(int x, int y)
{
	x_2016182027 = x;
	y_2016182027 = y;
	OmokPan_2016182027[x_2016182027][y_2016182027] = WHITESTONE_2016182027;
}

// 백은 룰과 상관없으므로 무조건 막는 전략으로 가자
void WhiteAttack_2016182027(int* x, int* y)
{
	Initialize();
	int score = 0;
	for (int i = 0; i < SIZE_2016182027; ++i)
	{
		for (int j = 0; j < SIZE_2016182027; ++j)
		{
			score = 0;
			if (OmokPan_2016182027[i][j] == PAN_2016182027)
			{
				{
					//----------가로-----------//
					// a●
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j + 1 <= SIZE_2016182027) && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 4] == BLACKSTONE_2016182027 && (j + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 3] == BLACKSTONE_2016182027 && (j - 1 >= 0) && (j + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == BLACKSTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && (j + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 4] == WHITESTONE_2016182027 && (j + 4 <= SIZE_2016182027))
						score += 5000;
					//○a○○○
					if (OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 3] == WHITESTONE_2016182027 && (j - 1 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 5000;
					//○○a○○
					if (OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 2] == WHITESTONE_2016182027 && (j - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 5000;
					//○○○a○
					if (OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j + 1] == WHITESTONE_2016182027 && (j - 3 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 5000;
					//○○○○a
					if (OmokPan_2016182027[i][j - 4] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i][j - 1] == WHITESTONE_2016182027 && (j - 4 >= 0))
						score += 5000;
					//----------세로-----------//
					// a●
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i - 4][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && (i - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (i + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 3][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i - 2][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 4][j] == WHITESTONE_2016182027 && (i + 4 <= SIZE_2016182027))
						score += 5000;
					//○a○○○
					if (OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j] == WHITESTONE_2016182027 && (i - 1 >= 0) && (i + 3 <= SIZE_2016182027))
						score += 5000;
					//○○a○○
					if (OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j] == WHITESTONE_2016182027 && (i - 2 >= 0) && (i + 2 <= SIZE_2016182027))
						score += 5000;
					//○○○a○
					if (OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j] == WHITESTONE_2016182027 && (i - 3 >= 0) && (i + 1 <= SIZE_2016182027))
						score += 5000;
					//○○○○a
					if (OmokPan_2016182027[i - 4][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j] == WHITESTONE_2016182027 && (i - 4 >= 0))
						score += 5000;
					//-------우상향대각--------//
					// a●
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i + 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i + 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i + 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 4][j + 4] == WHITESTONE_2016182027 && (i - 4 >= 0) && (j + 4 <= SIZE_2016182027))
						score += 5000;
					//○a○○○
					if (OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j + 3] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j - 1 >= 0) && (i - 3 >= 0) && (j + 3 <= SIZE_2016182027))
						score += 5000;
					//○○a○○
					if (OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j + 2] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j - 2 >= 0) && (i - 2 >= 0) && (j + 2 <= SIZE_2016182027))
						score += 5000;
					//○○○a○
					if (OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j - 3 >= 0) && (i - 1 >= 0) && (j + 1 <= SIZE_2016182027))
						score += 5000;
					//○○○○a
					if (OmokPan_2016182027[i + 4][j - 4] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j - 1] == WHITESTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j - 4 >= 0))
						score += 5000;
					//-------좌상향대각--------//
					// a●
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 1;
					// ●a
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0))
						score += 1;
					// a●●
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 10;
					// ●a●
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 10;
					// ●●a
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
						score += 10;
					// a●●●
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 100;
					// ●a●●
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 100;
					// ●●a●
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 100;
					// ●●●a
					if (OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
						score += 100;
					// a●●●●
					if (OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == BLACKSTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
						score += 1000;
					// ●a●●●
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 1000;
					// ●●a●●
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 1000;
					// ●●●a●
					if (OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 1000;
					// ●●●●a
					if (OmokPan_2016182027[i - 4][j - 4] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
						score += 1000;
					//-------------- 추가 --------------//
					// 평가에서 -가 되는 경우
					// ○a●				1 + 5	
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					// ○a●●				1 + 5 + 10
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score -= 16;
					// ○a●●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == BLACKSTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score -= 116;
					// ○●a●●			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == BLACKSTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//       ●a○			1 + 5
					if (OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 6;
					//     ●●a○			1 + 5 + 10
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 16;
					//   ●●●a○			1 + 5 + 10 + 100
					if (OmokPan_2016182027[i - 3][j - 3] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score -= 116;
					//   ●●a●○			1 + 5 + 10 + 100	
					if (OmokPan_2016182027[i - 2][j - 2] == BLACKSTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == BLACKSTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score -= 116;
					//-------------- 공격 --------------//
					//a○
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 5;
					//○a
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0))
						score += 5;
					//a○○
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 50;
					//○a○
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 50;
					//○○a
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0))
						score += 50;
					//a○○○
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 500;
					//○a○○
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 500;
					//○○a○
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 500;
					//○○○a
					if (OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0))
						score += 500;
					//a○○○○
					if (OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 4][j + 4] == WHITESTONE_2016182027 && (i + 4 <= SIZE_2016182027) && (j + 4 <= SIZE_2016182027))
						score += 5000;
					//○a○○○
					if (OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 3][j + 3] == WHITESTONE_2016182027 && (i - 1 >= 0) && (j - 1 >= 0) && (i + 3 <= SIZE_2016182027) && (j + 3 <= SIZE_2016182027))
						score += 5000;
					//○○a○○
					if (OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 2][j + 2] == WHITESTONE_2016182027 && (i - 2 >= 0) && (j - 2 >= 0) && (i + 2 <= SIZE_2016182027) && (j + 2 <= SIZE_2016182027))
						score += 5000;
					//○○○a○
					if (OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && OmokPan_2016182027[i + 1][j + 1] == WHITESTONE_2016182027 && (i - 3 >= 0) && (j - 3 >= 0) && (i + 1 <= SIZE_2016182027) && (j + 1 <= SIZE_2016182027))
						score += 5000;
					//○○○○a
					if (OmokPan_2016182027[i - 4][j - 4] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 3][j - 3] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 2][j - 2] == WHITESTONE_2016182027 && OmokPan_2016182027[i - 1][j - 1] == WHITESTONE_2016182027 && (i - 4 >= 0) && (j - 4 >= 0))
						score += 5000;
				}
					
				//6목?
				//a○○○○○


				// 점수 판별 및 힌트
				{
					if (WhiteHead_2016182027->next == NULL)
					{
						HINT* p = (HINT*)malloc(sizeof(HINT));
						p->x = i;
						p->y = j;
						p->score = score;
						WhiteHead_2016182027->next = p;
						p->next = WhiteHead_2016182027->next;
						p->prev = WhiteHead_2016182027->next;
					}
					else
					{
						// hint1
						if (WhiteHead_2016182027->next->score < score)
						{
							HINT* p = (HINT*)malloc(sizeof(HINT));
							p->x = i;
							p->y = j;
							p->score = score;
							WhiteHead_2016182027->next->prev = p;
							p->next = WhiteHead_2016182027->next;
							WhiteHead_2016182027->next = p;
						}
					}
				}
			}
		}
	}

	*x = WhiteHead_2016182027->next->x;
	*y = WhiteHead_2016182027->next->y;

	OmokPan_2016182027[WhiteHead_2016182027->next->x][WhiteHead_2016182027->next->y] = WHITESTONE_2016182027;
}

void WhiteDefence_2016182027(int x, int y)
{
	x_2016182027 = x;
	y_2016182027 = y;
	OmokPan_2016182027[x_2016182027][y_2016182027] = BLACKSTONE_2016182027;
}

void Initialize()
{
	BlackHead_2016182027->next = NULL;
	WhiteHead_2016182027->next = NULL;
}