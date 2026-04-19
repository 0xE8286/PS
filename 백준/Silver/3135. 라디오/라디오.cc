#include<iostream>
using namespace std;

int ch[7];
int v[1001];
int q[10001];
int f = -1;
int r = -1;

int main(){
	int a, b, n;
	cin >> a >> b;
	cin >> n;

	ch[0] = 1;
	ch[1] = -1;

	for (int i = 2; i < 2 + n; i++)
		cin >> ch[i];

	q[++r] = a;

	while (f != r){
		int c = q[++f];
		if (c == b) {
			cout << v[b];
			break;
		}
		for (int i = 0; i < 2 + n; i++){
			int next = 0;

			if (i == 0 || i == 1)
				next = c + ch[i];
			else
				next = ch[i];

			if (v[next] == 0) {
				q[++r] = next;
				v[next] = v[c] + 1;
			}	
		}
	}
}