#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str, org;
	set<string> words;

	cin >> org;
	str = org;
	int N = str.size();
		

	for (int i = 0; i < N - 2 ; i++) {
		for (int j = i + 1; j < N - 1 ; j++) {
			reverse(&str[0], &str[i + 1]);
			reverse(&str[i + 1], &str[j + 1]);
			reverse(&str[j + 1], &str[N]);
			words.insert(str);
			str = org;
		}
	}

	cout << *words.begin() << '\n';
	
	return 0;
}