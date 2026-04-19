#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt, curr;
vector<pair<int, int>> list;

bool comp(const pair<int, int> &a, const pair<int, int>& b) {
	if (a.second < b.second) return true;
	if (a.second == b.second && a.first < b.first) return true;
	return false;
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	pair<int, int> meeting;
	
	for (int i = 0; i < N; i++) {
		cin >> meeting.first >> meeting.second;
		list.push_back(meeting);
	}
	
	sort(list.begin(), list.end(), comp);
	
	curr = list[0].second;
	cnt = 1;

	for (int i = 1; i < list.size(); i++) {
		if (list[i].first >= curr && list[i].second >= curr) {
			curr = list[i].second;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}