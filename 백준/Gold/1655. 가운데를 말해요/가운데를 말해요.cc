#include <iostream>
#define MAX_N 100000

using namespace std;

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
	return;
}

struct max_heap {
	int size;
	int node[MAX_N + 1];

	void push(int x) {
		node[++size] = x;

		int me = size;
		int parent = size / 2;

		while (node[me] > node[parent] && me != 1) {
			swap(node[me], node[parent]);
			me = parent;
			parent = me / 2;
		}
	}

	void pop() {
		if (size <= 0) return;

		node[1] = node[size--];

		int me = 1;
		int left, right, child;

		while (me * 2 <= size) {

			left = me * 2;
			right = (me * 2) + 1;

			if (node[left] > node[right] || right > size) {
				child = left;
			}
			else {
				child = right;
			}

			if (node[me] > node[child]) {
				break;
			}
			else {
				swap(node[me], node[child]);
				me = child;
			}
		}
	}
	int top() {
		return node[1];
	}
};

struct min_heap {
	int size;
	int node[MAX_N + 1];

	void push(int x) {
		node[++size] = x;

		int me = size;
		int parent = size / 2;

		while (node[me] < node[parent] && me != 1) {
			swap(node[me], node[parent]);
			me = parent;
			parent = me / 2;
		}
	}

	void pop() {
		if (size <= 0) return;

		node[1] = node[size--];

		int me = 1;
		int left, right, child;

		while (me * 2 <= size) {

			left = me * 2;
			right = (me * 2) + 1;

			if (node[left] < node[right] || right > size) {
				child = left;
			}
			else {
				child = right;
			}

			if (node[me] < node[child]) {
				break;
			}
			else {
				swap(node[me], node[child]);
				me = child;
			}
		}
	}
	int top() {
		return node[1];
	}
};

int N;
int num;

max_heap maxheap;
min_heap minheap;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (maxheap.size == 0) {
			maxheap.push(num);
		}
		else {
			if (maxheap.size > minheap.size) {
				minheap.push(num);
			}
			else {
				maxheap.push(num);
			}
			if (maxheap.size > 0 && minheap.size > 0 && maxheap.top() > minheap.top()) {
				int a = maxheap.top();
				int b = minheap.top();

				maxheap.pop();
				minheap.pop();

				maxheap.push(b);
				minheap.push(a);
			}
		}

		cout << maxheap.top() << '\n';
	}

	return 0;
}