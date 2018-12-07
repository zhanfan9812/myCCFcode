#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

struct Line {
	int Startx, Starty, Endx, Endy;
};

struct Padding {
	int Startx, Starty;
	char fillChar;
};

struct direction {
	int x, y;
}d[4] = { {0,1}, {0,-1}, {-1,0}, {1,0} };

char canvas[100][100];
int visit[100][100];
int n, m;

void DrawLine(Line l) {
	int tempchange;
	if (l.Startx == l.Endx) {
		if (l.Starty > l.Endy) {
			tempchange = l.Starty;
			l.Starty = l.Endy;
			l.Endy = tempchange;
		}
		for (int i = l.Starty; i <= l.Endy; i++) {
			if (canvas[i][l.Startx] != '+') {
				if (canvas[i][l.Startx] == '-') {
					canvas[i][l.Startx] = '+';
				}
				else {
					canvas[i][l.Startx] = '|';
				}
			}
		}
	}
	if (l.Starty == l.Endy) {
		if (l.Startx > l.Endx) {
			tempchange = l.Startx;
			l.Startx = l.Endx;
			l.Endx = tempchange;
		}
		for (int i = l.Startx; i <= l.Endx; i++) {
			if (canvas[l.Starty][i] != '+') {
				if (canvas[l.Starty][i] == '|') {
					canvas[l.Starty][i] = '+';
				}
				else {
					canvas[l.Starty][i] = '-';
				}
			}
		}
	}
}

void FillChar(Padding p) {
	memset(visit, 0, sizeof(visit));
	queue<Padding>q;
	Padding now, next;
	next.fillChar = p.fillChar;
	q.push(p);
	visit[p.Starty][p.Startx] = 1;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		canvas[now.Starty][now.Startx] = now.fillChar;
		for (int i = 0; i < 4; i++) {
			next.Startx = now.Startx + d[i].x;
			next.Starty = now.Starty + d[i].y;
			if (visit[next.Starty][next.Startx])
				continue;
			if (next.Startx < 0 || next.Startx >= n || next.Starty < 0 || next.Starty >= m)
				continue;
			if (canvas[next.Starty][next.Startx] == '-' || canvas[next.Starty][next.Startx] == '|' || canvas[next.Starty][next.Startx] == '+')
				continue;
			q.push(next);
			visit[next.Starty][next.Startx] = 1;
		}
	}
}

int main() {
	int q, judge;
	Line templine;
	Padding tempfill;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			canvas[i][j] = '.';
	for (int i = 0; i < q; i++) {
		cin >> judge;
		if (judge) {
			cin >> tempfill.Startx >> tempfill.Starty >> tempfill.fillChar;
			FillChar(tempfill);
		}
		else {
			cin >> templine.Startx >> templine.Starty >> templine.Endx >> templine.Endy;
			DrawLine(templine);
		}
	}
	for (int i = m - 1; i > -1; i--) {
		for (int j = 0; j < n; j++) {
			cout << canvas[i][j];
		}
		cout << endl;
	}
	//	getchar();
	//	getchar();
}
