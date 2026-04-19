#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	char str[51];

	cin >> N;
	cin.ignore();

	for (int i = 1; i <= N; i++) {
		cin.getline(str, 51, '\n');
		cout << i << '.' << ' ' << str << '\n';
	}
	
	return 0;
}