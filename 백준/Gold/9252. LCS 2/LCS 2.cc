#include <iostream>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[1002][1002];
string lcs;

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	int i = str1.size();
	int j = str2.size();
	int cnt = dp[str1.size()][str2.size()];

	while (dp[i][j] != 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
			continue;
		}
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
			continue;
		}
		lcs.push_back(str1[i - 1]);
		i--;
		j--;		
	}
	reverse(lcs.begin(), lcs.end());

	cout << cnt << '\n';
	cout << lcs << '\n';

	return 0;
}