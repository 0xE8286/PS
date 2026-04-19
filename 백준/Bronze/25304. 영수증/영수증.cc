#include<iostream>
using namespace std;

int main() {

	int sum, N;
	int stuff, cnt;
	int ans = 0;

	cin >> sum >> N;

	for (int i = 0; i < N; i++) {
		cin >> stuff >> cnt;
		ans += (stuff * cnt);
	}

	if (sum == ans) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}