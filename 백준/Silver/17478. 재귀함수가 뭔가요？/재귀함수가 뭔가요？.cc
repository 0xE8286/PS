#include <iostream>
using namespace std;

int N;
string s0 = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
string s1 = "\"재귀함수가 뭔가요?\"\n";
string s2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string s3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string s4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string s5 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
string s6 = "라고 답변하였지.\n";

void out(int n, string* str) {
	for (int i = n; i < N; i++) {
		cout << "____";
	}
	cout << *str;
	return;
}
void jaegui(int n) {
	out(n, &s1);
	if (n > 0) {
		out(n, &s2);
		out(n, &s3);
		out(n, &s4);
		jaegui(n - 1);
	}
	else {
		out(n, &s5);
	}
	out(n, &s6);
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	cout << s0;
	jaegui(N);

	return 0;
}