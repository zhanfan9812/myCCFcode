#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x7fffffff;
const int N = 10000 + 1;
int cost[N], dist[N], n, m;

struct edge {
	int adjv, cost;
	edge *next;
};

struct node{
	int no;
	int cost = INF;
	edge *first=NULL;
	bool operator < (const node n)const {
		return cost > n.cost;
	}
};

node v[N];

void init() {
	cin >> n >> m;
	int s, e, c;
	for (int i = 0; i < m; i++) {
		edge *temp = new edge;
		cin >> s >> e >> c;
		temp->adjv = e;
		temp->cost = c;
		temp->next = NULL;
		if (v[s].first == NULL)	v[s].first = temp;
		else {
			edge *n = v[s].first;
			while (n->next)	
				n = n->next;
			n->next = temp;
		}
		edge *atemp = new edge;
		atemp->adjv = s;
		atemp->cost = c;
		atemp->next = NULL;
		if (v[e].first == NULL)	v[e].first = atemp;
		else {
			edge *n = v[e].first;
			while (n->next)
				n = n->next;
			n->next = atemp;
		}
	}
	for (int i = 1; i <= n; i++) {
		cost[i] = INF;
		v[i].no = i;
		dist[i] = INF;
	}
}

void dijkstra() {
	priority_queue<node> pq;
	v[1].cost = 0;
	cost[1] = 0;
	dist[1] = 0;
	pq.push(v[1]);
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		edge *temp = now.first;
		while (temp) {
			if (dist[temp->adjv] > (dist[now.no] + temp->cost) ||
			(dist[temp->adjv] == (dist[now.no] + temp->cost) && (cost[temp->adjv] > temp->cost))) {
				dist[temp->adjv] = (dist[now.no] + temp->cost);
				cost[temp->adjv] = temp->cost;
				v[temp->adjv].cost = dist[temp->adjv];
				pq.push(v[temp->adjv]);
			}
			if (temp->next)	temp = temp->next;
			else break;
		}
	}
}

int main() {
	init();
	dijkstra();
	int ans = 0;
	for (int i = 2; i <= n; i++)
		ans += cost[i];
	cout << ans << endl;
	return 0;
}
/*
4 5
2 1 7
3 1 5
2 3 1
2 4 3
3 4 5
*/
