#include <iostream>
#define MAX_N 2188
using namespace std;

int N;
int paper[MAX_N][MAX_N];
int maone, zero, one;

bool is_one_color(int y_start, int x_start, int y_end, int x_end) {
	int mark = paper[y_start][x_start];
	for (int i = y_start; i <= y_end; i++) {
		for (int j = x_start; j <= x_end; j++) {
			if (paper[i][j] != mark) {
				return false;
			}
		}
	}
	return true;
}


void cut(int y_start, int x_start, int y_end, int x_end, int size) {
	if (size > 1 && !is_one_color(y_start, x_start, y_end, x_end)) {
		int unit = size / 3;
		int x_first = (x_start + unit) - 1;
		int y_first = (y_start + unit) - 1;
		int x_second = x_first + unit;
		int y_second = y_first + unit;
		
		cut(y_start, x_start, y_first, x_first, unit);
		cut(y_start, x_first +1, y_first, x_second, unit);
		cut(y_start, x_second +1, y_first, x_end, unit);

		cut(y_first + 1, x_start, y_second, x_first, unit);
		cut(y_first + 1, x_first +1, y_second, x_second, unit);
		cut(y_first + 1, x_second +1, y_second, x_end, unit);

		cut(y_second + 1, x_start, y_end, x_first, unit);
		cut(y_second + 1, x_first + 1, y_end, x_second, unit);
		cut(y_second + 1, x_second + 1, y_end, x_end, unit);
	}
	else {
		if (paper[y_start][x_start] == -1)
			maone++;
		else if (paper[y_start][x_start] == 0)
			zero++;
		else if (paper[y_start][x_start] == 1)
			one++;
			
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	cut(0, 0, N - 1, N - 1, N);

	cout << maone << '\n' << zero << '\n' << one;

	return 0;
}