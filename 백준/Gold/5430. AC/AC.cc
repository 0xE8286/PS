#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class Deque {
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;

public:
	int is_empty() {
		if (head == NULL && tail == NULL)
			return 1;
		return 0;
	}
	int get_size() {
		return size;
	}
	void push_front(int x) {
		Node* n = new Node;
		n->data = x;
		n->prev = NULL;
		
		if (is_empty()){
			n->next = NULL;
			tail = n;
			head = n;
		}
		else {
			n->next = head;
			head->prev = n;
			head = n;
		}
		size++;
	} 
	void push_back(int x) {
		Node* n = new Node;
		n->data = x;
		n->next = NULL;

		if (is_empty()) {
			n->prev = NULL;
			head = n;
			tail = n;
		}
		else {
			n->prev = tail;
			tail->next = n;
			tail = n;
		}
		size++;
	}
	int pop_front() {
		if (is_empty()) 
			return -1;

		Node* tmp = head;
		if (head->next != NULL) {
			head = head->next;
			head->prev = NULL;
		}
		else {
			head = NULL;
			tail = NULL;
		}
		int data = tmp->data;
		delete tmp;
		size--;
		return data;
	}
	int pop_back() {
		if (is_empty())
			return -1;

		Node* tmp = tail;
		if (tail->prev != NULL) {
			tail = tail->prev;
			tail->next = NULL;
		}
		else {
			head = NULL;
			tail = NULL;
		}
		int data = tmp->data;
		delete tmp;
		size--;
		return data;
	}
};

int _atoi(char* a) {
	int i = 0;
	int num = 0;
	while (a[i] != '\0') {
		if (a[i] != '\n' && a[i] != '[' && a[i] != ']')
			num = (num * 10) + (a[i]-'0');
		i++;
	}
	return num;
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, n;
	char func[100001];
	char num[7];

	cin >> T;
	
	for (int tc = 0; tc < T; tc++) {
		Deque deq;

		cin >> func >> n;

		if (n != 0){
			for (int i = 0; i < n-1; i++) {
				cin.getline(num, 7, ',');
				deq.push_back(_atoi(num));
			}
			cin.getline(num, 7, ']');
			deq.push_back(_atoi(num));
		}
		else {
			cin >> num;
		}

		int way = 1;
		int error = 0;
		int i = 0;

		while (func[i] != '\0') {
			if (func[i] == 'R') {
				way = way * -1;
			}
			else {
				int result = 0;
				if (way == 1){
					result = deq.pop_front();
				}
				else {
					result = deq.pop_back();
				}
				if (result == -1) {
					error = 1;
					break;
				}
			}
			i++;
		}
		if (error == 1){
			cout << "error\n";
		}
		else {
			int size = deq.get_size();
			if (way == 1) {
				cout << "[";
				for (int i = 0; i < size; i++) {
					if (i == 0)
						cout << deq.pop_front();
					else
						cout << ',' << deq.pop_front();
				}
				cout << "]\n";
			}
			else {
				cout << "[";
				for (int i = 0; i < size; i++) {
					if (i == 0)
						cout << deq.pop_back();
					else
						cout << ',' << deq.pop_back();
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}