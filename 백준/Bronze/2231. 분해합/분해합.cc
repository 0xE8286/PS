#include <iostream>

using namespace std;

int sumnum(int num) {
	int sum = num;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int ans = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (sumnum(i) == N) {
			ans = i;
			break;
		}
	}
	cout << ans ;

	return 0;
}