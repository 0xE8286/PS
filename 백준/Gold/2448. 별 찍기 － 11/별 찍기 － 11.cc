#include <iostream>

using namespace std;

bool a[3073][6145];

void star(int y, int x, int N) {

	if (N == 3) {
		a[y][x] = true;

		a[y + 1][x - 1] = true; 
		a[y + 1][x + 1] = true;

		a[y + 2][x - 2] = true; 
		a[y + 2][x - 1] = true; 
		a[y + 2][x] = true;
		a[y + 2][x + 1] = true;
		a[y + 2][x + 2] = true;

		return;
	}
	N /= 2;
	star(y, x, N);
	star(y + N, x - N, N);
	star(y + N, x + N, N);
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	star(1, N, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N * 2; j++) {
			if (a[i][j] == true)
				cout << '*';
			if (a[i][j] == false)
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}