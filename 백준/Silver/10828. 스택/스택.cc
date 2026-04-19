#include <iostream>
#define MAX_N 10001
using namespace std;

int stack[MAX_N];
int t = 0;
int N;

void push(int x) {
	stack[++t] = x;
}
int pop() {
	if (t == 0) return -1;
	return stack[t--];
}
int size() {
	return t;
}
int empty() {
	if (t == 0) return 1;
	else return 0;
}
int top() {
	if (t == 0) return -1;
	return stack[t];
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	char cmd[6];
	int data;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd[1] == 'u') { //push
			cin >> data;
			push(data);
		}
		else if (cmd[1] == 'o') {
			if (cmd[0] == 'p') { //pop
				cout << pop() << '\n';
			}
			else if (cmd[0] == 't') { //top
				cout << top() << '\n';
			}
		}
		else if (cmd[1] == 'i') {
			cout << size() << '\n';

		}
		else if (cmd[1] == 'm') {
			cout << empty() << '\n';
		}
	}

	return 0;
}