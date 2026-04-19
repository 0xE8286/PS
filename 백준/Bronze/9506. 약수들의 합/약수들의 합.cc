#include <iostream>
#include <vector>
using namespace std;
int main() {

	
	while (1) {
		int N;
		vector<bool> check(100000);

		cin >> N;
		if (N == -1) break;
		int half = N / 2;
		int sum = 0;
		for (int i = 1; i <= half; i++) {
			if (N % i == 0) {
				check[i] = true;
				sum += i;
			}
		}
		
		if (sum != N) {
			cout << N << " is NOT perfect.";
		}
		else {
			cout << N << " = ";
			for (int i = 1; i <= half; i++) {
				if (check[i]) {
					cout << i;
					if (i != half) {
						cout << " + ";
					}
				}
			}
		}
		cout << '\n';
	}

	return 0;
}