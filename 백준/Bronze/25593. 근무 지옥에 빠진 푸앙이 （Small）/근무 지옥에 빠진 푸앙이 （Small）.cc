#include <iostream>
#include <map>
using namespace std;

int N;
string name;

map<string, int> hr;
int hour[4] = { 4, 6, 4, 10 };

int main() {

	cin >> N;
	
	for (int w = 0; w < N; w++) {
		for (int t = 0; t < 4; t++) {
			for (int d = 0; d < 7; d++) {
				cin >> name;
				if (name == "-") {
					continue;
				}
				hr[name] += hour[t];
			}
		}
	}

	int min_h = 987654321;
	int max_h = 0;

	for (auto h : hr) {
		min_h = min(h.second, min_h);
		max_h = max(h.second, max_h);
	}

	if (max_h - min_h <= 12) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}