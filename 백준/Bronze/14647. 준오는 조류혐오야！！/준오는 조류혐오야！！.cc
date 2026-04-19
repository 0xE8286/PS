#include <iostream>
using namespace std;

int N, M;
string bingo[500][500];

int main() {

	cin >> N >> M;
	
	int gu = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> bingo[i][j];
			for (char c : bingo[i][j]) {
				if (c == '9')
					gu++;
			}
		}
	}

	int max_row = 0; 
	int max_col = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			for (char c : bingo[i][j]) {
				if (c == '9')
					cnt++;
			}
		}
		max_row = max(cnt, max_row);
	}

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			for (char c : bingo[j][i]) {
				if (c == '9')
					cnt++;
			}
		}
		max_col = max(cnt, max_col);
	}

	cout << gu - max(max_col, max_row);

	return 0;
}