#include<stdio.h>
#define board_size 5
#define string_len 11
#define dir_num 8;
char board[board_size][board_size];
char strings[string_len];
int str_len;
int ans;
int dir[8][2] = {
	{0,-1},
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1}
};

void game(int i, int j,int index) {
	//만약 모든 글자를 다 순회한 상태라면 1을 return 한다.
	if (ans == 1)return;
	if (index == str_len) {
		ans = 1;
		return;
	}
	//만약 보드에서의 문자와 문자열의 문자가 일치하지 않으면 0을 return 한다.
	if (board[i][j] != strings[index]) {
		return;
	}
	for (int k = 0; k < 8; k++) {
		int tmp_i = i + dir[k][0];
		int tmp_j = j + dir[k][1];
		if ((tmp_i >= 0) && (tmp_i < board_size) && (tmp_j >= 0) && (tmp_j < board_size)) {
			game(tmp_i, tmp_j, index + 1);
		}
	}
}
int solve() {
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			//보드에서 시작 문자를 찾는다.
			if (board[i][j] == strings[0]) {
				//보드에서 원하는 문자열을 찾을경우 1을 return 한다.
				ans = 0;
				game(i, j, 0);
				if(ans == 1)return 1;
			}
		}
	}
	return 0;
}
int main() {
	int C, cases;
	char dummy;
	scanf("%d\n",&C);
	for (cases = 1; cases <= C; cases++) {
		//게임판 입력 받기
		for (int i = 0; i < board_size; i++) {
			for (int j = 0; j < board_size; j++) {
				scanf("%c", &board[i][j]);
			}
			scanf("%c",&dummy);
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
				printf("%s NO\n",strings);
			}
		}
	}
	return 0;
}
