#include<iostream>
#include<vector>
using namespace std;

int map[101][101];
int v[101][101];
int N;

void find(int from, int now) {
	for (int i = 0; i < N; i++) {
		if (map[now][i] == 1 && v[from][i] == 0) {
			v[from][i] = 1;
			find(from, i);
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		find(i, i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}