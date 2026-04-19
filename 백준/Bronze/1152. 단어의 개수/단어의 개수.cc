#include <iostream>
using namespace std;

int main(void) {
	
	char st[1000001];
	int i = 0;
	int cnt = 0;

	cin.getline(st, 1000001);

	if (st[0] == ' ')
		i = 1;

	if (st[i] != ' ' && st[i] != '\0')
		cnt++;

	while (st[i] != '\0') {
		if (st[i] == ' ' && st[i + 1] != ' ' && st[i + 1] != '\0')
			cnt++;
		i++;
	}
	cout << cnt << endl;

	return 0;
}