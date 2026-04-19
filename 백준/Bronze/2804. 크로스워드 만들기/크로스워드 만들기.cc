#include <iostream>
using namespace std;

string A, B;
int row, col, ok;
char map[30][31];

int main() {
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (A[i] == B[j]) {
				col = i;
				row = j;
				ok = 1;
				break;
			}
		}
		if (ok) break;
	}
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			map[i][j] = '.';
		}
	}
	for (int i = 0; i < A.size(); i++) {
		map[row][i] = A[i];
	}
	for (int i = 0; i < B.size(); i++) {
		map[i][col] = B[i];
	}
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}