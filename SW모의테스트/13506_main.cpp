// Title : 범인 색출, Score 를 최소화하라
// 20 초
// stack Memory : 1M  (전역 변수 사용 금지)

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#include <random>

extern void investigate();

const int MAX_NUM = 1000000;
static int SCORE, TOTAL_SCORE, TOTAL_TIME;
static char citizen[MAX_NUM];
static char room[MAX_NUM];
static char arrested[MAX_NUM];

void putIn(int n, int a)
{
   if (n < 0 || n >= MAX_NUM) return;
   if (a < 0 || a >= MAX_NUM) return;
   room[n] |= citizen[a];//room[n]에 범인 유무를 넣는 case
}

int closeDoor(int n)
{
   SCORE += 1;
   if (n < 0 || n >= MAX_NUM) return 0;
   return room[n];
}

void clearRoom() {
   for (int i = 0; i < MAX_NUM; i++) room[i] = 0;//모든 room의 경우를 초기화
}

void arrest(int a)
{
   SCORE += 10;
   if (a < 0 || a >= MAX_NUM) return;
   if(citizen[a] == 0) SCORE += 10000;
   arrested[a] = 1;
}


static unsigned long long seed = 113;
std::random_device rd;
std::mt19937 gen(seed);
std::uniform_int_distribution<int> dis(0, MAX_NUM - 1);

void init() {
   SCORE = 0;
   //초기화 과정
   for (int i = 0; i < MAX_NUM; i++) {
      citizen[i] = 0; room[i] = 0; arrested[i] = 0;
   }
   int j;
   //범인 번호 정하는 과정
   for (int i = 0; i < MAX_NUM / 1000; i++) {
      j = dis(gen);
      if (citizen[j] == 1) {
         i--;
         continue;
      }
      citizen[j] = 1;
   }
}

int main()
{
   int TC;
   TOTAL_SCORE = TOTAL_TIME = 0;
   //freopen("sample_input.txt", "r", stdin);
   scanf("%d", &TC);
   for (int t = 1; t <= TC; t++) {
      init();
      investigate();
      for (int i = 0; i < MAX_NUM; i++) if (citizen[i] == 1 && arrested[i] == 0) SCORE += 90000; //오답인 경우 확인
      if (SCORE < 86400) printf("#%d 100 %d\n", t, SCORE);
      else printf("#%d 0 0\n", t);
      TOTAL_SCORE += SCORE;
   }
   printf("TOTAL SCORE : %d\n", TOTAL_SCORE);

}
