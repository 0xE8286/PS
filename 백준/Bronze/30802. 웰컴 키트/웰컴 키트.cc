#include <iostream>
using namespace std;

int N;
int shirt[6];
int T, P;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> shirt[i];
	}
	cin >> T >> P;
	
	int shirt_sum = 0;
	for (int i = 0; i < 6; i++) {
		if (shirt[i] % T == 0) {
			shirt_sum += shirt[i] / T;
		}
		else {
			shirt_sum += shirt[i] / T + 1;
		}
	}

	int pen_bulk = N / P;
	int pen_each = N % P;

	cout << shirt_sum << '\n';
	cout << pen_bulk << ' ' << pen_each;

	return 0;
}