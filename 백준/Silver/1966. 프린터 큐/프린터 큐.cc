#include <iostream>
using namespace std;

int queue[100000];
int weight[101];
int head = 0;
int tail = -1;

int empty() {
	if (head > tail)
		return 1;
	return 0;
}

int front() {
	if (!empty()) {
		return queue[head];
	}
	return -1;
}

int back() {
	if (!empty()) {
		return queue[tail];
	}
	return -1;
}

void push(int x) {
	queue[++tail] = x;
}

int pop() {
	if (!empty()) {
		return queue[head++];
	}
	return -1;
}

int size() {
	return tail - head + 1;
}

void init() {
	head = 0;
	tail = -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N, M, tmp;

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();

		cin >> N >> M;
		int cnt = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			weight[i] = tmp;
			push(i);
		}
		
		while (true) {
			int ok = 1;
			for (int i = head; i <= tail; i++) {
				if (weight[front()] < weight[queue[i]]) {
					push(pop());
					ok = 0;
					break;
				}
			}
			if (ok) {
				int out = pop();
				cnt++;
				if (out == M) {
					cout << cnt << "\n";
					break;
				}
			}
		}
	}

	return 0;
}