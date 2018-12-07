#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <string>

using namespace std;

struct privilege{
	string category;
	int level;
};

map<string, vector<privilege> >role;
//map<string, vector<privilege> >user;
map<pair<string, string>, int>user;

void init() {
	int p, r, s, u, t;
	string temp, roleName, permisstions, userName, roleNamesOfUser;
	privilege pTemp;
	//privilege init
	cin >> p;
	while (p--) cin >> temp;
	//role init
	cin >> r;
	for (int i = 0; i < r; i++) {
		cin >> roleName >> s;
		while (s--) {
			cin >> permisstions;
			int len = permisstions.size();
			if (isdigit(permisstions[len - 1])) {
				pTemp.category = permisstions.substr(0, len - 2);
				pTemp.level = permisstions[len - 1] - '0';
			}
			else {
				pTemp.category = permisstions;
				pTemp.level = -1;
			}
			role[roleName].push_back(pTemp);
		}
	}
	//user init
	cin >> u;
	pair<string, string>pairTemp;
	for (int i = 0; i < u; i++) {
		cin >> userName >> t;
		while (t--) {
			cin >> roleNamesOfUser;
			for (vector<privilege>::iterator it = role[roleNamesOfUser].begin(); it != role[roleNamesOfUser].end(); it++) {
				pairTemp = { userName, it->category };
				if (!user.count(pairTemp)) {
					user[pairTemp] = it->level;
				}
				else {
					user[pairTemp] = user[pairTemp] > it->level ? user[pairTemp] : it->level;
				}
			}
		}
	}
}

void solve() {
	int q;
	privilege query;
	pair<string, string>match;
	string userName, permisstion;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> userName >> permisstion;
		int len = permisstion.size();
		if (isdigit(permisstion[len - 1])) {
			query.category = permisstion.substr(0, len - 2);
			query.level = permisstion[len - 1] - '0';
		}
		else {
			query.category = permisstion;
			query.level = -1;
		}
		match = { userName,query.category };
		if (!user.count(match)) {
			cout << "false" << endl;
		}
		else {
			if (query.level == -1 && user[match] != -1)	cout << user[match] << endl;
			else {
				user[match] >= query.level ? cout << "true" << endl : cout << "false" << endl;
			}
		}
	}
}

int main() {
	init();
	solve();
	return 0;
}
