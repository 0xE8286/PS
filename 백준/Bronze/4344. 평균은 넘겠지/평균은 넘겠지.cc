#include <iostream>

using namespace std;

int main() {

	int t, n;
	int score[1000];
	cin >> t;
	
	for (int tc = 0; tc < t; tc++) {
		cin >> n;

		int sum = 0;
		float ave = 0;
		float ratio = 0;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cin >> score[i];
			sum += score[i];
		}
		ave = (float)sum / n;

		for (int i = 0; i < n; i++) {
			if (score[i] > ave) {
				cnt++;
			}
		}
		ratio = (float)cnt / n * 100;
		printf("%.3f%%\n", ratio);
	}
	return 0;
}