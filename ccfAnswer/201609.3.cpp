#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct role {
	int  attack, hp;
};

vector<role>player[2];

int main() {
	role hero = { 0,30 };
	player[0].push_back(hero);
	player[1].push_back(hero);
	int n;
	bool flag = 0;
	string command;
	cin >> n;
	while (n--) {
		cin >> command;
		switch (command[0]) {
		case 's': {
			int p, a, h;
			role summon;
			cin >> p >> a >> h;
			summon.attack = a;
			summon.hp = h;
			/*player[flag].push_back(summon);
			if (p < (player[flag].size() - 1)) {
				for (int i = player[flag].size() - 2; i >= p; i--)
					player[flag][i + 1] = player[flag][i];
				player[flag][p] = summon;
			}*/
			player[flag].insert(player[flag].begin() + p, summon);
			break;
		}
		case 'a': {
			int aNo, dNo;
			cin >> aNo >> dNo;
			player[flag][aNo].hp -= player[!flag][dNo].attack;
			player[!flag][dNo].hp -= player[flag][aNo].attack;
			if (player[flag][aNo].hp <= 0) {
				/*for (int i = aNo + 1; i < player[flag].size(); i++)
					player[flag][i - 1] = player[flag][i];
				player[flag].pop_back();*/
				player[flag].erase(player[flag].begin() + aNo);
			}
			if (dNo != 0 && player[!flag][dNo].hp <= 0) {
				/*for (int i = dNo + 1; i < player[!flag].size(); i++)
					player[!flag][i - 1] = player[!flag][i];
				player[!flag].pop_back();*/
				player[!flag].erase(player[!flag].begin() + dNo);
			}
			break;
		}
		case 'e' : {
			flag = !flag;
			break;
		}
		default:
				break;
		}
	}
	if (player[0][0].hp <= 0)	cout << -1 << endl;
	else if (player[1][0].hp <= 0)	cout << 1 << endl;
	else cout << 0 << endl;
	cout << player[0][0].hp << endl;
	cout << player[0].size() - 1 << " ";
	for (int i = 1; i < player[0].size(); i++)
		cout << player[0][i].hp << " ";
	cout << endl;
	cout << player[1][0].hp << endl;
	cout << player[1].size() - 1 << " ";
	for (int i = 1; i < player[1].size(); i++)
		cout << player[1][i].hp << " ";
	cout << endl;
	return 0;
}
