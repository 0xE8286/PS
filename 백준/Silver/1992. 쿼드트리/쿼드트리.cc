#include <iostream>
using namespace std;

int N;
char scene[65][65];

bool is_one_color(int y_start, int x_start, int y_end, int x_end) {
	int mark = scene[y_start][x_start];
	for (int i = y_start; i <= y_end; i++) {
		for (int j = x_start; j <= x_end; j++) {
			if (scene[i][j] != mark) {
				return false;
			}
		}
	}
	return true;
}


void cut(int y_start, int x_start, int y_end, int x_end) {
	if (!is_one_color(y_start, x_start, y_end, x_end)) {
		int y_mid = (y_start + y_end) / 2;
		int x_mid = (x_start + x_end) / 2;
		
		cout << '(';
		cut(y_start, x_start, y_mid, x_mid);
		cut(y_start, x_mid + 1, y_mid, x_end);
		cut(y_mid + 1, x_start, y_end, x_mid);
		cut(y_mid + 1, x_mid + 1, y_end, x_end);
		cout << ')';
	}
	else {
		if (scene[y_start][x_start] == '1')
			cout << 1;
		else
			cout << 0;
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> scene[i];
	}
	cut(0, 0, N - 1, N - 1);

	return 0;
}