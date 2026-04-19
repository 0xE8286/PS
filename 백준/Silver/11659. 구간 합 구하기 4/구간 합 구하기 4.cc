#include <iostream>
using namespace std;

int N = 0;
int M = 0;

int arr[100001] = { 0, };
int sum[100001] = { 0, };

int s, e;
int ans = 0;

int main(){
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++){
		if (i == 1)
			sum[i] = arr[i];
		else
			sum[i] = sum[i - 1] + arr[i];
	}

	for (int j = 0; j < M; j++){
		scanf("%d %d", &s, &e);
		ans = sum[e] - sum[s - 1];
		//cout << ans << endl;
		printf("%d\n", ans);
	}
}