#include <iostream>	
#include <algorithm>

using namespace std;
typedef long long ll;

int T;
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {

		ll N;
		ll max_a = 0, max_b = 0, max_c = 0;
		bool is_fail = false;
		
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			ll a, b, c, p;
			cin >> a >> b >> c >> p;
			
			max_a = max(a, max_a);
			max_b = max(b, max_b);
			max_c = max(c, max_c);

			if (p < (max_a + max_b + max_c + i)) {
				is_fail = true;
			}
		}
		if (is_fail) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}