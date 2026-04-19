#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pos;
pos v1, v2, v3, v4;

int main() {

	cin >> v1.first >> v1.second;
	cin >> v2.first >> v2.second;
	cin >> v3.first >> v3.second;

	if (v1.first == v2.first) v4.first = v3.first;
	else if (v1.first == v3.first) v4.first = v2.first;
	else v4.first = v1.first;

	if (v1.second == v2.second) v4.second = v3.second;
	else if (v1.second == v3.second) v4.second = v2.second;
	else v4.second = v1.second;

	cout << v4.first << ' ' << v4.second;

	return 0;
}