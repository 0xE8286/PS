#include <iostream>

using namespace std;
typedef long long ll;

int T, N;
ll h[100001];

ll getSize(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return h[s];

	int mid = (s + e) / 2;
	ll size = max(getSize(s, mid), getSize(mid, e));
	
	int l = mid;
	int r = mid;

	ll width = 1;
	ll height = h[mid];

	while (width < e - s) {
		ll lh = (l > s) ? min(height, h[l - 1]) : -1;
		ll rh = (r < e - 1) ?  min(height, h[r + 1]) : -1;
		if (lh >= rh) {
			height = lh;
			l--;
		}
		else {
			height = rh;
			r++;
		}
		size = max(size, ++width * height);
	}
	return size;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	while (N != 0) {
		
		for (int i = 0; i < N; i++) {
			cin >> h[i];
		}
		cout << getSize(0, N) << '\n';
		cin >> N;
	}

	return 0;
}