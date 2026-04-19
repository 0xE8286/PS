#include <iostream>
using namespace std;

int main(void) {
	
	char st[103];
	int chk[131] = { 0, };
	int sum = 0;

	cin >> st;

	int i = 0;
	

	while (st[i] != '\0') {
		int plus = 1;
		if (st[i] == 'c') {
			if (st[i + 1] == '='){
				chk[123]++; 
				plus = 2;
			}
			else if (st[i + 1] == '-'){
				chk[124]++;
				plus = 2;
			}
			else
				chk['c' - 0]++;
		}
		else if (st[i] == 'd') {
			if (st[i + 1] == 'z' && st[i + 2] == '=') {
				chk[125]++;
				plus = 3;
			}
			else if (st[i + 1] == '-') {
				chk[126]++;
				plus = 2;
			}
			else
				chk['d' - 0]++;
		}
		else if (st[i] == 'l') {
			if (st[i + 1] == 'j') {
				chk[127]++;
				plus = 2;
			}
			else
				chk['l' - 0]++;
		}
		else if (st[i] == 'n') {
			if (st[i + 1] == 'j') {
				chk[128]++;
				plus = 2;
			}
			else
				chk['n' - 0]++;
		}
		else if (st[i] == 's') {
			if (st[i + 1] == '=') {
				chk[129]++;
				plus = 2;
			}
			else
				chk['s' - 0]++;
		}
		else if (st[i] == 'z') {
			if (st[i + 1] == '=') {
				chk[130]++;
				plus = 2;
			}
			else
				chk['z' - 0]++;
		}
		else {
			chk[st[i] - 0]++;	
		}
		i += plus;
	}

	for (int j = 97; j <= 130; j++) {
			sum += chk[j];
	}

	cout << sum << endl;
	
	return 0;
}