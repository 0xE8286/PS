#include <iostream>
#include <set>
using namespace std;

int N;
int map[1025][1025];

int find(int size, int y, int x) {
	if (size == 1) {
		return map[y][x];
	}
	if (size == 2) {
		set<int> s;
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				s.insert(map[i][j]);
			}
		}
		return *(++s.begin());
	}
	int half = size / 2;
	set<int> s;
	s.insert(find(half, y, x));
	s.insert(find(half, y, x + half));
	s.insert(find(half, y + half, x));
	s.insert(find(half, y + half, x + half));
	return *(++s.begin());
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << find(N, 0, 0);

	return 0;
}