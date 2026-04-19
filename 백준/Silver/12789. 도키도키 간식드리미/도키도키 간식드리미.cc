#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N;
int num;
queue<int> q;
stack<int> s;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		q.push(num);
	}

	int next = 1;

	while (!q.empty()) {
		
		if (q.front() == next) {
			q.pop();
			next++;
		}
		else if (!s.empty() && s.top() == next) {
			s.pop();
			next++;
		}
		else {
			s.push(q.front());
			q.pop();
		}
	}

	while (!s.empty()) {
		if (next == s.top()){
			s.pop();
			next++;
		}
		else {
			break;
		}
	}

	if (s.empty()) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}

	return 0;
}