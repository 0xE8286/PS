#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> hist;
priority_queue<pair<int, hist>, vector<pair<int, hist>>, greater<>> pq;

int X, C, K;
int T, S, N;
int seat[100001];
int result[100001];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> X >> C >> K;

	for (int i = 0; i < K; i++) {
		cin >> T >> S >> N;
		pq.push({ T, {S, N} });
	}
	
	while (!pq.empty()) {
		int seat_no = pq.top().second.first;
		int student_no = pq.top().second.second;
		pq.pop();
		
		if (seat[seat_no] != 0) {
			continue;
		}

		if (result[student_no] != 0) {
			seat[result[student_no]] = 0;
		}
		
		result[student_no] = seat_no;
		seat[seat_no] = student_no;		
	}
	
	for (int i = 1; i <= X; i++) {
		if (result[i] != 0) {
			cout << i << ' ' << result[i] << '\n';
		}
	}

	return 0;
}