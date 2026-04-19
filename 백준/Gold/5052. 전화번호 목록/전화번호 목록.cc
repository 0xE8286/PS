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
	return c - '0';
}

struct trie_node {
	bool isComp;
	bool hasChild;
	trie_node* num[10];
};

trie_node* getNode() {
	trie_node* t = (trie_node*)malloc(sizeof(trie_node));
	if (t) {
		t->isComp = 0;
		t->hasChild = 0;
		for (int i = 0; i < 10; i++) {
			t->num[i] = NULL;
		}
	}
	return t;
}

struct trie {
	trie_node* root;

	trie() {
		root = getNode();
	}

	~trie() {
		for (int i = 0; i < 10; i++) {
			if (root->num[i]) {
				delete root->num[i];
			}
		}
	}

	int insert(const char* key) {
		int result = 1;
		int length = strlength(key);

		trie_node* curr = root;

		for (int i = 0; i < length; i++) {

			int index = char2index(key[i]);

			if (!curr->num[index]) {
				curr->num[index] = getNode();
				curr->hasChild = 1;
			}

			curr = curr->num[index];

			if (curr->isComp) {
				result = 0;
			}
		}
		curr->isComp = 1;

		if (curr->hasChild) {
			result = 0;
		}
		return result;
	}
};

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;
	char num[11];

	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		trie* tree = new trie;

		cin >> N;
		bool wrong = false;

		for (int i = 0; i < N; i++) {
			cin >> num;
			int result = tree->insert(num);
			if (result == 0) {
				wrong = true;
			}
		}
		if (wrong) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
		delete tree;
	}
	return 0;
}