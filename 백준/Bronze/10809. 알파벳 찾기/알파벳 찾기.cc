#include <iostream>
using namespace std;

int cnt[26] = { 0, };

int main(void) {
	char a[101];
	cin >> a;

	for (int i = 0; i < 26; i++) {
		cnt[i] = -1;
	}

	int i = 0;
	while (a[i] != '\0') {
		if (cnt[a[i] - 97] == -1)
			cnt[a[i] - 97] = i;
		i++;
	}

	for (int j = 0; j < 26; j++) {
		cout << cnt[j] << " ";
	}
	return 0;
}