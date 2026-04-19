#include <iostream>
using namespace std;

int N;
int p[500000];
int max_increase;
int max_decrease;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	
	int increase = 0;
	int decrease = 0;
	
	for (int i = 1; i < N; i++) {
		if (p[i - 1] < p[i]) {
			max_increase = max(max_increase, ++increase);
			decrease = 0;
		}
		else if (p[i - 1] > p[i]) {
			max_decrease = max(max_decrease, ++decrease);
			increase = 0;
		}
	}
	cout << max(max_increase, max_decrease) + 1;
	
	return 0;
}