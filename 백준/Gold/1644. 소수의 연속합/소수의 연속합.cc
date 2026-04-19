#include <iostream>
using namespace std;

int N;
bool prime[4000001];
int primes[4000001];
int cnt = 0;
int ans = 0;

int main() {

	cin >> N;

	if (N == 1) {
		cout << 0;
		return 0;
	}
	
	fill(prime, prime + N + 1, true);
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= N; i++) {
		if (prime[i] == true) {
			primes[cnt++] = i;
			for (int j = i*2; j <= N; j+=i) { 
				prime[j] = false;
			}
		}
	}

	int start = 0;
	int end = 0;
	int sum = primes[start];

	while (true) {
		if (sum == N) {
			ans++;
			if (++end == cnt) break;
			sum += primes[end];
		}
		else if (sum < N) {
			if (++end == cnt) break;
			sum += primes[end];
		}
		else {
			sum -= primes[start];
			if (++start == cnt) break;
		}
	}
	cout << ans;

	return 0;
}