#include <iostream>
#include <stack>
using namespace std;

int hist[100002];
int N;
struct bar {
	int height;
	int dist;
};
stack<bar> s;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> hist[i];
	}

	int max_width = 0;

	for (int i = 1; i <= N; i++) {
		while (!s.empty() && s.top().height >= hist[i]) {
			bar now = s.top(); s.pop();
			if (!s.empty()) {
				bar prev = s.top();
				max_width = max(max_width, now.height * ((i - 1) - prev.dist));
			}
			else {
				max_width = max(max_width, now.height * (i - 1));
			}
		}

		bar now;
		now.height = hist[i];
		now.dist = i;
		
		s.push(now);
	}

	while (!s.empty()) {
		bar now = s.top(); s.pop();
		if (!s.empty()) {
			bar prev = s.top();
			max_width = max(max_width, now.height * (N - prev.dist));
		}
		else {
			max_width = max(max_width, now.height * N);
		}
	}

	cout << max_width;

	return 0;
}