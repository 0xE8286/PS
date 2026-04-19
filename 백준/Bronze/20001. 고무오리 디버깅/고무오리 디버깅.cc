#include <iostream>
#include <stack>
#include <string>

using namespace std;
string cmd;
stack<int> st;

int main() {
	
	getline(cin, cmd); //고무오리 디버깅 시작
	
	while (1) {
		getline(cin, cmd);
		
		if (cmd == "고무오리 디버깅 끝") {
			break;
		}
		if (cmd == "문제") {
			st.push(1);
		}
		else if (cmd == "고무오리") {
			if (st.empty()) {
				st.push(1);
				st.push(1);
			}
			else {
				st.pop();
			}
		}
	}
	if (st.empty()) {
		cout << "고무오리야 사랑해";
	}
	else {
		cout << "힝구";
	}
	return 0;
}