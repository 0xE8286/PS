#include <iostream>

using namespace std;


int stack[1000001];
int index = -1;
int N, cmd, param;

void push(int X) {
	stack[++index] = X;
}

int pop() {
	if (index >= 0) {
		return stack[index--];
	}
	return -1;
}

int size() {
	return index + 1;
}

int isEmpty() {
	if (index >= 0) {
		return 0;
	}
	return 1;
}

int top() {
	if (index >= 0) {
		return stack[index];
	}
	return -1;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> param;
			push(param);
		}
		else if (cmd == 2) {
			cout << pop() << "\n";
		}
		else if (cmd == 3) {
			cout << size() << "\n";
		}
		else if (cmd == 4) {
			cout << isEmpty() << "\n";
		}
		else {
			cout << top() << "\n";
		}
	}
}