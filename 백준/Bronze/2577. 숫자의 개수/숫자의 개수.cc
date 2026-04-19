#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int num = 0;
	char temp[10];
	int count[10] = { 0, };

	cin >> a >> b >> c;

	num = a * b * c;

	sprintf(temp, "%d", num);

	int i = 0;
	while (temp[i] != '\0') {
		count[temp[i] - 48]++;
		i++;
	}

	for (int i = 0; i < 10; i++) {
		cout << count[i] << "\n";
	}

	return 0;
}