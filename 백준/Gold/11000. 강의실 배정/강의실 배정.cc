#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int N;
multiset<pii> lecture;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		lecture.insert({ s, e });
	}

	int room = 0;
	while (lecture.size() > 0) {
		auto curr = lecture.begin();
		while (true) {
			int next_start_time = curr -> second;
			lecture.erase(curr);
			auto next = lecture.lower_bound({ next_start_time, 0 });
			if (next == lecture.end()) {
				room++;
				break;
			}
			curr = next;
		}
	}
	cout << room;

	return 0;
}