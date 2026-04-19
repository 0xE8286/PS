#include <iostream>

using namespace std;

int N;
int card[10000];
int front;
int rear = -1;

void push(int x) {
	card[++rear] = x;
}
int pop() {
	if (rear < front)
		return -1;
	return card[front++];
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		push(i);
	}

	while (front < rear) {
		cout << pop() << " ";
		push(pop());
	}
	cout << pop();

	return 0;
}