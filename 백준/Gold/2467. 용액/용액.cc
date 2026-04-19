#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int liquid[100000];
int minimun = 2147483647;
int min_i, min_j;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}

	sort(liquid, liquid + N);
	
	int i = 0;
	int j = N - 1;
	int balance;
	
	while (i != j) {
		balance = liquid[i] + liquid[j];
		if (abs(balance) < minimun) {
			minimun = abs(balance);
			min_i = i;
			min_j = j;
		}
		if (balance == 0) {
			break;
		}
		else if (balance < 0) {
			++i;
		}
		else {
			--j;
		}
	}
	cout << liquid[min_i] << ' ' << liquid[min_j];

	return 0;
}