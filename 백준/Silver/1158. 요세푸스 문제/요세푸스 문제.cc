#include <iostream>
using namespace std;

int queue[25000000];
int ans[10000];
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


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int idx = 0;
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		push(i);
	}

	while (!empty()) {
		for (int i = 1; i <= K; i++) {
			if (i != K) {
				push(pop());
			}
			else {
				ans[idx++] = pop();
			}
		}
	}

	cout << '<';
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cout << ans[i];
		}
		else {
			cout << ", " << ans[i];
		}
	}
	cout << '>';

	return 0;
}