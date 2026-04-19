#include <iostream>

using namespace std;

int N;
int num[12];
int oper[4];
int max_result = -2147483648;
int min_result = 2147483647;

int getResult(int curr, int op, int nextNum) {
	if (op == 0)
		return curr + nextNum;
	else if (op == 1)
		return curr - nextNum;
	else if (op == 2)
		return curr * nextNum;
	else
		return curr / nextNum;
}

void dfs(int* op, int num_i, int curr) {
	if (op[0] + op[1] + op[2] + op[3] == 0) {
		if (curr > max_result)
			max_result = curr;
		if (curr < min_result)
			min_result = curr;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			dfs(oper, num_i + 1, getResult(curr, i, num[num_i+1]));
			oper[i]++;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4;i++){
		cin >> oper[i];
	}
	dfs(oper, 0, num[0]);

	cout << max_result << "\n";
	cout << min_result << "\n";

	return 0;
}