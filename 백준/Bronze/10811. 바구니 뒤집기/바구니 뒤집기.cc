#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int N, M;
int stt, ed;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> stt >> ed;
		reverse(arr+stt, arr+ed+1);
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}