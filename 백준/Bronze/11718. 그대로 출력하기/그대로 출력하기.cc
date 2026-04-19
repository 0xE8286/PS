#include <iostream>
#include <string>

using namespace std;

string a;

int main() {

	getline(cin, a);

	while (a != "") {
		cout << a << endl;
		getline(cin, a);
	}

	return 0;
}