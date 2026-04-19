#include <iostream>
using namespace std;

int N;
long long h[100000];

long long getSize(long long s, long long e) {
	if (s == e) return 0;
	if (s + 1 == e) return h[s];

	long long mid = (s + e) / 2;
	long long size = max(getSize(s, mid), getSize(mid, e));
	
	long long l = mid;
	long long r = mid;

	long long width = 1;
	long long height = h[mid];

	while ((r - l + 1) < e - s) {
		long long lh = (l > s) ? min(height, h[l - 1]) : -1;
		long long rh = (r < e - 1) ?  min(height, h[r + 1]) : -1;
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
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	cout << getSize(0, N) << '\n';
	

	return 0;
}