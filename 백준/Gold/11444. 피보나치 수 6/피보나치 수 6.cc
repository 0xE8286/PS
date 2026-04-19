#include <iostream>
#include <unordered_map>

#define divide 1000000007

using namespace std;

unordered_map<long long, long long> dp;
long long N;

long long fibo(long long n) {

	if (dp[n]){
		return dp[n];
	}
	long long ans = 0;
	if (n % 2 == 0) {
		ans = (fibo(n / 2) * ((fibo(n / 2 + 1) + fibo(n / 2 - 1)))) % divide;
	}
	else {
		ans = (((fibo((n + 1) / 2) * fibo((n + 1) / 2)) % divide) 
			+ ((fibo((n - 1) / 2) * fibo((n - 1) / 2)) % divide))
			% divide;
	}

	dp[n] = ans % divide;
	return dp[n];
}

int main() {

	cin >> N;

	dp[0] = 0; 
	dp[1] = 1;
	dp[2] = 1;

	cout << fibo(N);

	return 0;
}