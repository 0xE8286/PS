#include <iostream>
#include <map>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";
string problem;
int order[100000];
map<char, int> spell;
int ans;

int main() {

	const char* str = alpha.c_str();

	for (int i = 1; i <= 26; i++) {
		spell.insert({ str[i - 1], i });
	}

	cin >> problem;

	for (int i = 0; i < problem.size(); i++) {
		order[i] = spell[problem[i]];
	}


	for (int i = 1; i < problem.size(); i++) {
		if (order[i] <= order[i - 1]) {
			ans++;
		}
	}

	cout << ans + 1;

	return 0;

}