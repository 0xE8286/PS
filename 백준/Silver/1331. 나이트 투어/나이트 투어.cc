#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

string pos;
map<string, int> visit;
vector<string> route;

bool check(string from, string to) {
	if (visit[to] != 0) return false;
	int diff1 = abs(from[0] - to[0]);
	int diff2 = abs(from[1] - to[1]);
	if (diff1 + diff2 != 3 || diff1 == 0 || diff2 == 0) return false;
	return true;
}

int main() {
	bool isValid = true;
	while (cin >> pos) {
		route.push_back(pos);
	}
	for (int i = 1; i <route.size(); i++) {
		isValid = check(route[i - 1], route[i]);
		if (!isValid) {
			cout << "Invalid";
			return 0;
		}
		visit[route[i]]++;
	}
	isValid = check(*(route.end() - 1), *route.begin());
	if (isValid) {
		cout << "Valid";
	}
	else {
		cout << "Invalid";
	}
	return 0;
}