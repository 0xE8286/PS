#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int by) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	hanoi(n - 1, from, by, to);
	cout << from << " " << to << "\n";
	hanoi(n - 1, by, to, from);
}

int count(int n) {
	int sum = 1;
	for (int i = 0; i < n; i++) {
		sum = sum * 2;
	}
	return sum - 1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << count(n) << "\n";
	hanoi(n, 1, 3, 2);

	return 0;
}