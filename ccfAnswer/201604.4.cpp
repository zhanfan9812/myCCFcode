#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int n, m, t;
int visit[101][101][10001];

typedef struct Position{
	int x, y, t;
}P;

void init() {
	int tx, ty, ts, te;
	memset(visit, 0, sizeof(visit));
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++) {
		cin >> tx >> ty >> ts >> te;
		for (int j = ts; j <= te; j++) {
			visit[tx][ty][j] = 1;
		}
	}
}

void sovle() {
	P start, now, next;
	P direction[4] = { {0,1,1}, {0,-1,1}, {-1,0,1}, {1,0,1} };
	queue<P>q;
	start.x = 1; start.y = 1; start.t = 0;
	q.push(start);
	visit[1][1][0] = 1;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.x == n && now.y == m) {
			cout << now.t;
			return;
		}
		for (int i = 0; i < 4; i++) {
			next.x = now.x + direction[i].x;
			next.y = now.y + direction[i].y;
			next.t = now.t + direction[i].t;
			if (next.x<1 || next.x>n || next.y<1 || next.y>m)
				continue;
			if (visit[next.x][next.y][next.t] == 1)
				continue;
			q.push(next);
			visit[next.x][next.y][next.t] = 1;
		}
	}
}

int main() {
	init();
	sovle();
}
