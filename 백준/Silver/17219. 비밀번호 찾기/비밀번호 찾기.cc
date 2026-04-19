#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, string> notepad;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	string site;
	string pw;

	while (N--) {
		cin >> site >> pw;
		notepad.insert(make_pair(site, pw));
	}
	while (M--) {
		cin >> site;
		cout << notepad.at(site) << "\n";
	}
	return 0;
}