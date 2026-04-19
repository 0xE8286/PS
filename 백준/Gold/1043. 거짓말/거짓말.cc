#include <iostream>
#include <vector>

using namespace std;

int p[51];
int N, M, T, P;
vector<int> attendees[51];

void init() {
	for (int i = 1; i <= N; i++) {
		p[i] = -1;
	}
}
int find(int v) {
	if (p[v] == -1) {
		return v;
	}
	p[v] = find(p[v]);
	return p[v];
}
void Union(int a, int b) {
	int s1 = find(a);
	int s2 = find(b);
	if (s1 == s2) {
		return;
	}
	p[s2] = s1;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> T;

	if (T == 0) {
		cout << M;
		return 0;
	}

	init();
	int curr, next;
	cin >> curr;
	for (int i = 0; i < T - 1; i++) {
		cin >> next;
		Union(curr, next);
		curr = next;
	}

	int A, x1, x2;
	for (int i = 0; i < M; i++) {
		cin >> A;
		cin >> x1;
		attendees[i].push_back(x1);
		for (int j = 0; j < A - 1; j++) {
			cin >> x2;
			attendees[i].push_back(x2);
			Union(x1, x2);
			x1 = x2;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool lier_party = true;
		for (int attendee : attendees[i]) {
			if (find(curr) == find(attendee)) {
				lier_party = false;
				break;
			}
		}
		if (lier_party) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}