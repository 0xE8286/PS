#include <iostream>
#include <queue>
using namespace std;

int N;
int card_num;
int merge_cnt;
priority_queue<int, vector<int>, greater<int>> cards;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card_num;
		cards.push(card_num);
	}
	while (cards.size() > 1) {
		int c1 = cards.top(); cards.pop();
		int c2 = cards.top(); cards.pop();
		merge_cnt += c1 + c2;
		cards.push(c1 + c2);
	}
	cout << merge_cnt;
	return 0;
}