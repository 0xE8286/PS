#include <iostream>
using namespace std;

typedef pair<int, int> p;
p p1, p2, p3;

int crossproduct(p a, p b) {
	return (a.first * b.second) - (a.second * b.first);
}

p vec(p a, p b) {
	return { b.first - a.first, b.second - a.second };
}

int main() {

	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;

	p vec1 = vec(p1, p2);
	p vec2 = vec(p2, p3);

	int ccw = crossproduct(vec1, vec2);

	if (ccw < 0) cout << -1;
	else if (ccw == 0) cout << 0;
	else cout << 1;


	return 0;
}