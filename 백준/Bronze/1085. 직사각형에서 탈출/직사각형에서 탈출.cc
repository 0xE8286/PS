#include <iostream>
using namespace std;

int x, y, w, h;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> x >> y >> w >> h;
	
	int ans = x > y ? y : x;
	ans = ans > w - x ? w - x : ans;
	ans = ans > h - y ? h - y : ans;
	
	cout << ans;

	return 0;
}