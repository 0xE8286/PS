#include<iostream>
using namespace std;

int check[31]; 
int input;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int i = 1; i <= 28; i++) {
		cin >> input;
		check[input] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (check[i] == 0){
			cout << i << '\n';
		}
	}
	return 0;
}