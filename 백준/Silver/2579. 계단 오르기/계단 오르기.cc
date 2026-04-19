#include <iostream>
#include <cmath>
using namespace std;

int N, sum;
int stair[301];
int score[301];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
		sum += stair[i];
	}
	score[1] = stair[1];
	score[2] = stair[2];
	score[3] = stair[3];

	for (int i = 4; i <= N; i++) {
		score[i] = min(score[i - 3], score[i - 2]) + stair[i];
	}

	cout << sum - min(score[N-1], score[N-2]) <<  endl;
	return 0;
}