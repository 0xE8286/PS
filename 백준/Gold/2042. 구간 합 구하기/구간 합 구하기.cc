#include <iostream>
using namespace std;

int N, M, K;

long long input[1000001];
long long tree[4000001];

long long init(int v, int start, int end){
	if (start == end)
		return tree[v] = input[start];
	else {
		return tree[v] = init(v * 2, start, (start + end) / 2) + init(v * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(int node, int target, int start, int end, long long diff){
	if (!(start <= target && target <= end))
		return;	
	
	tree[node] += diff;
	
	if (start != end) {
		update(node * 2, target, start, (start + end) / 2, diff); //왼쪽으로 이동
		update(node * 2 + 1, target, (start + end) / 2 + 1, end, diff); //오른쪽으로 이동
	}
}

long long getSum(int node, int start, int end, int t_start, int t_end){
	if (t_start > end || t_end < start)
		return 0; // 범위 x
	if (t_start <= start && end <= t_end)
		return tree[node];
	return getSum(node * 2, start, (start + end) / 2, t_start, t_end) + getSum(node * 2 + 1, (start + end) / 2 + 1, end, t_start, t_end);
}

int main(){
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> input[i];

	init(1, 1, N);
	/*
	for (int i = 0; i < M + K; i++){
		int a;
		cin >> a;
		if (a == 1){
			int b;
			long long c;
			cin >> b >> c;
			//input[b] = c;
			update(1, b, 1, N, c - input[b]);
		}
		else{
			int b, c;
			cin >> b >> c;
			cout << getSum(1, 1, N, b, c) << endl;
		}
	}
	*/
	
	M += K;
	while (M--){
		int cmd;
		cin >> cmd;
		if (cmd == 1){
			int b;
			long long c;
			long long diff = 0;
			cin >> b >> c;
			diff = c - input[b];
			input[b] = c;
			update(1, b, 1, N, diff);
		}
		else if (cmd == 2){
			int b;
			int c;
			cin >> b >> c;
			cout << getSum(1, 1, N, b, c) << endl;
		}	
	}
}