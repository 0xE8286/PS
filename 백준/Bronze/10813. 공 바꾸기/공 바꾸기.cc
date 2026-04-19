#include <iostream>
using namespace std;

int N, M;
int arr[101];

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}

	int a, b, temp;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	for(int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}