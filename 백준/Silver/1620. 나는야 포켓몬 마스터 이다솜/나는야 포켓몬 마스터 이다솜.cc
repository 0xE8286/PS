#include <iostream>
using namespace std;

#define BUCKET_SIZE 100007

struct Node {
	unsigned long long key;
	int value; 
	Node* next;
}pool[BUCKET_SIZE];
int pool_size = 0;

Node* alloc(unsigned long long key, int value) {
	pool[pool_size].key = key;
	pool[pool_size].value = value;
	return &pool[pool_size++];
}

struct List {
	Node* head;
	Node* tail;

	void init() {
		head = 0;
		tail = 0;
	}

	void insert(unsigned long long key, int value) {
		Node* n = alloc(key, value);

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
	
	unsigned long long hash(const char* str) {
		unsigned long long value = 5381;
		int c;
		while (c = *str++) {
			value += ((value << 5) + c - 'a' + 1);
		}
		return value;
	}

	void put(const char* str, int value) {
		unsigned long long key = hash(str);
		table[key % BUCKET_SIZE].insert(key, value);
	}

	Node* get(const char* str) {
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

void strcopy(char* dest, const char* src) {
	int i;
	for (i = 0; src[i]; i++) {
		dest[i] = src[i];
	}
	dest[i] = src[i];
}

int _atoi(const char* str) {
	int c;
	int value = 0;
	while (c = *str++) {
		value = value * 10 + (c - '0');
	}
	return value;
}

HashMap map;
char vec[100007][21];
int N;
int M;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	char temp[21];

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		strcopy(vec[i], temp);
		map.put(temp, i);
	}

	for (int i = 1; i <= M; i++) {
		cin >> temp;
		Node* n = map.get(temp);
		if (!n) {
			int index = _atoi(temp);
			cout << vec[index];
		}
		else {
			cout << n->value;
		}
		cout << '\n';
	}

	return 0;
}