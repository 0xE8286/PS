#include <bits/stdc++.h>
using namespace std;

char mobis[5];
int main() {
	string hyundai;
	cin >> hyundai;
	for (int i = 0; i < hyundai.length(); i++) {
		if (hyundai[i] == 'M') mobis[0]++;
		else if (hyundai[i] == 'O') mobis[1]++;
		else if (hyundai[i] == 'B') mobis[2]++;
		else if (hyundai[i] == 'I') mobis[3]++;
		else if (hyundai[i] == 'S') mobis[4]++;
	}

	for (int i = 0; i < 5; i++) {
		if (mobis[i] <= 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}