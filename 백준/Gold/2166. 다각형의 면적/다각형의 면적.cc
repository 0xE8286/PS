#include <iostream>
#include <algorithm>

using namespace std;

int N;
long double x[10000];
long double y[10000];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		cin >> y[i];
	}
	
	long double sum1 = x[N - 1] * y[0];
	long double sum2 = x[0] * y[N - 1];
	
	for (int i = 0; i < N - 1; i++) {
		sum1 += x[i] * y[i + 1];
		sum2 += x[i + 1] * y[i];
	}
	long double ans = abs(sum1 - sum2) / 2;

	cout.precision(1);
	cout << fixed;

	cout << ans;

	return 0;
}