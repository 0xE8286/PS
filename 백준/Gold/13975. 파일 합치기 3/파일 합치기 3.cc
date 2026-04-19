#include <iostream>
#include <queue>
using namespace std;

typedef long long int lli;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N; 
		
		int size;
		priority_queue<lli, vector<lli>, greater<lli>> pq;
		
		for (int i = 0; i < N; i++) {
			cin >> size;
			pq.push(size);
		}
		
		lli sum = 0;
		
		while (pq.size() > 1) {
			lli c1 = pq.top(); pq.pop();
			lli c2 = pq.top(); pq.pop();
			sum += c1 + c2;
			pq.push(c1 + c2);
		}
		
		cout << sum << '\n';
	}
	return 0;
}