#include <iostream>
#define MAX_N 100001
using namespace std;

char stack[MAX_N];
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
	char st[51];

	for (int i = 0; i < N; i++) {
		cin >> st;
		int j = 0;
		t = 0;
		while (st[j] != '\0') {
			if (st[j] == '('){
				push('(');
			}
			if (st[j] == ')'){
				int result = pop();
				if (result == -1) {
					t = -1;
					break;
				}
			}
			j++;
		}
		if (t == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}