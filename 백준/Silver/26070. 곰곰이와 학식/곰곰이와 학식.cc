#include <iostream>
using namespace std;

long long gom[3];
long long ticket[3];

void pay() {
	for (int i = 0; i < 3; i++) {
		if (gom[i] < ticket[i]) {
			ticket[i] -= gom[i];
			gom[i] = 0;
		}
		else {
			gom[i] -= ticket[i];
			ticket[i] = 0;
		}
	}
}

int main() {

	cin >> gom[0] >> gom[1] >> gom[2];
	cin >> ticket[0] >> ticket[1] >> ticket[2];

	long long goms = gom[0] + gom[1] + gom[2];

	pay();

	ticket[1] += ticket[0] / 3;
	ticket[0] = ticket[0] % 3;

	pay();

	ticket[2] += ticket[1] / 3;
	ticket[1] = ticket[1] % 3;

	pay();

	ticket[0] += ticket[2] / 3;
	ticket[2] = ticket[2] % 3;
	
	pay();

	ticket[1] += ticket[0] / 3;
	ticket[0] = ticket[0] % 3;

	pay();

	cout << goms - (gom[0] + gom[1] + gom[2]);

	return 0;
}