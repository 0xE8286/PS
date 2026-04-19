#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int N;
lli liquid[5000];

lli min_diff = INT64_MAX;
int min_i, min_j, min_k;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}

	sort(liquid, liquid + N);

	for (int k = 0; k < N; k++) {
		int i = k + 1;
		int j = N - 1;

		while (i < j) {
			lli sum = liquid[i] + liquid[j] + liquid[k];
			if (abs(sum) < min_diff) {
				min_diff = abs(sum);
				min_i = i;
				min_j = j;
				min_k = k;
			}
			if (sum == 0) {
				break;
			}
			else if (sum < 0) {
				i++;
			}
			else {
				j--;
			}
		}
		if (min_diff == 0) {
			break;
		}
	}
	cout << liquid[min_k] << ' ' << liquid[min_i] << ' ' << liquid[min_j];

	return 0;
}