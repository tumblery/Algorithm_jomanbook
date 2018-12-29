#include<stdio.h>
#define board_size 20
#define empty 0
#define wall 2
#define covered 1
#define error 3
#define set 1
#define del 0
int ans;
int H, W;
int board[board_size][board_size];
int covers[4][3][2] =
{
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,-1},{1,0}}
};
void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~\n");
}
int setting(int i_flag, int j_flag, int type,int flag) {
	int tmp_i, tmp_j;
	int cover_flag = 0;
	for (int i = 0; i < 3; i++) {
		tmp_i = i_flag + covers[type][i][0];
		tmp_j = j_flag + covers[type][i][1];
		if (tmp_i >= 0 && tmp_i < H && tmp_j >= 0 && tmp_j < W) {
			if (flag == set) {
				if (board[tmp_i][tmp_j] == empty) cover_flag++;
				else {
					return 0;
				}
			}
			else if (flag == del) {
				if (board[tmp_i][tmp_j] == covered) cover_flag++;
				else {
					return 0;
				}
			}
		}
		else {
			return 0;
		}
	}
	if (cover_flag == 3) {
		for (int i = 0; i < 3; i++) {
			tmp_i = i_flag + covers[type][i][0];
			tmp_j = j_flag + covers[type][i][1];
			if (flag == set) {
				board[tmp_i][tmp_j] = covered;
			}
			else if (flag == del) {
				board[tmp_i][tmp_j] = empty;
			}
		}
	}
	return 1;
}
void cover_block() {
	int i_flag,j_flag;
	i_flag = j_flag = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == empty) {
				i_flag = i;
				j_flag = j;
				break;
			}
		}
		if (i_flag != -1) break;
	}
	if (i_flag == -1) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (setting(i_flag, j_flag, i, set) == 1) {
			cover_block();
			setting(i_flag, j_flag, i, del);
		}
	}
}

int main() {
	int C;
	scanf("%d\n", &C);
	for (int cases = 1; cases <= C; cases++) {
		scanf("%d %d\n", &H, &W);
		int empty_block = 0;
		char tmp;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%c", &tmp);
				if (tmp == '#') board[i][j] = wall;
				else if (tmp == '.') {
					board[i][j] = empty;
					empty_block++;
				}
				else board[i][j] = error;
			}
			scanf("%c", &tmp);
			scanf("%c", &tmp);
		}
		//print();
		ans = 0;
		if(empty_block == 0)ans = 1;
		else if(empty_block%3 == 0)cover_block();
		
		printf("%d\n", ans);
	}
	return 0;
}