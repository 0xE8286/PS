#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int N, M;
typedef pair<int, int> problem;
set<problem> sys;
unordered_map<int, int> grades;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int no, grade;
	for (int i = 0; i < N; i++) {
		cin >> no >> grade;
		sys.insert({ grade, no });
		grades.insert({no, grade});
	}
	cin >> M;
	string cmd;
	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "recommend") {
			int x; cin >> x;
			if (x == 1) {
				cout << (--sys.end())->second << '\n';
			}
			else {
				cout << sys.begin()->second << '\n';
			}
		}
		else if (cmd == "add") {
			int p; int l;
			cin >> p >> l;
			sys.insert({ l, p });
			grades.insert({ p, l });
		}
		else {
			int p; cin >> p;
			auto result = sys.lower_bound({ grades[p], p });
			grades.erase(p);
			sys.erase(result);
		}
	}

	return 0;
}