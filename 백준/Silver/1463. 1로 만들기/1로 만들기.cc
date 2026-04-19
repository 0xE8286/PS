#include <iostream>
using namespace std;

int data[1000000];


int makeOne(int n){
	if (n == 1)	return 0;
	if (data[n] != 0) return data[n];

	int sol_1 = 2147483647;
	int sol_2 = 2147483647;
	int sol_3 = 2147483647;

	sol_1 = makeOne(n - 1) + 1;
	if (n % 2 == 0)
		sol_2 = makeOne(n / 2) + 1;
	
	if (n % 3 == 0)
		sol_3 = makeOne(n / 3) + 1;
	
	if (sol_1 < sol_2){
		if (sol_1 < sol_3)
			data[n] = sol_1;
		else
			data[n] = sol_3;
	}
	else {
		if (sol_2 < sol_3)
			data[n] = sol_2;
		else
			data[n] = sol_3;
	}
	return data[n];
}

int main(){
	int N; 
	cin >> N;

	makeOne(N);
	cout << data[N];

	return 0;
}