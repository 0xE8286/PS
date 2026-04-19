#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N;
int A[1001];
int D[1001];
int cnt;

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				D[i] = max(D[i], D[j] + 1);
				cnt = max(cnt, D[i]);
			}
		}

	}
	cout << cnt << '\n';
	
	vector<int> seq;
	for (int i = N; i >= 1; i--) {
		if (D[i] == cnt) {
			seq.push_back(A[i]);
			if (--cnt == 0) {
				break;
			}
		}
	}
	reverse(seq.begin(), seq.end());
	for (int s : seq) {
		cout << s << ' ';
	}

	return 0;
}