#include <iostream>

using namespace std;

int A, B, V;
int ans;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> V;
	
	if (V - A <= 0) {
		ans = 1;
	}
	else if ((V - A) % (A - B) == 0) {
		ans = (V - A) / (A - B) + 1;
	}	
	else {
		ans = (V - A) / (A - B) + 2;
	}
	
	cout << ans;

	return 0;
}