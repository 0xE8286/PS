#include <iostream>
#include <algorithm>

#define INT_MAX 2147483647 

using namespace std;

int N;
int val[100000];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	sort(val, val + N);
	
	int i = 0;
	int j = N - 1;

	int min_diff = INT_MAX;
	int org_sum;

	while (i != j) {
		int sum = val[i] + val[j];

		if (abs(sum) < min_diff) {
			min_diff = abs(sum);
			org_sum = sum;
		}
		
		if (sum < 0) {
			i++;
		}
		else {
			j--;
		}
	}

	cout << org_sum;

	return 0;
}