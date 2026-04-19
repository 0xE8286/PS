#include <iostream>
#define right -1
#define left 1
using namespace std;

int map[100][100];
int cmap[100][100][4];
int M, N;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; //동남서북

int sx, sy, sd, ex, ey, ed;

struct q_bot{
	int y;
	int x;
	int dir;
	int cnt;
};

int f = -1;
int r = -1;
q_bot q[100000];
q_bot v;
int ans;

int fixdir(int d){
	if (d == -1) //방향에맞게수정
		return 3;
	else
		return d % 4;
}

int isSafe(int y, int x){
	if (y >= 1 && y <= M && x >= 1 && x <= N)
		return true;
	else
		return false;
}

int ewns(int v){
	if (v == 1)
		return 0;
	if (v == 2)
		return 2;
	if (v == 3)
		return 1;
	if (v == 4)
		return 3;
}

int main(){
	cin >> M >> N;
	for (int y = 1; y <= M; y++){
		for (int x = 1; x <= N; x++){
			cin >> map[y][x];
		}
	}
	cin >> sy >> sx >> sd;
	cin >> ey >> ex >> ed;

	sd = ewns(sd);
	ed = ewns(ed);

	r++;
	q[r].y = sy;
	q[r].x = sx;
	q[r].dir = sd;

	while (f != r){
		++f;
		v.y = q[f].y;
		v.x = q[f].x;
		v.dir = q[f].dir;
		v.cnt = q[f].cnt;

		if (v.y == ey && v.x == ex && v.dir == ed){
			ans = v.cnt;
			break;
		}

		int ld = fixdir(v.dir + left);
		if (cmap[v.y][v.x][ld] == 0){
			++r;
			q[r].y = v.y;
			q[r].x = v.x;
			q[r].dir = ld;
			q[r].cnt = v.cnt + 1;
			cmap[v.y][v.x][ld] = 1;
		}

		int rd = fixdir(v.dir + right);
		if (cmap[v.y][v.x][rd] == 0){
			++r;
			q[r].y = v.y;
			q[r].x = v.x;
			q[r].dir = rd;
			q[r].cnt = v.cnt + 1;
			cmap[v.y][v.x][rd] = 1;
		}

		for (int l = 1; l <= 3; l++){
			int newY = v.y + (dy[v.dir] * l); //현재 y + 방향 * 직진길이
			int newX = v.x + (dx[v.dir] * l);

			if (map[newY][newX] == 1)
				break;

			if (map[newY][newX] == 0 && cmap[newY][newX][v.dir] == 0 && isSafe(newY, newX)){
				++r;
				q[r].y = newY;
				q[r].x = newX;
				q[r].dir = v.dir;
				q[r].cnt = v.cnt + 1;
				cmap[newY][newX][v.dir] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}