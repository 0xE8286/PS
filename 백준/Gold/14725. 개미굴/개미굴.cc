#include <iostream>
#include <map>
#include <string>

#define MAX_K 16
#define MAX_T 16

using namespace std;

int N, K, T;
string food[MAX_K];

struct Trie {

	map<string, Trie*> trie_map;

	void insert(string str[15], int index) {
		if (index == K) {
			return;
		}
		if (trie_map.find(str[index]) == trie_map.end()) {
			trie_map.insert({ str[index], new Trie() });
		}
		trie_map[str[index]]->insert(str, index + 1);
	}

	void search(int depth) {
		map<string, Trie*>::iterator iter;
		for (iter = trie_map.begin(); iter != trie_map.end(); ++iter) {
			for (int i = 0; i < depth; ++i) {
				cout << "--";
			}
			cout << (*iter).first << "\n";
			(*iter).second->search(depth + 1);
		}
	}
}trie;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> food[j];
		}
		trie.insert(food, 0);
	}
	
	trie.search(0);

	return 0;
}