#include <iostream>
using namespace std;

int N;
int n[100000];

int atoi(char *a){
	int value = 0;
	while (*a){
		if (*a >= '0' && *a <= '9'){
			value = (value * 10) + (*a) - '0';
		}
		a++;
	}
	return value;
}

int sum(char *t, char *c, int cnt){
	int sum = 0;
	
	for (int i = 0; i < cnt; i++){
		c[i] = t[cnt - i - 1];
	}
	sum = atoi(t) + atoi(c);

	//cout << atoi(t) <<" " << atoi(c) << endl;
	//cout << sum << endl;
	return sum;
}

void isTrue(int n){
	int org = n;
	int rev = 0;
		while (n){
			rev *= 10;
			rev += n % 10;
			n /= 10;
		}
		if (org == rev)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
}

int main(){
	cin >> N;

	for (int i = 1; i <= N; i++){
		
		char t[100000] = { 0, };
		char c[100000] = { 0, };

		cin >> t;

		int j = 0;
		int cnt = 0;
		
		while (t[j] != '\0'){
			cnt++;
			j++;
		}
		//cout << cnt <<endl;
		isTrue(sum(t, c, cnt));
	}
	return 0;
}