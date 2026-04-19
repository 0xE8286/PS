#include <iostream>
#include <algorithm>
using namespace std;

int edge[3];

int main() {
	cin >> edge[0] >> edge[1] >> edge[2];
	sort(edge, edge+3);
	
	if (edge[0] + edge[1] > edge[2]) {
		cout << edge[0] + edge[1] + edge[2];
	}
	else {
		edge[2] = edge[0] + edge[1] - 1;
		cout << edge[0] + edge[1] + edge[2];
	}

	return 0;
}