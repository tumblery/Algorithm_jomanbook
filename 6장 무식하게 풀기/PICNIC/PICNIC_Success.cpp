#include<stdio.h>
int N, M;
int friends[10][10];
int selected[10];
int ans;
void solve() {
	int first_sel = -1;
	for (int i = 0; i < N; i++) {
		if (selected[i] == 0) {
			first_sel = i;
			break;
		}
	}
	if (first_sel == -1) {
		ans++;
		return;
	}
	for (int pair = first_sel + 1; pair < N; pair++) {
		if ((selected[pair] == 0) && (friends[pair][first_sel] == 1)) {
			selected[pair] = selected[first_sel] = 1;
			solve();
			selected[pair] = selected[first_sel] = 0;
		}
	}
}
void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			friends[i][j] = 0;
		}
		selected[i] = 0;
	}
}
int main() {
	int C;
	scanf("%d", &C);
	for (int cases = 1; cases <= C; cases++) {
		scanf("%d %d", &N, &M);
		int part_1, part_2;
		init();
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &part_1, &part_2);
			friends[part_1][part_2] = 1;
			friends[part_2][part_1] = 1;
		}
		ans = 0;
		solve();
		printf("%d\n", ans);
	}
	return 0;
}