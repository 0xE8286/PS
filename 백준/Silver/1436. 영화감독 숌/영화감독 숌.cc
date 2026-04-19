#include <iostream>

using namespace std;

#define MAX_N 10

int check666(char* num) {
	for (int i = 0; i < MAX_N-3; i++) {
		if (num[i] == '6' && num[i + 1] == '6' && num[i + 2] == '6') {
			return 1;
		}
	}
	return 0;
}

int main() {
	char num_char[MAX_N];
	int N;
	int i = 0;
	int cnt = 0;
	int last_val = 0;

	cin >> N;
	
	while (cnt < N) {
		sprintf(num_char, "%d", i);
		if (check666(num_char) == 1) {
			cnt++;
			last_val = i;
		}
		i++;
	}
	cout << last_val;

	return 0;
}