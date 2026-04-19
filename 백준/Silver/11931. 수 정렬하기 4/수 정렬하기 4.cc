#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000001];

bool oper(int a, int b) {
	if (a < b) return false;
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, &arr[N], oper);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}