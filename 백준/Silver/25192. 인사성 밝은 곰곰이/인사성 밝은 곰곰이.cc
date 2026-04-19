#include<iostream>
#include<unordered_map>
using namespace std;

int N;
int sum;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string log;
	unordered_map<string, bool> hi_list;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> log;
		if (log == "ENTER") {
			sum += hi_list.size();
			hi_list.erase(hi_list.begin(), hi_list.end());
		}
		else {
			hi_list[log] = true;
		}
	}
	sum += hi_list.size();
	cout << sum;

	return 0;
}