#include <iostream>

using namespace std;

char expr[51];
char buff[51];
int ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> expr;

	int i = 0;
	int buff_index = 0;
	bool isAdd = true;

	while (expr[i] != '\0') {
		if (expr[i] == '+') {
			buff[buff_index] = '\0';
			if (isAdd) {
				ans += atoi(buff);
			}
			else {
				ans -= atoi(buff);
			}
			buff_index = 0;
		}
		else if (expr[i] == '-') {
			buff[buff_index] = '\0';
			if (isAdd) {
				ans += atoi(buff);
				isAdd = false;
			}
			else {
				ans -= atoi(buff);
			}
			buff_index = 0;
		}
		else {
			buff[buff_index++] = expr[i];
		}
		i++;
	}

	buff[buff_index] = '\0';

	if (isAdd) {
		ans += atoi(buff);
	}
	else {
		ans -= atoi(buff);
	}

	cout << ans;
	return 0;
}