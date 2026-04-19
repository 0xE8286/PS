
#include <iostream>
#include <string>
using namespace std;

int A, B, C;
int main() {	
	cin >> A >> B >> C;
	
	string ab;
	ab.append(to_string(A));
	ab.append(to_string(B));

	cout << A + B - C << '\n';
	cout << atoi(ab.c_str()) - C;


	return 0;
}