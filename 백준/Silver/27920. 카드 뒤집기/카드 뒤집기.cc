#include <iostream>

using namespace std;

int N;
int card[200001];
int order[200001];

int main() {
	cin >> N;  

	int i = 0;
	int k = N - 1;
	int c = 0;
	bool flag = true;
	
	while (k > 0) {
		card[i] = k;
		order[c] = i + 1;
		
		if (!flag) i -= k;
		else i += k;
		
		k--; c++;
		flag = !flag;
	}
	order[c] = i + 1;
	card[i] = N;

	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		cout << card[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << order[i] << ' ';
	}

	return 0;
}