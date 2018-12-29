#include<stdio.h>
#include<iostream>
#define clock_cnt 16
#define INF 987654321
#define min(a,b) a<b?a:b
int ans;
int switchs[10][16] =
{
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},//0
	{ 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0 },//1
	{ 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1 },//2
	{ 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },//3
	{ 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0 },//4
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 },//5
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1 },//6
	{ 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1 },//7
	{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },//8
	{ 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0 }//9
};

int is_same(int* clock) {
	for (int i = 0; i < clock_cnt; i++) {
		if (clock[i] != 12)
			return 0;
	}
	return 1;
}
void clock_wise(int* clock,int type,int l) {
	for (int i = 0; i < clock_cnt; i++) {
		if (switchs[type][i] == 1) {
			clock[i] += 3*l;
			if (clock[i] > 12) clock[i] -= 12;
		}
	}
}
void Cnt_clock_wise(int* clock,int type,int l) {
	for (int i = 0; i < clock_cnt; i++) {
		if (switchs[type][i] == 1) {
			clock[i] -= 3*l;
			if (clock[i] <= 0) clock[i] += 12;
		}
	}
}
void solve(int* clock, int switch_num, int now) {

	if (ans <= now)return;	
	if (switch_num == 10) {
		if (is_same(clock) == 0)return;
		ans = min(ans, now);
		return;
	}
	for (int i = 0; i < 4; i++) {
		clock_wise(clock,switch_num,i);
		solve(clock,switch_num + 1,now+i);
		Cnt_clock_wise(clock,switch_num,i);
	}
}
int main() {
	int C;
	scanf("%d\n", &C);
	int clocks[16];
	for (int cases = 1; cases <= C; cases++) {
		for (int i = 0; i < clock_cnt; i++) {
			std::cin >> clocks[i];
		}
		ans = INF;
		solve(clocks,0,0);
		if (ans == INF) {
			ans = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

