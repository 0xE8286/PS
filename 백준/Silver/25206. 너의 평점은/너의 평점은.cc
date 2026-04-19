#include <iostream>
#include <map>
using namespace std;

map<string, float> score_table;

int main() {

	string subject, grade;
	float score;

	float my_sum = 0;
	float score_sum = 0;

	score_table["A+"] = 4.5;
	score_table["A0"] = 4.0;
	score_table["B+"] = 3.5;
	score_table["B0"] = 3.0;
	score_table["C+"] = 2.5;
	score_table["C0"] = 2.0;
	score_table["D+"] = 1.5;
	score_table["D0"] = 1.0;
	score_table["F"] = 0.0;

	for (int i = 0; i < 20; i++) {
		cin >> subject >> score >> grade;
		if (grade == "P") continue;
		
		my_sum += score * score_table[grade];
		score_sum += score;
	}
	cout << my_sum / score_sum;
	return 0;
}