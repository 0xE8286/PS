#include <iostream>

#define M_EXP 30

using namespace std;

int N, K, M;
int dp[100001][M_EXP];
int first[100000];

int main() {

	cin >> N >> K >> M;

	for (int i = 0; i < N; i++) {
		cin >> first[i];
	}
	for (int i = 1; i <= K; i++) {
		cin >> dp[i][0];
	}

	for (int j = 1; j < M_EXP; j++) {
		for (int i = 1; i <= K; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	M--;
	for (int i = 0; i < N; i++) {
		int x = first[i];
		int t = M;
		
		for (int j = M_EXP - 1; j >= 0; j--) {
			int exp_time = 1 << j;
			if (t >= exp_time) {
				t -= exp_time;
				x = dp[x][j];
			}
		}
		cout << x << ' ';
	}

	return 0;
}