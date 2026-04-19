#include <iostream>
#include <stack>

#define teamed -1
#define alone -2

using namespace std;

int T, N;
int wanted[100001];
int visit[100001];

void init() {
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
}

void dfs(int curr, stack<int>&route, bool&isSuccess) {
	int next = wanted[curr];
	
	if (visit[next] == 1) {
		isSuccess = true;
		route.push(next);
		return;
	}
	if (visit[next] == 0) {
		visit[next] = 1;
		route.push(next);
		dfs(next, route, isSuccess);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			cin >> wanted[i];
		}

		init();

		for (int i = 1; i <= N; i++) {
			if (visit[i] != 0) continue;
			
			bool isSuccess = false;
			stack<int> route;
			
			route.push(i);
			visit[i] = 1;

			dfs(i, route, isSuccess);

			if (isSuccess) {
				int cycle_meet = route.top(); route.pop();
				
				while (route.top() != cycle_meet) {
					visit[route.top()] = teamed;
					route.pop();
				}
				visit[route.top()] = teamed; //만나는 지점
				route.pop();

				while (!route.empty()) {
					visit[route.top()] = alone;
					route.pop();
				}
			}
			else {
				while (!route.empty()) {
					visit[route.top()] = alone;
					route.pop();
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (visit[i] == alone) ans++;
		}
		cout << ans << '\n';

	}
	return 0;
}