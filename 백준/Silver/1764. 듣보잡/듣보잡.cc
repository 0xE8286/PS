#include <iostream>
#include <map>
#define BUCKET_SIZE 500009
using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, int> m;
	
	int N, M;
	string name;
	int ans = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> name;
		m[name] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		m[name]++;
	}

	for (auto iter = m.begin(); iter != m.end(); ++iter) {
		if (iter->second == 2) {
			ans++;
		}
	}
	cout << ans << "\n";

	for (auto iter = m.begin(); iter != m.end(); ++iter) {
		if (iter->second == 2) {
			cout << iter->first << "\n";
		}
	}
	return 0;
}