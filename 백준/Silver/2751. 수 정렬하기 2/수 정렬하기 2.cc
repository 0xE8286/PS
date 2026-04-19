#include <iostream>
using namespace std;

int N;
int num[1000001];
int temp[1000001];

void merge(int start, int mid, int end) {
	int li = start;
	int ri = mid + 1;
	int ti = start;

	while (li <= mid && ri <= end) {
		temp[ti++] = (num[li] < num[ri]) ? num[li++] : num[ri++];
	}
	while (li <= mid) {
		temp[ti++] = num[li++];
	}
	while (ri <= end) {
		temp[ti++] = num[ri++];
	}
	for (int i = start; i <= end; i++) {
		num[i] = temp[i];
	}
}

void divide(int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	divide(start, mid);
	divide(mid + 1, end);
	merge(start, mid, end);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	divide(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}

	return 0;
}