#include <iostream>

using namespace std;

bool isPrime[1001];

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 2; i <= 1000; i++) isPrime[i] = true;

	for (int num = 2; num <= 1000; num++) {
		if (isPrime[num]) {
			for (int i = num * 2; i <= 1000; i += num) {
				isPrime[i] = false;
			}
		}
	}
	
	int N;
	int input;
	int cnt = 0;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> input;

		if (isPrime[input]) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}