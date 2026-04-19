#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> group;
unordered_map<string, string> member;

int N, Q, member_cnt;
string group_name, member_name;

int query;
string key;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> group_name >> member_cnt;
		while (member_cnt--) {
			cin >> member_name;
			member[member_name] = group_name;
			group[group_name].push_back(member_name);
		}
		sort(group[group_name].begin(), group[group_name].end());
	}
	for (int i = 0; i < Q; i++) {
		cin >> key >> query;
		if (query == 0) {
			for (string mem : group[key]) {
				cout << mem << '\n';
			}
		}
		else {
			cout << member[key] << '\n';
		}
	}
	return 0;
}