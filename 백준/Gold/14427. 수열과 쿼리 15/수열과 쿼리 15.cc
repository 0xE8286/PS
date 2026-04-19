#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int index;
	int value;
	bool operator <(node another) {
		if (value < another.value) return true;
		if (value == another.value && index < another.index) return true;
		return false;
	}
};

struct heap {
	node tree[100007];
	int heap_index[100007];
	int size;

	void init() {
		size = 0;
	}

	void update(int curr) {
		int parent;
		while (curr > 1) {
			parent = curr / 2;
			if (tree[curr] < tree[parent]) {
				swap(tree[parent], tree[curr]);
				swap(heap_index[tree[parent].index], heap_index[tree[curr].index]);
				curr = parent;
			}
			else {
				break;
			}
		}
	}

	void downdate(int curr) {
		int child, left, right;
		while (curr * 2 <= size) {
			left = curr * 2;
			right = curr * 2 + 1;

			if (right > size || tree[left] < tree[right]) {
				child = left;
			}
			else {
				child = right;
			}

			if (tree[child] < tree[curr]) {
				swap(tree[child], tree[curr]);
				swap(heap_index[tree[child].index], heap_index[tree[curr].index]);
				curr = child;
			}
			else {
				break;
			}
		}
	}

	void push(node n) {
		tree[++size] = n;
		heap_index[n.index] = size;
		update(size);
	}

	void modify(int index, int value) {
		int curr = heap_index[index];
		tree[curr].value = value;
		update(curr);
		downdate(curr);
	}

	int top() {
		return tree[1].index;
	}
};

heap h;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int cmd, idx, num;
	
	node temp;
	h.init();

	cin >> N;

	for (int i = 1; i <= N; i++) {
		temp.index = i;
		cin >> temp.value;
		h.push(temp);
	}

	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> idx >> num;
			h.modify(idx, num);
		}
		else if (cmd == 2) {
			cout << h.top() << "\n";
		}
	}
	return 0;
}