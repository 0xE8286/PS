#include <iostream>
using namespace std;

string gazi[10][10];

bool check_width() {

	for (int i = 0; i < 10; i++) {
		string start_gazi = gazi[i][0];
		bool ok = 1;
		
		for (int j = 1; j < 10; j++) {
			if (gazi[i][j] != start_gazi) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return 1;
		}
	}
	return 0;
}
bool check_height() {

	for (int i = 0; i < 10; i++) {
		string start_gazi = gazi[0][i];
		bool ok = 1;

		for (int j = 1; j < 10; j++) {
			if (gazi[j][i] != start_gazi) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return 1;
		}
	}
	return 0;
}

int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> gazi[i][j];
		}
	}

	cout << (check_width()|| check_height());

	return 0;
}