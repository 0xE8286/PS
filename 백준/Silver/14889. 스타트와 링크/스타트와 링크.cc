#include<iostream>

using namespace std;

int N;
int s[21][21];
int pick[21];
int min_stat=2147483647;

int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

int getGap() {
	int start = 0;
	int link = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (pick[i] == 1 && pick[j] == 1)
				start += s[i][j];

			else if (pick[i] == 0 && pick[j] == 0)
				link += s[i][j];
		}
	}
	return abs(start - link);
}

void dfs(int index, int num) {
	if (index > N / 2) {
		int gap = getGap();
		if (gap < min_stat)
			min_stat = gap;
		return;
	}
	for (int i = num; i <= N; i++) {
		if (pick[i] != 1) {
			pick[i] = 1;
			dfs(index + 1, i + 1);
			pick[i] = 0;
		}
	}
}

int main(void){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){
			cin >> s[i][j];
		}
	}

	dfs(1, 1);
	cout << min_stat;

	return 0;
}