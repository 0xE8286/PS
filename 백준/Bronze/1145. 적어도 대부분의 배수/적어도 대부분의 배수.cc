#include <iostream>
using namespace std;

int arr[5], ans = 1;
int main() {
	for (int i = 0; i < 5; i++) cin >> arr[i];

	while (true) {
		int count = 0;
		for (int i = 0; i < 5; i++)
			if (ans % arr[i] == 0) count++;
		if (count >= 3) {
			cout << ans;
			break;
		}
		ans++;
	}

	return 0;
}