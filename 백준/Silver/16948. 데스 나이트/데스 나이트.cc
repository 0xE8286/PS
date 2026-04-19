#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int di[] = { -2, -2, 0, 0, +2, +2 }, dj[] ={- 1, +1, -2, +2, -1, +1};
// (r, c)라면, (r - 2, c - 1), (r - 2, c + 1), (r, c - 2), (r, c + 2), (r + 2, c - 1), (r + 2, c + 1)

int N;

bool isValid(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N) return false;
	return true;
}

int r1, c1, r2, c2;
int check[500][500];

int main() {
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;

	check[r1][c1] = 1;
	queue<pos> q;
	q.push({ r1,c1 });
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second; q.pop();
		if (i == r2 && j == c2) {
			cout << check[i][j] -1;
			return 0;
		}
		for (int k = 0; k < 6; k++) {
			int ni = i + di[k], nj = j + dj[k];

			if (isValid(ni, nj) && !check[ni][nj]) {
				check[ni][nj] = check[i][j] + 1;
				q.push({ ni,nj });
			}
		}
	}
	cout << -1;
	return 0;
}