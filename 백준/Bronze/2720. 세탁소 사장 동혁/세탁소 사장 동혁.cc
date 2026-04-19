#include <iostream>
#include <vector>
using namespace std;

int T, C;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> C;
		vector<int> coin;
		coin.push_back(C / 25);
		C %= 25;
		coin.push_back(C / 10);
		C %= 10;
		coin.push_back(C / 5);
		C %= 5;
		coin.push_back(C / 1);
		C %= 1;
		for (auto i = coin.begin(); i != coin.end(); i++) {
			cout << *i << ' ';
		}
		cout << '\n';
	}
	return 0;
}