#include <iostream>

#define MAX_N 1000000
using namespace std;

struct Pos {
	int index;
	int value;
};

Pos pos[MAX_N + 1];
Pos temp[MAX_N + 1];
int ans[MAX_N + 1];

void merge_sort(Pos* arr, int start, int mid, int end) {
	int left_i = start;
	int temp_i = start;
	int right_i = mid + 1;
	while (left_i <= mid && right_i <= end) {
		if (arr[left_i].value < arr[right_i].value)
			temp[temp_i++] = arr[left_i++];
		else
			temp[temp_i++] = arr[right_i++];
	}
	while (left_i <= mid) {
		temp[temp_i++] = arr[left_i++];
	}
	while (right_i <= end) {
		temp[temp_i++] = arr[right_i++];
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}

void divide(Pos* arr, int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		divide(arr, start, mid);
		divide(arr, mid + 1, end);
		merge_sort(arr, start, mid, end);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int count = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> pos[i].value;
		pos[i].index = i;
	}
	
	divide(pos, 0, N - 1);

	for (int i = 0; i < N; i++) {
		ans[pos[i].index] = count;
		if (pos[i].value != pos[i + 1].value)
			count++;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}