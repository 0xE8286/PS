#include <iostream>
#include <map>
using namespace std;

int N;
string name, record;
map<string, bool, greater<string>> list;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> record;
		if (record == "enter") list[name] = true;
		else list[name] = false;
	}

	for (auto i = list.begin(); i != list.end(); i++) {
		if (i->second) {
			cout << i->first << '\n';
		}
	}

	return 0;
}