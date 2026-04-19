#include <iostream>
#include <unordered_map>

using namespace std;

int T, N;
string a, b;
int p[200002];

int find(int x) {
	if (p[x] < 0) {
		return x;
	}
	p[x] = find(p[x]);
	return p[x];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	p[a] += p[b];
	p[b] = a;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		
		unordered_map<string, int> table;
		int t_index = 0;
		
		for (int i = 0; i < N; i++) {
			
			cin >> a >> b;
			
			if (table.find(a) == table.end()) {
				p[t_index] = -1;
				table[a] = t_index++;
				
			}
			if (table.find(b) == table.end()) {
				p[t_index] = -1;
				table[b] = t_index++;
			}
			
			merge(table[a], table[b]);
			cout << abs(p[find(table[a])]) << '\n';
		}
	}

	return 0;
}