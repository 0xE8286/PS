#include <iostream>
using namespace std;

bool num[1001];
int N, K;

int main() {

	cin >> N >> K;

	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		if (num[i] == true) continue;
		for (int j = i; j <= N; j += i) {
			if (num[j] == true) continue;
			
			num[j] = true; 
			cnt++;
			
			if (cnt == K) {
				cout << j << '\n';
				return 0;
			}
		}
	}
	return 0;
}