// Lotto.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

// 1. 1부터 50까지 5개의 임의의 수를 입력받을 것 (범위 초과하는 것, 예외 처리 할 것)
// 2. 실행시킬때마다 랜덤으로 설정되는 당첨번호와 비교. 배열로!! (순서 중요 No)
// 3. 5개 --> 1등 / 4개 --> 2등 / 3개 --> 3등 ...

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int n, i, j;
int lotto[50], lucky[50];
int count = 0;

void selectNum() {
	printf("1부터 50까지 임의의 5개의 수를 입력하세요.\n");

	for (n = 0; n < 5; n++) {
		scanf("%d", &lotto[n]);
		if (lotto[n] > 50 || lotto[n] < 1) {
			printf("잘못입력하였습니다.\n");
			exit(0);
		}
	}
	printf("선택한 번호 : ");
	for (n = 0; n < 5; n++) {
		printf("%d ", lotto[n]);
	}
}

void luckyNum() {
	printf("\n행운의 번호 : ");
	for (n = 0; n < 5; n++) {
		lucky[n] = rand() % 50 + 1;
		printf("%d ", lucky[n]);
	}
}

void compareNum() {
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (lotto[i] == lucky[j]) {
				count += 1;
			}
		}
	}
	if (count == 5) {
		printf("\n1등입니다!!!\n");
	}
	else if (count == 4) {
		printf("\n2등입니다!!\n");
	}
	else if (count == 3) {
		printf("\n3등입니다!\n");
	}
	else if (count == 2) {
		printf("\n4등입니다.\n");
	}
	else if (count == 1) {
		printf("\n5등입니다..\n");
	}
	else {
		printf("\n다음기회에...\n");
	}
}

int main()
{
	srand(time(NULL));
	selectNum();
	luckyNum();
	compareNum();
}

