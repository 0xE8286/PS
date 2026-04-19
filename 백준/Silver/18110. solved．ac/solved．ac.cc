#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int num;
vector<int> grades;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	if (N == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> num;
		grades.push_back(num);
	}

	sort(grades.begin(), grades.end());

	int cut = round(N * 0.15); 
	double sum = 0;

	for (int i = cut; i < N - cut; i++) {
		sum += grades[i];
	}

	cout << round(sum / (N - (cut * 2)));

	return 0;
}