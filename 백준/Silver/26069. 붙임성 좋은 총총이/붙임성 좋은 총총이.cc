#include <iostream>
#include <unordered_map>
using namespace std;

int N;
unordered_map<string, bool> dance;

int main() {

	cin >> N;
	dance["ChongChong"] = true;
	string a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (dance[a]) {
			dance[b] = true;
			continue;
		}
		if (dance[b]) {
			dance[a] = true;
			continue;
		}
	}
	int ans = 0;
	for (auto tokki : dance) {
		if (tokki.second) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}