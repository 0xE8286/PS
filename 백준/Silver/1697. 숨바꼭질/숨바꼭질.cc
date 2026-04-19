#include <iostream>
using namespace std;

int N = 0;
int K = 0;

int q[10000000];
int v[100001];

int f = -1;	
int r = -1;

int cur = 0;
int step = 0;
int ans = 0;

bool isSafe(int i){
	if (i >= 0 && i <= 100000){
		return true;
	}
	else{
		return false;
	}
}

int main(){

	cin >> N >> K;

	q[++r] = N;
	v[N] = 1;

	while (f != r){
		int cur = q[++f];

		if (cur == K){
			ans = v[cur];
			break;
		}

		if (isSafe(cur + 1) && v[cur + 1] == 0){
			q[++r] = cur + 1;
			v[cur + 1] = v[cur] + 1;
		}
		if (isSafe(cur - 1) && v[cur - 1] == 0){
			q[++r] = cur - 1;
			v[cur - 1] = v[cur] + 1;
		}
		if (isSafe(cur * 2) && v[cur * 2] == 0){
			q[++r] = cur * 2;
			v[cur * 2] = v[cur] + 1;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}