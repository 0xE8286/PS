#include <iostream>
#include <map>

#define MOD 900528
using namespace std;

string memo;
string pw;
map<char, int> idx;

int main() {

	cin >> memo >> pw;
	
	for (int i = 0; i < memo.size(); i++) {
		idx[memo[i]] = i + 1;
	}

	long long cnt = 0;
	
	for (int i = 0; i < pw.size()-1; i++) {
		cnt += idx[pw[i]];
		cnt %= MOD;
		cnt *= memo.size();
		cnt %= MOD;
	}
	cnt += idx[pw.back()];
	cout << cnt % MOD;

	return 0;

}