#include <iostream>
#define MAX_N 100000

using namespace std;

void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
	return;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

struct max_heap{
	int size;
	int node[MAX_N +1];
	
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

	int pop() {
		if (size <= 0)
			return 0;

		int top = node[1];
		node[1] = node[size--];

		int me = 1;
		int left, right, child;

		while (me*2 <= size) {
			
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

		return top;
	}
};

int N;
int num;

max_heap heap;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			cout << heap.pop() << '\n';
		}
		else {
			heap.push(num);
		}
	}

	return 0;
}