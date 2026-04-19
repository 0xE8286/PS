#include <iostream>

using namespace std;

int N, K;
int num[500000];
int temp[500000];
int cnt;

void print() {
	for (int i = 0; i < N; i++) {
		cout << num[i] << ' ';
	}
	cout << '\n';
}

void merge(int start, int mid, int end) {
	int left_i = start;
	int temp_i = start;
	int right_i = mid + 1;

	while (left_i <= mid && right_i <= end) {
		if (num[left_i] < num[right_i]) {
			temp[temp_i++] = num[left_i++];
		}
		else {
			temp[temp_i++] = num[right_i++];
		}
	}
	while (left_i <= mid) {
		temp[temp_i++] = num[left_i++];
	}
	while (right_i <= end) {
		temp[temp_i++] = num[right_i++];
	}
	for (int i = start; i <= end; i++) {
		num[i] = temp[i];
		if (++cnt == K) {
			print();
			return;
		}
	}
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	merge_sort(0, N - 1);
	if (cnt < K) {
		cout << -1;
	}
	return 0;
}