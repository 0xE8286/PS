#include <iostream>

using namespace std;

int cnt[42] = { 0, };

int main() {
	
	int a = 0; 
	int result = 0;

	for (int i = 0; i < 10; i++) {
		cin >> a;
		if (cnt[a % 42] != 1)
			cnt[a % 42] = 1; 
	}

	for (int i = 0; i < 42; i++) {
		if (cnt[i] == 1) {
			result++;
		}
	}

	cout << result;

	return 0;
}