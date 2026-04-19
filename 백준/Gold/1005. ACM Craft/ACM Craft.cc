#include <iostream>

using namespace std;

int T, N, K, W;

int time[1001];
int sub_time[1001];
int visit[1001];
int pre_task[1001]; //선행 작업의 갯수
int graph[1001][1001]; //[node][0] 은 인접 리스트의 갯수

int q[5000];
int f, r;

void put_q() {
	for (int i = 1; i <= N; i++) {
		if (pre_task[i] == 0 && visit[i] == 0) {
			q[++r] = i;
			visit[i] = 1;
		}
	}
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		
		N = 0;
		K = 0;
		W = 0;
		
		for (int i = 0; i < 1001; i++) {

			time[i] = 0;
			sub_time[i] = 0;
			visit[i] = 0;
			pre_task[i] = 0;

			for (int j = 0; j < 1001; j++) {
				graph[i][j] = 0;
			}
		}

		for (int i = 0; i < 5000; i++) {
			q[i] = 0;
		}

		scanf("%d %d", &N, &K);

		for (int i = 1; i <= N; i++)
			scanf("%d", &time[i]);

		for (int i = 1; i <= K; i++) {
			int x = 0;
			int y = 0;

			scanf("%d %d", &x, &y);

			graph[x][y] = 1;
			pre_task[y]++;
		}

		scanf("%d", &W);

		f = 0;
		r = 0;

		put_q();

		while (pre_task[W] != 0) {
			int curr = q[++f];
			for (int i = 1; i <= N; i++) {
				if (graph[curr][i] == 1) {
					pre_task[i]--;
					sub_time[i] = max(sub_time[i], sub_time[curr] + time[curr]);
				}
			}
			put_q();
		}

		cout << sub_time[W] + time[W] << endl;
	}

	return 0;
}