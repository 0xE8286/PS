#include <iostream>
#include <ctime>
using namespace std;

int now[3];
int war[3];
int wait[3];

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	scanf("%d:%d:%d", &now[0], &now[1], &now[2]);
	scanf("%d:%d:%d", &war[0], &war[1], &war[2]);

	int now_sec = now[0] * 3600 + now[1] * 60 + now[2];
	int war_sec = war[0] * 3600 + war[1] * 60 + war[2];

	if (war_sec <= now_sec) war_sec += (24 * 3600);

	int diff = war_sec - now_sec;
	
	wait[0] = diff / 3600;
	diff = diff % 3600;

	wait[1] = diff / 60;
	diff = diff % 60;

	wait[2] = diff;

	printf("%02d:%02d:%02d", wait[0], wait[1], wait[2]);
	
	return 0;
}