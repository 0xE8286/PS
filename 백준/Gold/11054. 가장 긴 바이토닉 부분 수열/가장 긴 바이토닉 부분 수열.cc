#include <iostream>
using namespace std;

#define MAX_N 1001
int N;
int arr[MAX_N];
int cnt[MAX_N];
int cnt_reverse[MAX_N];
int ans = -1;
int sum_max = -1;

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
	}

	for (int i = N-1; i >= 0; i--) {
		cnt_reverse[i] = 1;
		for (int j = N-1; j > i; j--) {
			if (arr[i] > arr[j]) {
				cnt_reverse[i] = max(cnt_reverse[j] + 1, cnt_reverse[i]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (cnt[i] + cnt_reverse[i] > sum_max) {
			sum_max = cnt[i] + cnt_reverse[i];
		}
	}

	cout << sum_max - 1;;

	return 0;
}