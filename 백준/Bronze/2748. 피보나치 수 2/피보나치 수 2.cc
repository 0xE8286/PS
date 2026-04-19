#include <iostream>
using namespace std;

long long int ans[100] = { 0, };

long long int f(int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (ans[n] != 0) return ans[n];
	else{
		ans[n] = f(n - 2) + f(n - 1);
		return ans[n];
	}
}

int main(){
	int N;
	cin >> N;
	cout << f(N);
	return 0;
}