#include <iostream>
#include <cmath>

using namespace std;

int main() {

	string num;
	int n;
	int ans = 0;

	cin >> num >> n;

	for (int i = 0; i < num.size(); i++) {
	
		int x = -1;
		if (num[i] >= '0' && num[i] <= '9') x = num[i] - '0';
		if (num[i] >= 'A' && num[i] <= 'Z') x = num[i] - 'A' + 10;
		ans += x * pow(n, num.size() - i - 1);
	}
	cout << ans;
	
	return 0;
}