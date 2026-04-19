#include <iostream>
using namespace std;
#define MAX_N 1000000

long long fibo[MAX_N + 1];
int N;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	fibo[1] = 1;
	fibo[2] = 2;

	for (int i = 3; i <= N; i++) {
		fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 15746;
	}
	cout << fibo[N] % 15746 << endl;

	return 0;
}