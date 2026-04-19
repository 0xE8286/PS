#include <iostream>

#define MAX_N 1000

using namespace std;

int N;
int cost[MAX_N][3];
int dp[MAX_N][3];

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

void paint(int num) {
	if (num == N) {
		cout << min(min(dp[num-1][0], dp[num - 1][1]), dp[num - 1][2]);
	}
	else if (num == 0) {
		for (int i = 0; i < 3; i++) {
			dp[num][i] = cost[num][i];
		}
		paint(num + 1);
	}
	else {
		dp[num][0] = min(dp[num - 1][1], dp[num - 1][2]) + cost[num][0];
		dp[num][1] = min(dp[num - 1][0], dp[num - 1][2]) + cost[num][1];
		dp[num][2] = min(dp[num - 1][0], dp[num - 1][1]) + cost[num][2];
		paint(num + 1);
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];


	paint(0);
	return 0;
}