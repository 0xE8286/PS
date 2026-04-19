#include <iostream>	

using namespace std;

int A, B, C;
int S, V;
int L;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C >> S >> V >> L;

	int needs = 25000 - (L*100);
	int timeSum = 0;

	while (needs > 0) {
		if (V) {
			needs -= (C * 30);
			timeSum += 30;

			if (needs < 0) {
				timeSum += (needs/C);
			}
			V--;
			continue;
		}
		if (S) {
			needs -= (B * 30);
			timeSum += 30;

			if (needs < 0) {
				timeSum += (needs/B);
			}
			S--;
			continue;
		}
		timeSum += needs / A;
		needs = needs % A;
		if (needs) {
			timeSum += 1;
			needs = 0;
		}
	}

	cout << timeSum;

	return 0;
}