#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define BUCKET_SIZE 500009

struct Node {
	unsigned long long key;
	bool heard;
	bool seen;
	Node* next;

}pool[BUCKET_SIZE];
int pool_size = 0;

Node* alloc(unsigned long long key) {
	pool[pool_size].key = key;
	pool[pool_size].heard = true;
	return &pool[pool_size++];
}

struct List {
	Node* head;
	Node* tail;

	void init() {
		head = 0;
		tail = 0;
	}

	void insert(unsigned long long key) {
		Node* n = alloc(key);

		if (!tail) {
			head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
	}
};

struct HashMap {
	List table[BUCKET_SIZE];

	unsigned long long hash(string str) {
		unsigned long long value = 5381;
		int c;
		for (int i = 0; str[i]; i++) {
			value += ((value << 5) + str[i] - 'a' + 1);
		}
		return value;
	}

	void put(string str, int value) {
		unsigned long long key = hash(str);
		table[key % BUCKET_SIZE].insert(key);
	}

	Node* get(string str) {
		unsigned long long key = hash(str);
		Node* curr = table[key % BUCKET_SIZE].head;
		while (curr != nullptr) {
			if (key == curr->key) {
				break;
			}
			curr = curr->next;
		}
		return curr;
	}
};

HashMap map;
int N;
int M;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	
	string temp;
	vector<string> v;
	vector<string> ans;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
		map.put(temp, 1);
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		v.push_back(temp);
		Node* person = map.get(temp);
		if (person != nullptr)
			person->seen = true;
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		Node* person = map.get(v[i]);
		if (person != nullptr && person->heard && person->seen) {
			ans.push_back(v[i]);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}