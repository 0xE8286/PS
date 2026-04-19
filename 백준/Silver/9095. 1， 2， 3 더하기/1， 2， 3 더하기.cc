#include<iostream>
using namespace std;

int T = 0;
int N = 0;

int sum = 0;
int cnt = 0;

void dfs(int num){
	if (sum >= N){
		if (sum == N)
			cnt++;
		return;
	}
	else {
		for (int i = 1; i <= 3; i++){
			sum += i;
			dfs(sum + i);
			sum -= i;
		}
	}
}

int main(){
	
	cin >> T ;
	for (int i = 0; i < T; i++){
		cin >> N;

		sum = 0;
		cnt = 0;

		dfs(0);
		cout << cnt << endl;
	}
	
	return 0;
}