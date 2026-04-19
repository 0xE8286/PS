#include <iostream>
using namespace std;

int q[100000] = { 0, };
int front = 0;
int rear = 0;

void swap(int *a, int *b){
	int *tmp=0;
	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

void push(int v){
	q[++rear] = v;
	for (int i = rear; i >= 1; i/=2){
		if (q[i] < q[i/2]){
			swap(q[i] , q[i/2]);
		}
	}
}
void pop(){
	q[1] = q[rear--];
	int cur = 1;
	int child = 0;

	while (cur * 2 <= rear){ //자식이 없을때까지
		if (rear < cur * 2 + 1 || q[cur * 2] < q[cur * 2 + 1])
			child = cur * 2;
		else child = cur * 2 + 1;
		if (q[cur] < q[child]) break;
		else {
			swap(q[cur], q[child]);
			cur = child;
		} 
	}
}
bool isEmpty(){
	if (front == rear)
		return true;
	else
		return false;
}
int main(){

	int T, c;
	scanf("%d", &T);
	//cin >> T;

	for (int i = 0; i < T; i++){
		//cin >> c;
		scanf("%d", &c);

		if (c == 0 && isEmpty() == true){
			//cout << 0 << endl;
			printf("0\n");
		}

		else if (c == 0){
			//cout << q[1] << endl;
			printf("%d\n", q[1]);
			pop();
		}

		else {
			push(c);
		}
	}
}