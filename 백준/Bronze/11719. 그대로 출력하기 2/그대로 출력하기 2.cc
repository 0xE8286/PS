#include <iostream>
#include <string>

using namespace std;

char a;

int main() {

	while (true) {
		a = getchar();
		if (a == EOF)
			break;
		putchar(a);
	}
	return 0;
}