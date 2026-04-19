#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string alphabets;
string candidates;
bool visit[15];

int c_cnt;
int v_cnt;

void count(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v_cnt++;
	else c_cnt++;
}
void discount(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v_cnt--;
	else c_cnt--;
}

void make_pw(int start, int depth) {
	if (depth == N && c_cnt >= 2 && v_cnt >= 1) {
		cout << candidates << '\n';
		return;
	}
	for (int i = start; i < M; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			count(alphabets[i]);
			candidates.push_back(alphabets[i]);
			make_pw(i, depth + 1);
			candidates.pop_back();
			discount(alphabets[i]);
			visit[i] = false;
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	char c;

	for (int i = 0; i < M; i++) {
		cin >> c;
		alphabets.push_back(c);
	}
	sort(alphabets.begin(), alphabets.end());
	make_pw(0, 0);

	return 0;
}