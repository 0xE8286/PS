#include <iostream>
#define MAX_N 1000000

using namespace std;

struct LIS{
	int size;
	int num[MAX_N];

	void push_back(int x) {
		num[size++] = x;
	}
	void replace(int i, int x) {
		num[i] = x;
	}
	int top_back() {
		if (size <= 0)
			return -1;
		return num[size - 1];
	}
	int pop_back() {
		if (size <= 0) {
			return -1;
		}
		return num[--size];
	}
	int get_size() {
		return size;
	}
	int lower_bound(int find) {
		int start = 0;
		int end = size - 1;

		while (start < end) {
			int mid = (start + end) / 2;
			if (num[mid] < find) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}
		return end;
	}
};

int N;
int num;

LIS list;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> num;
	list.push_back(num);

	for (int i = 1; i < N; i++) {
		cin >> num;
		if (list.top_back() < num) {
			list.push_back(num);
		}
		else {
			int index = list.lower_bound(num);
			list.replace(index, num);
		}
	}

	cout << list.get_size();

	return 0;
}