#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, cnt, lastDistance;
int map[21][21];
int visit[21][21];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int kg = 2;

struct pos {
	int y;
	int x;
	int distance;
	bool operator<(pos other) {
		if (y < other.y) return true;
		if (y == other.y && x < other.x) return true;
		return false;
	}
};

queue<pos> route;
vector<pos> candidate;

bool isWall (int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) return true;
	return false;
}

void clearVisitArray () {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}

void findFeed () {
	candidate.clear();
	int min_distance = 999;

	while (!route.empty()) {
		pos curr = route.front();
		route.pop();
		int x = curr.x;
		int y = curr.y;

		if (curr.distance <= min_distance && map[y][x] > 0 && map[y][x] < kg) { 
			candidate.push_back(curr);
			min_distance = curr.distance;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isWall(ny, nx) && visit[ny][nx] == 0 && map[ny][nx] <= kg) {
				route.push({ ny, nx, curr.distance+1 });
				visit[ny][nx] = 1;
			}
		}
	}
	clearVisitArray();
}

int main (void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				route.push({ i, j, 0 });
				map[i][j] = 0;
				visit[i][j] = 1;
			}
		}
	}
	findFeed();
	while (candidate.size() > 0) {
		sort(candidate.begin(), candidate.end());
		
		pos target = candidate[0];
		map[target.y][target.x] = 0;
		route.push(target);
		cnt++;

		if (cnt == kg) {
			kg++;
			cnt = 0;
		}

		lastDistance = candidate[0].distance;
		findFeed();
	}
	cout << lastDistance << endl;

	return 0;
}