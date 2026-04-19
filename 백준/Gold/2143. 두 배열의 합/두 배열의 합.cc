#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;

int A[1000];
int B[1000];

vector<int> sumA;
vector<int> sumB;

int main() {

	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N; i++) {
		int sum = A[i];
		sumA.push_back(A[i]);
		for (int j = i + 1; j < N; j++) {
			sum += A[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		int sum = B[i];
		sumB.push_back(B[i]);
		for (int j = i + 1; j < M; j++) {
			sum += B[j];
			sumB.push_back(sum);
		}
	}
	sort(sumB.begin(), sumB.end());
	long long cnt = 0;
	
	for (int a : sumA) {
		int diff = T - a;
		auto lower = lower_bound(sumB.begin(), sumB.end(), diff);
		auto upper = upper_bound(sumB.begin(), sumB.end(), diff);
		cnt += (upper-lower);
	}
	cout << cnt;
	
	return 0;
}