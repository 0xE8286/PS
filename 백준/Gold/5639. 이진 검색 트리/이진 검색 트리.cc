#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int child[1000000][2];
int root, num;

void post(int v) {
	if (v == 0) return;
	post(child[v][0]);
	post(child[v][1]);
	cout << v << '\n';
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> root;
	while (cin >> num) {
		int prev = -1;
		int curr = root;
				
		while (curr) {
			if (num < curr) {
				prev = curr;
				curr = child[curr][0];
			}
			else {
				prev = curr;
				curr = child[curr][1];
			}
		}
		if (num < prev) child[prev][0] = num;
		else child[prev][1] = num;
	}

	post(root);

	return 0;
}