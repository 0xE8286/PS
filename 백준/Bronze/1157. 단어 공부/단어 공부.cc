#include <iostream>
using namespace std;

int cnt[58];

int main(void) {

	char st[1000000];

	cin >> st;

	int i = 0;
	int max = 0;
	int max_i = 0;
	int stack = 0;

	while (st[i] != '\0') {
		cnt[st[i] - 65]++;
		i++;
	}

	for (int j = 0; j < 26; j++) {
		int temp = cnt[j] + cnt[j + 32];
		if (temp > max) {
			max = temp;
			max_i = j;
			stack = 0;
		}
		else if (temp == max) {
			stack++;
		}
	}
	if (stack > 0)
		printf("?");
	else
		printf("%c\n", max_i+65);

	return 0;
}