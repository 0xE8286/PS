#include <iostream>
#define MAX_N 1000001
using namespace std;

int stack[MAX_N];
int num[MAX_N];
int output[MAX_N];
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

int getsize(char *st) {
	int size = 0;
	while (st[size] != '\0') size++;
	return size;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int k = 0;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		output[i] = -1;
	}

	for (int i = 0; i < N; i++) {
		while (!empty() && num[top()] < num[i]) {
			output[top()] = num[i];
			pop();
		}
		push(i);
	}

	for (int i = 0; i < N; i++) {
		cout << output[i] << " ";
	}

	return 0;
}