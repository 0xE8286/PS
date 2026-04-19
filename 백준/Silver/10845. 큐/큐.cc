#include <iostream>
using namespace std;

int queue[1000001];
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
	char cmd[6];
	int data;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd[1] == 'u') {
			cin >> data;
			push(data);
		}
		if (cmd[1] == 'o') {
			cout << pop() << "\n";
		}
		if (cmd[1] == 'i') {
			cout << size() << "\n";
		}
		if (cmd[1] == 'm') {
			cout << empty() << "\n";
		}
		if (cmd[1] == 'r') {
			cout << front() << "\n";
		}
		if (cmd[1] == 'a') {
			cout << back() << "\n";
		}
	}

	return 0;
}