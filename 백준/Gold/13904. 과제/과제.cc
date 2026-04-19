#include <iostream>
#include <queue>

using namespace std;

int N;
int schedule[1001];
int sum;

typedef pair<int, int> homework;
priority_queue<homework> todo;

int main() {

	cin >> N;
	int d, w;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		todo.push(homework(w, d));
	}

	while (!todo.empty()) {
		homework top = todo.top();
		todo.pop();

		for (int i = top.second; i >= 1; i--) {
			if (schedule[i] == 0) {
				schedule[i] = top.first;
				break;
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		sum += schedule[i];
	}

	cout << sum;

	return 0;
}
