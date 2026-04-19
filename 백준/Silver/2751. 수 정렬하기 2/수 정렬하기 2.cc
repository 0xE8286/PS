#include <iostream>

#define MAX_N 1000000

using namespace std;

void merge(int *num, int start, int mid, int end) {
	int temp_i = start;
	int left_i = start;
	int right_i = mid + 1;
	int temp[MAX_N];

	while (left_i <= mid && right_i <= end) {
		if (num[left_i] < num[right_i])
			temp[temp_i++] = num[left_i++];
		else
			temp[temp_i++] = num[right_i++];
	}
	if (left_i <= mid) {
		for (int i = left_i; i <= mid; i++) {
			temp[temp_i++] = num[i];
		}
	}
	else {
		for (int i = right_i; i <= end; i++) {
			temp[temp_i++] = num[i];
		}
	}
	for (int i = start; i <= end; i++) {
		num[i] = temp[i];
	}
}

void merge_sort(int* num, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(num, start, mid);
		merge_sort(num, mid+1, end);
		merge(num, start, mid, end);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int a[MAX_N];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	merge_sort(a, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}