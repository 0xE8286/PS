#include <iostream>
using namespace std;

int N;
int point[301];
long long dp[301][2];


long long max(long long a, long long b) {
	if (a > b)
		return a;
	else 
		return b;
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> point[i];
	}

	//시작점이 0번 인덱스

	dp[0][0] = point[1]; 
	dp[0][1] = point[2]; 

	dp[1][0] = point[1] + point[2];
	dp[1][1] = point[1] + point[3];
 
	for (int i = 2; i < N; i++) { //N-1 층의 0번 인덱스 까지만 채우묜 댐
		dp[i][0] = dp[i - 2][1] + point[i + 1];
		if (i == N - 1) break;
		dp[i][1] = max(dp[i - 1][0], dp[i-2][1]) + point[i + 2];
	}

	cout << max(dp[N - 1][0], dp[N - 2][1]);
	   	 
	return 0;
}