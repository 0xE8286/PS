#include <iostream>

using namespace std;

#define MAX_N 10001

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int cnt[MAX_N] = {0, };
	cin >> N; 

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		cnt[temp]++;
	}

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < cnt[i]; j++){
			cout << i << "\n";
		}
	}
	return 0;
}