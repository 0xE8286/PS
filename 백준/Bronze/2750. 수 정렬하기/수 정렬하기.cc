#include <iostream>

using namespace std;

void sort(int *a, int n) {
	int i, j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
 	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int a[1000] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}