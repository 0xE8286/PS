#include <iostream>
using namespace std;

int main(void) {
	
	char st[101][101];
	
	int n = 0;
	int cnt = 0;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> st[i];

		char front = st[i][0]; //첫 글자
		int chk[500] = { 0, };

		int j = 0;
		while (st[i][j] != '\0') {
			int curr = st[i][j];
			if (curr != front && chk[curr] > 0) {
				cnt++;
				break; //그룹 단어 아님
			}
			chk[curr]++;
			front = curr;
			j++;
		}
	}
	cout << n-cnt << endl;

	return 0;
}