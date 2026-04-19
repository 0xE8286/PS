#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[8][8];
int backup[8][8];
int max_safe_area;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

typedef pair<int, int> pos;
vector<pos> emptys;
vector<pos> virus;

bool isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return false;
	return true;
}

void diffuse_virus() {
	queue<pos> q;
	for (auto i = virus.begin(); i != virus.end(); i++) {
		q.push(*i);
	}
	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = now.first + dy[i];
			int xx = now.second + dx[i];

			if (isValid(yy, xx) && map[yy][xx] == 0) {
				map[yy][xx] = 2;
				q.push(pos(yy, xx));
			}
		}
	}
}

void copy_map(int (*source)[8], int (*dest)[8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dest[i][j] = source[i][j];
		}
	}
}

int count_safe_area() {
	int safe_area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				safe_area++;
			}
		}
	}
	return safe_area;
}

void build_wall(int start, int d) {
	if (d == 3) {
		copy_map(map, backup);
		
		diffuse_virus();
		max_safe_area = max(count_safe_area(), max_safe_area);
		
		copy_map(backup, map);
		return;
	}
	for (int i = start; i < emptys.size(); i++) {
		int y = emptys[i].first;
		int x = emptys[i].second;

		if (map[y][x] == 0) {
			map[y][x] = 1;
			build_wall(i, d + 1);
			map[y][x] = 0;
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				emptys.push_back(pos(i, j));
			}
			else if (map[i][j] == 2) {
				virus.push_back(pos(i, j));
			}
		}
	}

	build_wall(0, 0);
	cout << max_safe_area;

	return 0;
}