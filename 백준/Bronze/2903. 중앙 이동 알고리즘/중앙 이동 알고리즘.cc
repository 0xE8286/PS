#include <iostream>
using namespace std;

int N;
int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int init = 2;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		init = (init * 2) - 1;
	}
	cout << init*init;

	return 0;
}