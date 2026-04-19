#include <iostream>

using namespace std;

int TC, N, M;
int U, T;

int main() {

	cin >> TC;

	while (TC--) {
		cin >> N >> M;

		int org_dari = M * 2;

		U = org_dari - N;
		T = M - U;
		
		cout << U << ' ' << T << '\n';
	}

	return 0;
}