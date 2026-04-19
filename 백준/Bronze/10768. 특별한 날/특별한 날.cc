#include <iostream>
using namespace std;

int mon;
int day;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> mon >> day;
	
	if (mon == 2 && day == 18) {
		cout << "Special";
		return 0;
	}

	if (mon == 1) {
		cout << "Before";
		return 0;
	}

	if (mon == 2) {
		if (day < 18) {
			cout << "Before";
		}
		else {
			cout << "After";
		}
	}
	else {
		cout << "After";
	}

	return 0;
}