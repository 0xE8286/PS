#include <iostream>
#define MAX_N 100001
using namespace std;

int stack[MAX_N];
int num[MAX_N];
char output[MAX_N];
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

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int j = 0;
	int k = 0;
	for (int i = 1; i <= N; i++) {
		push(i);
		output[k++] = '+';

		while (!empty() && num[j] == top()) {
			pop();
			output[k++] = '-';
			j++;
		}
	}
	if (!empty())
		cout << "NO\n";
	else
		for (int i = 0; i < k; i++) cout << output[i] << '\n';

	return 0;
}