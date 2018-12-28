#include<stdio.h>
#define board_size 5
#define string_len 11
#define dir_num 8;
#define min(a,b) a<b?a:b
char board[board_size][board_size];
int init_score[board_size][board_size];
int  score[board_size][board_size];
char strings[string_len];
int str_len;
int ans;
int Max_num;
int dir[8][2] = {
	{ 0,-1 },
	{ -1,-1 },
	{ -1,0 },
	{ -1,1 },
	{ 0,1 },
	{ 1,1 },
	{ 1,0 },
	{ 1,-1 }
};
void score_init() {
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			init_score[i][j] = 0;
		}
	}
}
void get(int i,int j) {
	Max_num = -1;
	for (int k = 0; k < 8; k++) {
		int tmp_i = i + dir[k][0];
		int tmp_j = j + dir[k][1];
		if ((tmp_i >= 0) && (tmp_i < board_size) && (tmp_j >= 0) && (tmp_j < board_size)) {
			if (score[tmp_i][tmp_j] > Max_num) {
				Max_num = score[tmp_i][tmp_j];
			}
		}
	}
}
void copy_score() {
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			score[i][j] = init_score[i][j];
		}
	}
}
int solve() {
	for (int i = 0; i < str_len; i++) {
		//i = 문자열의 인덱스
		char word = strings[i];
		score_init();
		for (int j = 0; j < board_size; j++) {
			for (int k = 0; k < board_size; k++) {
				if (board[j][k] == word) {
					get(j,k);
					init_score[j][k] = min(i + 1, Max_num+1);
				}
			}
		}
		copy_score();
	}

	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			if (score[i][j] >= str_len) {
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int C, cases;
	char dummy;
	scanf("%d\n", &C);
	for (cases = 1; cases <= C; cases++) {
		//게임판 입력 받기
		for (int i = 0; i < board_size; i++) {
			for (int j = 0; j < board_size; j++) {
				scanf("%c", &board[i][j]);
			}
			scanf("%c", &dummy);
		}
		// 단어 입력 받기
		int N;
		char ch;
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			str_len = 0;
			scanf("%c", &ch);
			while (ch != '\x0a') {
				strings[str_len] = ch;
				str_len++;
				scanf("%c", &ch);
			}
			strings[str_len] = '\x00';
			if (solve() == 1) {
				printf("%s YES\n", strings);
			}
			else {
				printf("%s NO\n", strings);
			}
		}
	}
	return 0;
}