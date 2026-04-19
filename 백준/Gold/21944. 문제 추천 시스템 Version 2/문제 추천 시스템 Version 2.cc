#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

typedef pair<int, int> problem; //level, number

int N, M;

unordered_map<int, pair<int, int>> problem_info; //P L G 순

set<problem> accending;
set<problem, greater<>> descending;

set<problem> accending_by_level[101];
set<problem, greater<>> descending_by_level[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int P, L, G;

	for (int i = 0; i < N; i++) {
		cin >> P >> L >> G;

		problem_info[P] = make_pair(L, G);

		accending.insert({ L, P });
		descending.insert({ L, P });

		accending_by_level[G].insert({ L, P });
		descending_by_level[G].insert({ L, P });
	}

	cin >> M;

	string cmd;
	int x;

	for (int i = 0; i < M; i++) {

		cin >> cmd;

		if (cmd == "recommend") {
			cin >> G >> x;

			if (x == 1) {
				cout << descending_by_level[G].begin()->second << '\n';
			}
			else {
				cout << accending_by_level[G].begin()->second << '\n';
			}
		}
		else if (cmd == "recommend2") {
			cin >> x;

			if (x == 1) {
				cout << descending.begin()->second << '\n';
			}
			else {
				cout << accending.begin()->second << '\n';
			}
		}
		else if (cmd == "recommend3") {
			cin >> x >> L;
			if (x == 1) {
				auto lower = accending.lower_bound({ L, 0 });
				if (lower == accending.end()) {
					cout << -1 << '\n';
				}
				else {
					cout << lower->second << '\n';
				}
			}
			else {
				auto lower = descending.lower_bound({ L - 1, 100000 });
				if (lower == descending.end()) {
					cout << -1 << '\n';
				}
				else {
					cout << lower->second << '\n';
				}
			}
		}
		else if (cmd == "add") {
			cin >> P >> L >> G;

			problem_info[P] = make_pair(L, G);

			accending.insert({ L, P });
			descending.insert({ L, P });

			accending_by_level[G].insert({ L, P });
			descending_by_level[G].insert({ L, P });
		}
		else {
			cin >> P;
			L = problem_info[P].first;
			G = problem_info[P].second;

			accending.erase({ L, P });
			descending.erase({ L, P });

			accending_by_level[G].erase({ L, P });
			descending_by_level[G].erase({ L, P });
		}
	}
	return 0;
}