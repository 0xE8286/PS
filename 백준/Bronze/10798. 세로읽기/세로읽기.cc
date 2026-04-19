#include<iostream>
using namespace std;

char str[5][16];

int main() {
	
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j][i] != '\0') {
				cout << str[j][i];
			}
		}
	}
	return 0;
}