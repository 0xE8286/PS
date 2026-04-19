#include <iostream>
using namespace std;
#define MAX_N 100

long long pado[MAX_N + 1];
int T;
int N;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		pado[1] = 1;
		pado[2] = 1;
		pado[3] = 1;

		for (int i = 4; i <= N; i++) {
			pado[i] = (pado[i - 2] + pado[i - 3]);
		}
		cout << pado[N] << endl;
	}
	
	return 0;
}