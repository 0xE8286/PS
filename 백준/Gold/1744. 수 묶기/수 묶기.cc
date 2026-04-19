#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, num;

priority_queue<int> max_q;
priority_queue<int, vector<int>, greater<>> min_q;
int sum;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num <= 0) {
			min_q.push(num);
		}
		else {
			max_q.push(num);
		}
	}

	while (!max_q.empty() && max_q.top() >= 2) {
		if (max_q.size() >= 2) {
			int n1 = max_q.top(); max_q.pop();
			int n2 = max_q.top(); max_q.pop();
			if (n2 != 1) {
				sum += (n1 * n2);
			}
			else {
				sum += (n1 + n2);
			}
		}
		else {
			break;
		}
	}

	while (!min_q.empty()) {
		if (min_q.size() >= 2) {
			int n1 = min_q.top(); min_q.pop();
			int n2 = min_q.top(); min_q.pop();
			sum += (n1 * n2);
		}
		else {
			break;
		}
	}

	while (!max_q.empty()) {
		sum += max_q.top(); 
		max_q.pop();
	}

	while (!min_q.empty()) {
		sum += min_q.top();
		min_q.pop();
	}

	cout << sum;

	return 0;
}