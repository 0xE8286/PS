#include <iostream>
#include <queue>
#include <vector>

#define LARGE 987654321;
using namespace std;

int N;
int a, b;
int fw[51][51];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for  (int j = 1; j <= N; j++) {
			if (i == j) continue;
			fw[i][j] = LARGE;
		}
	}

	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		fw[a][b] = 1;
		fw[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
	
	for (int i = 1; i <= N; i++) {
		int max_value = -1;
		for (int j = 1; j <= N; j++) {
			max_value = max(max_value, fw[i][j]);
		}
		q.push(make_pair(max_value, i));
	}
	
	vector<pair<int, int>> candidates;
	candidates.push_back(q.top());
	q.pop();
	
	while (!q.empty()) {
		pair<int, int> person = q.top();
		q.pop();

		if (candidates[0].first != person.first) {
			break;
		}
		candidates.push_back(person);
	}

	cout << candidates[0].first << ' ';
	cout << candidates.size() << '\n';

	for (auto i = candidates.begin(); i != candidates.end(); i++) {
		cout << i->second << ' ';
	}

	return 0;
}