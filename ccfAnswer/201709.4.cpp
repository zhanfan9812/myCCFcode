#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 1000 + 1;
int mp[N][N],visit[N];
vector<int>v[N];

void dfs(int s,int e) {
	visit[e] = 1;
	mp[s][e] = mp[e][s] = 1;
	for (int i = 0; i < v[e].size(); i++) {
		if (!visit[v[e][i]])
			dfs(s, v[e][i]);
	}
}

int main() {
	memset(mp, 0, sizeof(mp));
	int n, m, s, e, ans=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		v[s].push_back(e);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!mp[i][j])break;
			if (j == n)ans++;
		}
	}
	cout << ans;
	return 0; 
}
