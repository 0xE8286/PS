#include <iostream>

using namespace std;

string org;
string conseq;

int ans;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> org >> conseq;

	for (int i = 0; i < conseq.size(); i++) {

		int max_same_cnt = 0;

		for (int j = 0; j < org.size(); j++) {
			
			int same_cnt = 0;
			int ii = i;
			int jj = j;
			
			while (conseq[ii] == org[jj]) {
				same_cnt++;
				if (++ii == conseq.size() || ++jj == org.size()) {
					break;
				} 
			}

			max_same_cnt = max(same_cnt, max_same_cnt);
		}

		for (int j = 1; j < max_same_cnt; j++) {
			i++;
		}
		ans++;
	}

	cout << ans;

	return 0;
}