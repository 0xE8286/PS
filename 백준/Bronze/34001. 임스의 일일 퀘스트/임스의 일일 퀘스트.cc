#include <iostream>	

using namespace std;

int level;
int arcane[3][6] = { 
	{200, 210, 220, 225, 230, 235},
	{210, 220, 225, 230, 235, 245},
	{220, 225, 230, 235, 245, 250} 
};
int grandis[3][7] = {
	{260, 265, 270, 275, 280, 285, 290},
	{265, 270, 275, 280, 285, 290, 295},
	{270, 275, 280, 285, 290, 295, 300}
};

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> level;

	for (int i = 0; i < 6; i++) {
		int kill = 500;
		
		if (level < arcane[0][i]) {
			kill = 0;
			cout << kill << ' ';
			continue;
		}

		for (int j = 1; j <= 2; j++) {
			if (arcane[j][i] <= level)
				kill -= 200;
		}
		cout << kill << ' ';
	}
	cout << '\n';

	for (int i = 0; i < 7; i++) {
		int kill = 500;

		if (level < grandis[0][i]) {
			kill = 0;
			cout << kill << ' ';
			continue;
		}
		for (int j = 1; j <= 2; j++) {
			if (grandis[j][i] <= level)
				kill -= 200;
		}
		cout << kill << ' ';
	}

	return 0;
}