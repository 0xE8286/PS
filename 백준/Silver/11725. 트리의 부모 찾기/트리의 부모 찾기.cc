#include <iostream>
#include <vector>

using namespace std;

int N;
int from, to;

vector<int> gp[100001];

int parent[100001];
int visit[100001];

void explor(int v) {
	for (int i = 0; i < gp[v].size(); i++) {
		int next = gp[v][i];
		if (visit[next] == 0) {
			visit[next] = 1;
			parent[next] = v;
			explor(next);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> from >> to;
		gp[from].push_back(to);
		gp[to].push_back(from);
	}

	visit[1] = 1;
	explor(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}