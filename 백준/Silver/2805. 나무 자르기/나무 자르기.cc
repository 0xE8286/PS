#include <iostream>
using namespace std;

int N = 0;
int M = 0;
int height[1000000];

int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> height[i];

	int start = 0;
	int end = 1000000000;

	while (start + 1 < end) {
		//cout << start << " " << end << endl;
		int div = (start + end) / 2;
		long long int sum = 0;
		for (int i = 0; i < N; i++) {
			if (height[i] > div)
				sum += height[i] - div;
		}
		if (sum >= M)
			start = div;
		else
			end = div;
	}
	cout << start;
}