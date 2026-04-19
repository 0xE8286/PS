#include <iostream>
#define MAX_N 100000
using namespace std;

int x[MAX_N];
int y[MAX_N];

int temp_x[MAX_N];
int temp_y[MAX_N];

bool isSmall(int *x, int *y, int left_i, int right_i) {
	if (x[left_i] < x[right_i]) {
		return true;
	}
	else if (x[left_i] == x[right_i]) {
		if (y[left_i] < y[right_i]) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void merge(int *x, int *y, int start, int mid, int end) {
	int left_i = start;
	int temp_i = start;
	int right_i = mid + 1;
	
	while (left_i <= mid && right_i <= end) {
		if (isSmall(x, y, left_i, right_i)) {
			temp_x[temp_i] = x[left_i];
			temp_y[temp_i++] = y[left_i++];
		}
		else {
			temp_x[temp_i] = x[right_i];
			temp_y[temp_i++] = y[right_i++];
		}
	}
	if (left_i <= mid) {
		while (left_i <= mid) {
			temp_x[temp_i] = x[left_i];
			temp_y[temp_i++] = y[left_i++];
		}
	}
	else {
		while (right_i <= end) {
			temp_x[temp_i] = x[right_i];
			temp_y[temp_i++] = y[right_i++];
		}
	}
	for (int i = start; i <= end; i++) {
		x[i] = temp_x[i];
		y[i] = temp_y[i];
	}
}

void merge_sort(int *x, int *y, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(x, y, start, mid);
		merge_sort(x, y, mid+1, end);
		merge(x, y, start, mid, end);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	merge_sort(x, y, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << x[i] << " " << y[i] << "\n";
	}

	return 0;
}