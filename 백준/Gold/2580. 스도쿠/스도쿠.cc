#include <iostream>
using namespace std;

int sudoku[9][9];
int blank[81][2];
int cnt;
bool complete = false;

bool isValid(int x, int y, int ans) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][i] == ans || sudoku[i][y] == ans)
			return false;
	}

	if (x < 3) {
		for (int i = 0; i < 3; i++) {
			if (y < 3) {
				for (int j = 0; j < 3; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
			else if (y < 6) {
				for (int j = 3; j < 6; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
			else {
				for (int j = 6; j < 9; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
		}
	}
	else if (x < 6) {
		for (int i = 3; i < 6; i++) {
			if (y < 3) {
				for (int j = 0; j < 3; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
			else if (y < 6) {
				for (int j = 3; j < 6; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
			else {
				for (int j = 6; j < 9; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
		}
	}
	else {
		for (int i = 6; i < 9; i++) {
			if (y < 3) {
				for (int j = 0; j < 3; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
			else if (y < 6) {
				for (int j = 3; j < 6; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
			else {
				for (int j = 6; j < 9; j++)
					if (sudoku[i][j] == ans)
						return false;
			}
		}
	}
	return true;
}

void dfs(int b) {
	if (b == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << endl;
		}
		complete = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int x = blank[b][0];
		int y = blank[b][1];
		
		if (isValid(x, y, i)) {
			sudoku[x][y] = i;
			dfs(b + 1);
			if (complete) {
				return;
			}
			sudoku[x][y] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				blank[cnt][0] = i;
				blank[cnt++][1] = j;
			}
		}
	}

	dfs(0);
	   
	return 0;
}