#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pos;

int N, M;
int map[50][50];
vector<pos> home;
vector<pos> chicken;

bool visit[14];
vector<int> list;

int ans = 987654321;

int distance(int y1, int x1, int y2, int x2) {
	return abs(y1 - y2) + abs(x1 - x2);
}

void dfs(int idx, int depth) {
	if (depth == M) {
		vector<int> distances(home.size());
		fill(distances.begin(), distances.end(), 999);
		int sum = 0;

		for (int c = 0; c < M; c++) {
			for (int h = 0; h < home.size(); h++) {
				int c_index = list[c];
				int dist = distance(chicken[c_index].first, chicken[c_index].second, home[h].first, home[h].second);

				distances[h] = min(distances[h], dist);
			}
		}
		for (int i = 0; i < distances.size(); i++) {
			sum += distances[i];
		}
		if (sum < ans) {
			ans = sum;
		}
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			list.push_back(i);

			dfs(i + 1, depth + 1);

			visit[i] = 0;
			list.pop_back();
		}
	}
}
int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				home.push_back(pos(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(pos(i, j));
			}

		}
	}
	dfs(0, 0);

	cout << ans;

	return 0;
}