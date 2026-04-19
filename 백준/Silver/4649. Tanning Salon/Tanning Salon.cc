#include <iostream>
#include <unordered_set>

using namespace std;

int bed;
string customer;
unordered_set<char> set;

int main() {
	
	cin >> bed;
	while (bed != 0) {
		cin >> customer;

		int away = 0;
		for (char c : customer) {
			if (set.find(c) == set.end()) {
				if (set.size() >= bed) {
					away++;
					continue;
				}
				set.insert(c);
			}
			else {
				set.erase(c);
			}
		}
		away /= 2;

		if (away == 0) {
			cout << "All customers tanned successfully.\n";
		}
		else {
			cout << away << " customer(s) walked away.\n";
		}

		cin >> bed;
	}

	return 0;
}