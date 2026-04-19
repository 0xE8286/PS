#include <iostream>	
using namespace std;

int N;
int cnt;
int f[41];

int main() {

	cin >> N;

	f[1] = 1;
	f[2] = 1;
	
	for (int i = 3; i <= N; i++) {
		f[i] = f[i - 1] + f[i - 2];
		cnt++;
	}

	cout << f[N] << ' ' << cnt;

	return 0;
}