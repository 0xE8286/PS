#include <iostream>
#include <algorithm>
using namespace std;

int index;
pair<int, bool> node[1000001];

int alloc(int value) {
	node[++index].first = value;
	node[index].second = 1;
	return index;
}

struct pq {
	int tree[1000001];
	int size;
	int comp_flag;

	void init(int flag) {
		comp_flag = flag;
		size = 0;
	}

	bool comp(int a, int b) {
		if (comp_flag == 1) {
			if (a > b) {
				return true;
			}
			return false;
		}
		else {
			if (a < b) {
				return true;
			}
			return false;
		}
	}

	void push(int n) {
		tree[++size] = n;
		
		int me = size;
		int parent = size / 2;

		while (me != 1 && comp(node[tree[me]].first, node[tree[parent]].first)) {
			swap(tree[me], tree[parent]);
			me = parent;
			parent = me / 2;
		}
	}

	int pop() {
		if (size <= 0) return 0;

		int top = tree[1];
		tree[1] = tree[size--];

		int me = 1;
		int left, right, child;

		while (me * 2 <= size) {

			left = me * 2;
			right = (me * 2) + 1;

			if (comp(node[tree[left]].first, node[tree[right]].first) || right > size) {
				child = left;
			}
			else {
				child = right;
			}

			if (comp(node[tree[me]].first, node[tree[child]].first)) {
				break;
			}
			else {
				swap(tree[me], tree[child]);
				me = child;
			}
		}
		return top;
	}

	int top() {
		return tree[1];
	}
};

pq min_heap;
pq max_heap;

int T, k, n;
char cmd[2];

void lazy_delete () {
	while (min_heap.size > 0 && node[min_heap.top()].second == 0) {
		min_heap.pop();
	}

	while (max_heap.size > 0 && node[max_heap.top()].second == 0) {
		max_heap.pop();
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		min_heap.init(-1);
		max_heap.init(1);
		index = 0;

		cin >> k;

		for (int i = 0; i < k; i++) {
			cin >> cmd >> n;
			
			if (cmd[0] == 'I') {
				int idx = alloc(n);
				min_heap.push(idx);
				max_heap.push(idx);
			}

			if (cmd[0] == 'D') {
				if (n == -1) {
					int idx = min_heap.pop();
					node[idx].second = 0;
				}
				else if (n == 1) {
					int idx = max_heap.pop();
					node[idx].second = 0;
				}
				lazy_delete();
			}
		}

		if (max_heap.size && min_heap.size) {
			cout << node[max_heap.top()].first << " " << node[min_heap.top()].first << endl;
		}
		else {
			cout << "EMPTY" << endl;
		}
	}

	return 0;
}