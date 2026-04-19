#include <iostream>
#define MAX_N 100001
using namespace std;


int N, M;
int a[MAX_N];
int target;
int temp[MAX_N];
bool found = false;

void merge(int *arr, int start, int mid, int end) {
	int left_i = start;
	int temp_i = start;
	int right_i = mid + 1;
	
	while (left_i <= mid && right_i <= end) {
		if (arr[left_i] <= arr[right_i]) 
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
	for (int i = start; i <= end; i++) 
		arr[i] = temp[i];
}

void merge_sort(int *arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void binary_search(int *arr, int start, int end) {
	int mid = (start + end) / 2;

	if (end - start >= 0) {
		if (arr[mid] == target) {
			found = true;
			return;
		}
		else if (target < arr[mid]) {
			binary_search(arr, start, mid - 1);
		}
		else {
			binary_search(arr, mid + 1, end);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	merge_sort(a, 0, N-1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> target;
		binary_search(a, 0, N-1);

		if (found == true)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";

		found = false;
	}
}