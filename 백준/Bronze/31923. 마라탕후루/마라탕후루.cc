#include <iostream>
using namespace std;

int N, P, Q;
int A, B;
int strawberry[101];
int grape[101];
int cnt[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> strawberry[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> grape[i];
	}

	bool isAble = true;
	for (int i = 1; i <= N; i++) {
		int try_cnt = 10000;
		while (try_cnt) {
			if (strawberry[i] == grape[i]) {
				cnt[i] = 10000 - try_cnt;
				break;
			}
			strawberry[i] += P;
			grape[i] += Q;
			try_cnt--;
		}
		if (try_cnt == 0) {
			isAble = false;
			break;
		}
	}
	if (isAble) {
		cout << "YES\n";
		for (int i = 1; i <= N; i++) {
			cout << cnt[i] << ' ';
		}
	}
	else {
		cout << "NO\n";
	}

	return 0;
}