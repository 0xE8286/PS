#include <iostream>
using namespace std;

int N, M;
int ans, cnt;
string str;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'I') {
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				cnt++;
				if (cnt == N) {
					ans++;
					cnt--;
				}
				i += 2;
			}
			cnt = 0;
		}
	}
	cout << ans;
	return 0;
}