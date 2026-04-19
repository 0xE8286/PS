#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
	string name;
	int korean;
	int english;
	int math;
};

bool myCmp(student a, student b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				int result = strcmp(a.name.c_str(), b.name.c_str());
				if (result < 0) return true;
				else return false;
			}
			else return (a.math > b.math);
		}
		else return (a.english < b.english);
	}
	else return (a.korean > b.korean);
}

int N;
vector<student> list;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		student s;
		cin >> s.name >> s.korean >> s.english >> s.math;
		list.push_back(s);
	}

	sort(list.begin(), list.end(), myCmp);

	for (int i = 0; i < N; i++) {
		cout << list[i].name << '\n';
	}
	
	return 0;
}