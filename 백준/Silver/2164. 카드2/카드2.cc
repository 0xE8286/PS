#include <iostream>
using namespace std;

int queue[10000001];
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

	int N;
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		push(i);
	}

	while (size() != 1) {
		pop();
		push(pop());
	}

	cout << front();

	return 0;
}