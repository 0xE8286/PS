#include <iostream>
using namespace std; 

int N, W, H, L;

int main() {

	cin >> N >> W >> H >> L;

	int ans = (W / L) * (H / L);
	ans = min(N, ans);

	cout << ans;

	return 0;
}