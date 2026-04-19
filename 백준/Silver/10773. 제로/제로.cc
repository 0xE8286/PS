#include <iostream>
#define MAX_N 100001
using namespace std;

int stack[MAX_N];
int t;
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

	int num;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			pop();
		}
		else {
			push(num);
		}
	}
	for (int i = 1; i <= t; i++) {
		sum += stack[i];
	}
	cout << sum << "\n";

	return 0;
}