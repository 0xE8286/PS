#include <iostream>
#include <vector>
#include <map>
using namespace std;

int T, N;

string item, category;
map<string, vector<string>> closet;

int main() {

	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		cin >> N;
		int comb = 1;
				
		for (int i = 0; i < N; i++) {
			cin >> item >> category;
			closet[category].push_back(item);
		}

		for (auto iter = closet.begin(); iter != closet.end(); iter++) {
			comb *= iter->second.size() + 1;
		}

		cout << comb - 1 << endl;
		closet.clear();
	}
	return 0;
}
