#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int N, M; 
string name, me, anc;

set<string> person;
set<string> root;

map<string, int> indegree;
map<string, vector<string>> edge;
map<string, set<string>> child;


void fill_child(const string& ancestor) {
	queue<string> q;
	q.push(ancestor);
	
	while (!q.empty()) {
		string curr = q.front(); q.pop();
		for (string next : edge[curr]) {
			if (--indegree[next] == 0) {
				child[curr].insert(next);
				q.push(next);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name;

		person.insert(name);
		indegree[name] = 0;
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> me >> anc;
		
		indegree[me]++;
		edge[anc].push_back(me);
	}

	for (auto iter = indegree.begin(); iter != indegree.end(); iter++) {
		if (iter->second == 0) root.insert(iter->first);
	}

	for (auto iter = root.begin(); iter != root.end(); iter++) {
		fill_child(*iter);
	}

	cout << root.size() << '\n';
	for (auto r : root) {
		cout << r << ' ';
	}
	cout << '\n';

	for (auto p : person) {
		cout << p << ' ';
		cout << child[p].size() << ' ';
		for (auto c : child[p]) {
			cout << c << ' ';
		}
		cout << '\n';
	}

	return 0;
}