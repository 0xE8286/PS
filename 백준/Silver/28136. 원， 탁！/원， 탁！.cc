#include <iostream>
#include <vector>
using namespace std;

int N;
int num[1000001];
int tak;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 2; i <= N; i++) {
		if (num[i - 1] >= num[i]) tak++;
	}
	if (num[N] >= num[1]) tak++;
	
	cout << tak;

	return 0;
}