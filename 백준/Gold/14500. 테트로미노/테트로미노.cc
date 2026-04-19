#include <iostream>
#define MAX 500

using namespace std;

int N, M;
int board[MAX][MAX];
int check[MAX][MAX];

int dir_y[4] = { 0, -1 , 0, 1 };
int dir_x[4] = { -1, 0, 1, 0 };

int max_sum;

bool isWall(int y, int x) {
	if (y >= N || y < 0 || x >= M || x < 0) {
		return true;
	}
	return false;
}

void dfs(int y, int x, int sum, int depth) {
	if (depth == 4) {
		if (max_sum < sum) {
			max_sum = sum;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dir_y[i];
		int nx = x + dir_x[i];
		if (check[ny][nx] == 0 && !isWall(ny, nx)) {
			check[ny][nx] = 1;
			dfs(ny, nx, sum + board[ny][nx], depth + 1);
			check[ny][nx] = 0;
		}
	}
}

int getNum(int y, int x) {
	if (isWall(y, x)) {
		return -9999;
	}
	return board[y][x];
}

void findTblock(int y, int x) {
	int t1 = board[y][x] + getNum(y, x - 1) + getNum(y - 1, x) + getNum(y, x + 1); //ㅗ
	int t2 = board[y][x] + getNum(y - 1, x) + getNum(y + 1, x) + getNum(y, x + 1); //ㅏ
	int t3 = board[y][x] + getNum(y, x - 1) + getNum(y + 1, x) + getNum(y, x + 1); //ㅜ
	int t4 = board[y][x] + getNum(y, x - 1) + getNum(y + 1, x) + getNum(y - 1, x); //ㅓ

	if (t1 > max_sum) max_sum = t1;
	if (t2 > max_sum) max_sum = t2;
	if (t3 > max_sum) max_sum = t3;
	if (t4 > max_sum) max_sum = t4;
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = 1;
			dfs(i, j, board[i][j], 1);
			check[i][j] = 0;
		}
	}

	//+ DFS로는 T블럭 못찾으므로 추가 탐색 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			findTblock(i, j);
		}
	}


	cout << max_sum;
	return 0;
}