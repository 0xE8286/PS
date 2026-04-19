#include <iostream>
#include <cmath>
using namespace std;

int N;
int stair[301];
int score[301][3];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	score[1][1] = stair[1];
	score[1][2] = stair[1];

	for (int i = 2; i <= N; i++) {
		score[i][1] = max(score[i - 2][1], score[i - 2][2]) + stair[i];
		score[i][2] = score[i - 1][1] + stair[i];
	}
	cout << max(score[N][1], score[N][2]);
	return 0;
}