#include <iostream>
using namespace std;

int arr[6] = { 1, 1, 2, 2, 2, 8 };
int input;

int main() {

	for (int i = 0; i < 6; i++) {
		cin >> input;
		cout << arr[i] - input << ' ';
	}
	return 0;
}