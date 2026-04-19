#include <iostream>

using namespace std;

char pan[50][51];
char w_pan[8][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};
char b_pan[8][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};

int cntChange(int y, int x) {
	int w_cnt=0;
	int b_cnt=0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pan[i + y][j + x] != w_pan[j][i]) {
				w_cnt++;
			}
			if (pan[i + y][j + x] != b_pan[j][i]) {
				b_cnt++;
			}
		}
	}
	if (w_cnt < b_cnt)
		return w_cnt;
	else
		return b_cnt;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	int min_cnt = 64;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> pan[i];
	}
	
	int lim_n = n - 8;
	int lim_m = m - 8;

	for (int i = 0; i <= lim_n; i++) {
		for (int j = 0; j <= lim_m; j++) {
			int cnt = cntChange(i, j);
			if (cnt < min_cnt)
				min_cnt = cnt;
		}
	}
	
	cout << min_cnt << endl;
	
	return 0;
}