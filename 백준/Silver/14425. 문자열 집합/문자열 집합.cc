#include <iostream>
using namespace std;

int strlength(const char* str) {
	int c = 0;
	while (*str) {
		c++;
		str++;
	}
	return c;
}

int char2index(char c) {
	return c - 'a';
}

struct trie_node {
	int cnt;
	trie_node* spell[26];
};

trie_node* getNode() {
	trie_node* t = (trie_node*)malloc(sizeof(trie_node));
	if (t) {
		t->cnt = 0;
		for (int i = 0; i < 26; i++) {
			t->spell[i] = NULL;
		}
	}
	return t;
}

struct trie {
	trie_node* root;

	void init() {
		root = getNode();
	}

	void insert(const char* key) {
		int length = strlength(key);
		trie_node* curr = root;
		
		for (int i = 0; i < length; i++) {
			int index = char2index(key[i]);
			if (!curr->spell[index]) {
				curr->spell[index] = getNode();
			}
			curr = curr->spell[index];
		}
		curr->cnt++;
	}

	int search(const char* key) {
		int length = strlength(key);
		trie_node* curr = root;

		for (int i = 0; i < length; i++) {
			int index = char2index(key[i]);
			if (!curr->spell[index]) {
				return 0;
			}
			curr = curr->spell[index];
		}
		if (!curr) {
			return 0;
		}
		else {
			return curr->cnt;
		}
	}
}my_trie;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	char word[501];
	int ans = 0;

	my_trie.init();

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> word;
		my_trie.insert(word);
	}
	for (int i = 0; i < M; i++) {
		cin >> word;
		int result = my_trie.search(word);
		if (result) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}