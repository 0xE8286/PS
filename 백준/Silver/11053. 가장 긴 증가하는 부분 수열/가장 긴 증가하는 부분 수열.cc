#include <iostream>
using namespace std;

#define MAX_N 1001
int N;
int arr[MAX_N];
int cnt[MAX_N];
int ans = -1;

int max(int a, int b) {
	if (a >= b)return a;
	return b;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		cnt[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cnt[i] = max(cnt[j] + 1, cnt[i]);
			}
		}
		ans = max(cnt[i], ans);
	}
	cout << ans;

	return 0;
}