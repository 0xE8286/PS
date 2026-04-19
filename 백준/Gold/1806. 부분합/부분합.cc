#include <iostream>
using namespace std;

int N, S;
int numbers[100000];
int min_length = 100001;

int main() {

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	int start = 0;
	int end = 0;
	int sum = numbers[start];

	while (end < N) {
		if (sum >= S) {
			int len = end - start + 1;
			if (len < min_length) {
				min_length = len;
			}
			sum -= numbers[start];
			start++;
		}
		else {
			if (++end == N) break;
			sum += numbers[end];
		}
	}

	if (min_length == 100001) {
		cout << 0;
	}
	else {
		cout << min_length;
	}
	
	return 0;
}