#include <iostream>
using namespace std;

int T;
int N;
int fibo[41][2];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N;

		fibo[0][0] = 1;
		fibo[0][1] = 0;

		fibo[1][0] = 0;
		fibo[1][1] = 1;

		for (int i = 2; i <= N; i++) {
			fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
			fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
		}

		cout << fibo[N][0] << " " << fibo[N][1] << endl;
	}
	   
	return 0;
}