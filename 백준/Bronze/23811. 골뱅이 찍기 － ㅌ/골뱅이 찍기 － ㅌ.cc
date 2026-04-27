#include <iostream>
using namespace std;

int N; 
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int M = N * 5;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << '@';
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << '@';
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << '@';
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << '@';
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << '@';
		}
		cout << '\n';
	}
	return 0;
}