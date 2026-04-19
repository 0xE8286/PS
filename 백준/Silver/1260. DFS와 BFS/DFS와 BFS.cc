#include <iostream>
using namespace std;

int graph[1001][1001] = { 0, };
int visit[1001] = { 0, };

int s[10001];
int top = 0;

int q[10001];
int f = -1;
int r = -1;

void dfs(int v){

	visit[v] = 1;
	top--;
	cout << v << " ";

	for (int i = 0; i <= 1000; i++){
		if (graph[v][i] == 1 && visit[i] == 0){
			s[++top] = i;
			dfs(s[top]);
		}
	}
	if (top < 0){
		return;
	}
}
/*
void bfs(int v){
	while (f != r){
		visit[q[++f]] = 1;
		cout << v << " ";
		for (int i = 0; i <= 1000; i++){
			if (graph[v][i] == 1 && visit[i] == 0){
				q[++r] = i;
			}
		}
		bfs(q[++f]);
	}
}
*/
int main(){
	int N, M, V;
	int p, c;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++){ 
		cin >> p >> c;
		graph[p][c] = 1;
		graph[c][p] = 1;
	}

	top++;
	dfs(V);
	
	cout << endl;

	for (int i = 0; i <= 1000; i++)
		visit[i] = 0;


	//bfs(V);
	
	q[++r] = V;
	visit[V] = 1;

	while (f != r){
		int v = q[++f];
		cout << v << " ";
		for (int i = 0; i <= 1000; i++){
			if (graph[v][i] == 1 && visit[i] == 0){
				q[++r] = i;
				visit[i] = 1;
			}
		}
	}

	cout << endl;

	return 0;
}