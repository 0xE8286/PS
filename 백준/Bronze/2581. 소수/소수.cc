#include <iostream>
#include <set>
using namespace std;

int M, N;
int ans[2];
set<int> sosu;

bool isSosu(int n) {
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	cin >> M >> N;
	ans[0] = 0;
	ans[1] = 10001;
	
	for (int i = M; i <= N; i++) {
		if (isSosu(i)) {
			sosu.insert(i);
		}
	}

	for (int i : sosu) {
		ans[0] += i;
		ans[1] = min(ans[1], i);
	}
	
	if (ans[0] == 0) {
		cout << -1;
	}
	else {
		cout << ans[0] << '\n';
		cout << ans[1];
	}
	return 0;
}