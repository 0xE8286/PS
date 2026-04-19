#include <iostream>
using namespace std;

int N, V;
int arr[101];
int ans;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
	
		cin >> arr[i];

	}
	cin >> V;

	for (int i = 0; i < N; i++) {

		if (arr[i] == V) {
			ans++;
		}

	}
	cout << ans;
}
