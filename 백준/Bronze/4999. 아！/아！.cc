#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	string jaehwan;
	string doctor;

	cin >> jaehwan >> doctor;
	cout << (jaehwan.size() >= doctor.size() ? "go" : "no");

	return 0;
}
