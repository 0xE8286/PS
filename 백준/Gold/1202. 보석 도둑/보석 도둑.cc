#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N, K;
int bag, m, v;
long long int sum;

typedef pair<int, int> gem;
multiset<int> bags;
priority_queue<gem> gems;

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		gems.push(gem(v, m));
	}
	for (int i = 0; i < K; i++) {
		cin >> bag;
		bags.insert(bag);
	}
	while (!bags.empty() && !gems.empty()) {
		gem most_expensive = gems.top();
		gems.pop();
		auto perfect_bag = bags.lower_bound(most_expensive.second);
		if (perfect_bag == bags.end()) continue;
		sum += most_expensive.first;
		bags.erase(perfect_bag);
	}
	cout << sum;

	return 0;
}