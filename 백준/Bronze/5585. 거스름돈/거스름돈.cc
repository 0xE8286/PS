#include <iostream>
using namespace std;

int N;
int coin[6] = { 500, 100, 50, 10, 5, 1 };

int main(){

	cin >> N;

	int left = 1000 - N;
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		cnt += left / coin[i];
		left %= coin[i];
	}

	cout << cnt;

	return 0;
}