#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[1000];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<>());
	cout << arr[K-1];
	return 0;
}