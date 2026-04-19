#include <iostream>
using namespace std;

int numbers[1025][1025];
int sum[1025][1025];

int N, M;
int sx, sy, ex, ey;

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &numbers[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + numbers[i][j];
		}
	}
		

	for (int i = 0; i < M; i++){
		
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		printf("%d\n", sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1]);
	}
}