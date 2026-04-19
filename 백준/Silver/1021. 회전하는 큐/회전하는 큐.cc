#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* prev = NULL;
	Node* next = NULL;
};

class queue {
public:
	Node* head = NULL;
	Node* rear = NULL;
	int size = 0;

public:
	int empty() {
		if (head == NULL && rear == NULL)
			return 1;
		return 0;
	}

	void connect() {
		rear->next = head;
		head->prev = rear;
	}

	void disconnect() {
		rear->next = NULL;
		head->prev = NULL;
	}

	void push_front(int x) {
		Node* n = new Node;
		n->data = x;
		n->prev = NULL;
		size++;

		if (empty()) {
			head = n;
			rear = n;
		}
		else {
			head->prev = n;
			n->next = head;
			head = n;
		}
	}
	void push_back(int x) {
		Node* n = new Node;
		n->data = x;
		n->next = NULL;
		size++;

		if (empty()) {
			head = n;
			rear = n;
		}
		else {
			rear->next = n;
			n->prev = rear;
			rear = n;
		}
	}

	int pop_front() {
		if (empty()) {
			return -1;
		}
		Node* tmp = head;
		int data = tmp->data;

		head = head->next;

		if (head != NULL)
			head->prev = NULL;
		if (tmp == rear)
			rear = NULL;

		size--;
		delete tmp;
		return data;
	}

	int pop_back() {
		if (empty()){
			return -1;
		}
		Node* tmp = rear;
		int data = tmp->data;

		rear = rear->prev;
		if (rear != NULL)
			rear->next = NULL;
		if (tmp == head)
			head = NULL;

		size--;
		delete tmp;
		return data;
	}

	int front() {
		if (empty())
			return -1;
		return head->data;
	}
	int back() {
		if (empty())
			return -1;
		return rear->data;
	}

	int get_size() {
		return size;
	}

	void move_forward() {
		rear = head;
		head = head->next;
	}
	void move_backward() {
		head = rear;
		rear = rear->prev;
	}
	int find(int x) {
		Node* i = head;
		int cnt = 0;
		while (i->data != x) {
			i = i->next;
			cnt++;
		}
		if (cnt > get_size() / 2) {
			return 0;
		}
		else {
			return 1;
		}
	}
};

int abs(int x) {
	if (x < 0)
		return -1 * x;
	return x;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	queue deque;

	int N, M, K;
	int cnt = 0;

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		deque.push_back(i);
	}

	deque.connect();

	for (int i = 0; i < M; i++) {
		cin >> K;

		while (deque.front() != K) {
			if (deque.find(K)) {
				deque.move_forward();
			}
			else {
				deque.move_backward();
			}
			cnt++;
		}
		deque.disconnect();
		deque.pop_front();
		if (!deque.empty()) {
			deque.connect();
		}
	}

	cout << cnt;

	return 0;
}