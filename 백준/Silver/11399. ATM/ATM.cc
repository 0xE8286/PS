#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, time;
	int ans = 0;
	vector<int> v;

	cin >> N;
	for (int i = 0; i< N; i++) {
		cin >> time;
		v.push_back(time);
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			ans += v[j];
		}
		ans += v[i];
	}
	cout << ans;

	return 0;
}