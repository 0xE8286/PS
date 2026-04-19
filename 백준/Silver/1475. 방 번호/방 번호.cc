#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int max_cnt;
string number;

int main() {
	cin >> number;

	for (int i = 0; i < number.size(); i++) {
		int num = number[i] - '0';
		if (num == 6) {
			num = arr[6] <= arr[9] ? 6 : 9;
		}
		else if (num == 9) {
			num = arr[9] <= arr[6] ? 9 : 6;
		}
		arr[num]++;
		max_cnt = max(max_cnt, arr[num]);
	}

	cout << max_cnt;

	return 0;
}