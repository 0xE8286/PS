#include <iostream>

using namespace std;

int N, M;
int arr[101];
int s, e, num;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> s >> e >> num;
		for (int j = s; j <= e; j++) {
			arr[j] = num;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}