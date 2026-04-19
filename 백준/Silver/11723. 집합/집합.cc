#include <iostream>
using namespace std;

char cmd[7];
bool exist[21];
int M, num;

int main(){
	cin >> M;

	for (int i = 0; i < M; i++){
		scanf("%s %d", &cmd, &num);

		if (cmd[1] == 'd'){ //add
			exist[num] = true;
		}
		if (cmd[1] == 'e'){ //remove
			exist[num] = false;
		}
		if (cmd[1] == 'h'){ //check
			if (exist[num] == true)
				printf("1\n");
			else
				printf("0\n");
		}
		if (cmd[1] == 'o'){ //toggle
			if (exist[num] == true)
				exist[num] = false;
			else
				exist[num] = true;
		}
		if (cmd[1] == 'l'){ //all
			for (int i = 1; i <= 20; i++)
				exist[i] = true;
		}
		if (cmd[1] == 'm'){ //empty
			for (int i = 1; i <= 20; i++)
				exist[i] = false;
		}
	}
}