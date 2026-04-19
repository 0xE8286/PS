#include <iostream>
#include <set>

using namespace std;

int N, K;
set<int, greater<int>> s;

int main() {

	cin >> N >> K;

	int coin;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> coin;
		s.insert(coin);
	}

	auto iter = s.begin();
	while (K != 0) {
		int c = *iter;
		if (K / c > 0) {
			cnt += K / c;
			K = K % c;
		}
		iter++;
	}
	
	cout << cnt;
	return 0;
}