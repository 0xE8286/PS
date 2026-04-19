#include <iostream>
using namespace std;

int q[100000][2] = { 0, };
int rear = 0;

void swap(int *a, int *b){
	int *tmp = 0;
	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

int abs(int v){
	if (v < 0) return v * -1;
	else return v;
}

void push(int v){
	if (v < 0) {
		rear++;
		q[rear][0] = abs(v);
		q[rear][1] = -1;
	}
	else {
		q[++rear][0] = v;
		q[rear][1] = 0;
	}
		
	for (int i = rear; i >= 1; i /= 2){
		if (q[i][0] < q[i / 2][0]){
			swap(q[i][0], q[i / 2][0]);
			swap(q[i][1], q[i / 2][1]);
		}
		else if (q[i][0] == q[i / 2][0] && q[i][1] < q[i / 2][1]){
			swap(q[i][0], q[i / 2][0]);
			swap(q[i][1], q[i / 2][1]);
		}
		else
			break;
	}
}
void pop(){
	
	q[1][0] = q[rear][0];
	q[1][1] = q[rear][1];
	rear--;

	int cur = 1;
	int child = 0;

	while (cur * 2 <= rear){ //자식이 없을때까지
		if (q[cur * 2 + 1] == 0) {//오른쪽 자식이 없을 때
			child = cur * 2;
		}
		else if (q[cur * 2][0] < q[cur * 2 + 1][0]){//자식 중 왼쪽 절대값이 작을 때
			child = cur * 2;
		}
		else if (q[cur * 2][0] > q[cur * 2 + 1][0]){//자식 중 오른쪽 절대값이 작을 때
			child = cur * 2 + 1;
		}
		else { // 절대값이 같을 때
			if (q[cur * 2][1] < q[cur * 2 + 1][1]) //부호가 작은쪽이 child
				child = cur * 2;
			else 
				child = cur * 2 + 1;
		}

		if (q[cur][0] < q[child][0]) //현위치가 자식보다 절대값이 작을ㄸㅐ
			break;

		else if (q[cur][0] == q[child][0] && q[cur][1] <= q[child][1]) //현위치랑 자식이 절대값이 동일하지만 부호가 같거나 작을때
			break;

		else {
			swap(q[cur][0], q[child][0]);
			swap(q[cur][1], q[child][1]);
			cur = child;
		}
	}
}
bool isEmpty(){
	if (rear == 0)
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
			if (q[1][1] < 0)
				printf("%d\n", q[1][0] * -1);
			else
				printf("%d\n", q[1][0]);
			pop();
		}

		else {
			push(c);
		}
	}
}