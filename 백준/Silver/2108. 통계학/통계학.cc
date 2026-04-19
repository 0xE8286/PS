#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int average(vector<int> param) {
	int sum = 0;
	int size = param.size();
	for (int i = 0; i < size; i++) {
		sum += param[i];
	}
	double ave = (float)sum / size;
	return round(ave);
}
int second_mode(vector<int> param) {
	int count[8001] = { 0, };
	for (int i = 0; i < param.size(); i++) {
		count[4000 + param[i]]++;
	}
	int mode_cnt = 0;
	for (int i = 0; i < 8001; i++) {
		if (count[i] > mode_cnt) {
			mode_cnt = count[i];
		}
	}
	vector<int> modes;
	for (int i = 0; i < 8001; i++) {
		if (count[i] == mode_cnt) {
			modes.push_back(i - 4000);
		}
	}
	if (modes.size() == 1) {
		return modes[0];
	}
	else {
		sort(modes.begin(), modes.end());
		return modes[1];
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	ios::sync_with_stdio(false);

	vector<int> vec;
	int N;
	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	
	cout << average(vec) << "\n";
	cout << vec[(vec.size() - 1) / 2] << "\n";
	cout << second_mode(vec) << "\n";
	cout << vec[vec.size() - 1] - vec[0] << "\n";

	return 0;
}