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
};


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	queue deque;

	int N;
	char cmd[11];
	int data;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd[1] == 'u') {
			cin >> data;
			if (cmd[5] == 'b') {
				deque.push_back(data);
			}
			else if (cmd[5] == 'f') {
				deque.push_front(data);
			}
		}
		if (cmd[1] == 'o') {
			if (cmd[4] == 'b') {
				cout << deque.pop_back() << '\n';
			}
			else if (cmd[4] == 'f') {
				cout << deque.pop_front() << '\n';
			}
		}
		if (cmd[1] == 'i') {
			cout << deque.get_size() << '\n';
		}
		if (cmd[1] == 'm') {
			cout << deque.empty() << '\n';
		}
		if (cmd[1] == 'r') {
			cout << deque.front() << '\n';
		}
		if (cmd[1] == 'a') {
			cout << deque.back() << '\n';
		}
	}

	return 0;
}