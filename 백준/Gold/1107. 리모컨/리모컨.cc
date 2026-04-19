#include <iostream>

using namespace std;

int target;
int wrong_cnt;

int wrong[10];


bool is_able(int ch) {
	
	int able = true;

	if (ch == 0 && wrong[0]== -1) {
		return false;
	}
	
	while (ch != 0) {
		if (wrong[ch % 10] == -1) {
			able = false;
			break;
		}
		ch /= 10;
	}
	return able;
}

int get_digit(int ch) {
	if (ch == 0)
		return 1;

	int i = 0;
	while (ch != 0) {
		ch /= 10;
		i++;
	}
	return i;
}

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int abs(int a) {
	if (a < 0) return a * -1;
	else return a;
}

int main() {

	cin >> target;
	cin >> wrong_cnt;

	for (int i = 0; i < wrong_cnt; i++) {
		int number;
		cin >> number;

		wrong[number] = -1;
	}

	int min_cnt = min(abs(target - 100), abs(100 - target));
	int min_ch = 100;

	for (int i = 0; i <= 1000000; i++) {
		if (is_able(i)) {
			int cnt = min(abs(target - i), abs(i - target)) + get_digit(i);;
			if (cnt < min_cnt) {
				min_cnt = cnt;
				min_ch = i;
			}
		}
	}
	cout << min_cnt;

	return 0;
}