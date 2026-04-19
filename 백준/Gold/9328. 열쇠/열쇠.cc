#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define BLANK '.'
#define WALL '*'
#define DOC '$'

using namespace std;

int TC, N, M;

char map[100][101];
bool visit[100][100];

int dy[4] = { 0, 1, -1, 0 };
int dx[4] = { 1, 0 , 0, -1 };

string keys;
int find_cnt;

typedef pair<int, int> pos;

void clearAll () {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = '0';
			visit[i][j] = 0;
		}
	}
	find_cnt = 0;
	keys = "";
}

void clearVisit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return false;
	if (map[y][x] == WALL) return false;
	return true;
}

vector<pos>* getEntrance(vector<pos>* vec) {
	for (int y = 0; y < N; y++) {
		if (map[y][0] != WALL) {
			vec->push_back({ y, 0 });
		}
		if (map[y][M - 1] != WALL) {
			vec->push_back({ y, M - 1 });
		}
	}
	for (int x = 0; x < M; x++) {
		if (map[0][x] != WALL) {
			vec->push_back({ 0, x });
		}
		if (map[N - 1][x] != WALL) {
			vec->push_back({ N - 1, x });
		}
	}
	return vec;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N >> M;
		
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}
		cin >> keys;

		vector<pos> entrs;
		getEntrance(&entrs);
		
		queue<pos> q;
		for (pos start : entrs) {
			visit[start.first][start.second] = true;
			q.push(start);
		}

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			//문을 만나면
			if (map[y][x] >= 'A' && map[y][x] <= 'Z') {
				if (keys.find(tolower(map[y][x])) == string::npos) {
					continue;
				}
				else {
					map[y][x] = BLANK;
				}
			}
			//열쇠를 만나면
			else if (map[y][x] >= 'a' && map[y][x] <= 'z') {
				keys.push_back(map[y][x]);
				map[y][x] = BLANK;

				// 처음부터 다시 탐색
				clearVisit();
				while (!q.empty())q.pop();
				for (pos start : entrs) {
					visit[start.first][start.second] = true;
					q.push(start);
				}
				continue;
			}
			//문서를 만나면
			else if (map[y][x] == DOC) {
				find_cnt++;
				map[y][x] = BLANK;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!visit[ny][nx] && isValid(ny, nx)) {
					visit[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
		cout << find_cnt << endl;
		clearAll();
	}
	return 0;
}