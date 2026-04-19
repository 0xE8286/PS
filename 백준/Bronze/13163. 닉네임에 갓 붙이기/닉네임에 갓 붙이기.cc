#include <iostream>
#include <string>
using namespace std;

int N;
string id[100];

int main() {

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, id[i]);

		cout << "god";
		for (int j = id[i].find_first_of(' ') + 1; j < id[i].size(); j++) {
			if (id[i][j] == ' ') continue;
			cout << id[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}