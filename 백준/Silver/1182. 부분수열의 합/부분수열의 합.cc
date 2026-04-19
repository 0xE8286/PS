#include <iostream>
using namespace std;

int num[100001] = { 0, };
int bin[100001] = { 0, };

int s[10001];
int top = 0;

int N = 0;
int S = 0;
int sum = 0;
int cnt = 0;

void dfs(int seq){
	if (seq == N) {
		sum = 0;
		for (int i = 0; i < N; i++){
			if (bin[i] == 1){
				sum += num[i];
			}
		}
		if (S == sum)
			cnt++;
		
		return;
	}
	else {
		for (int i = 0; i < 2; i++){
			bin[seq] = i;
			dfs(seq + 1);
		}
	}
}

int main(){

	cin >> N >> S;

	for (int i = 0; i < N; i++){
		cin >> num[i];
	}

	dfs(0);

	if (S == 0)
		cnt--;

	cout << cnt << endl;

	return 0;
}