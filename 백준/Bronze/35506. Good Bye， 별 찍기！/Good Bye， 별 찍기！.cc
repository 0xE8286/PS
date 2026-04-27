#include <iostream>
#include <algorithm>
#include <string>

#define STAR '*'
#define BLANK ' '

using namespace std;

int N;
int y, x;
string board[201];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	y = 2 * N; 
	x = 4 * N + 2;

	int s1, s2, s3;
	int adj;
	
	for (int i = 0; i < y; i++) {
		board[i] = string(x, BLANK);
		
		s1 = 2 * N - 1 - i;
		if (i < N) {
			adj = i;
		}
		else {
			adj = 2 * N - 1 - i;
		}
		s2 = 3 * N - adj;
		s3 = 3 * N + adj + 2;

		board[i][s1] = STAR;
		board[i][s2] = STAR;
		board[i][s3] = STAR;
	}

	for (int i = 0; i < y; i++) {
		cout << board[i] << '\n';
	}

	return 0;
}