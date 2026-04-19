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

int getsize(char *st) {
	int size = 0;
	while (st[size] != '\0') size++;
	return size;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size = 0;
	int valid = 0;
	char st[102];

	cin.getline(st, 102);

	while (st[0] != '.') {
		size = getsize(st);

		for (int j = 0; j < size; j++) {
			if (st[j] == '(' || st[j] == '[')
				push(st[j]);
			else if (st[j] == ')'){
				if (pop() != '(') {
					valid = -1;
					break;
				}
			}
			else if (st[j] == ']') {
				if (pop() != '[') {
					valid = -1;
					break;
				}
			}
		}
		if (valid == -1 || t != 0)
			cout << "no\n";
		else
			cout << "yes\n";

		cin.getline(st, 102);
		t = 0;
		valid = 0;
	}

	return 0;
}