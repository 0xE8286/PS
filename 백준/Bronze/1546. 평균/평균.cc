#include <iostream>

using namespace std;

int main() {
	
	int n;
	float m[1000] = { 0, };
	float max = 0;
	float sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m[i];

		if (m[i] > max)
			max = m[i];
	}

	for (int i = 0; i < n; i++) {
		m[i] = m[i] / max * 100;
		sum += m[i];
	}
	cout << sum / n;

	return 0;
}