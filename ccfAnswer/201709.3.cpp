//40·Ö³¬Ê± 
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>

using namespace std;

struct keyValuePair{
	bool valueIsObject;
	string key;
	string value;
};

map<string,keyValuePair>answer;
int n, m;

void init(string add,bool isSubclass) {
	keyValuePair temp;
	string line;
	while (n--) {
		temp.key = ""; temp.value = ""; temp.valueIsObject = false;
		int kpos1, kpos2, vpos1, vpos2, div, pos;
		std::getline(std::cin, line);
		kpos1 = line.find("\"");
		if (kpos1 == -1) {
			if (isSubclass)	break;
			else continue;
		}
		//²Ãµô'\'
		while ((pos = line.find("\\\\")) != -1) line.erase(pos, 1);
		while ((pos = line.find("\\\"")) != -1) line.erase(pos, 1);
		div = line.find(":");
		kpos2 = line.rfind("\"", div);
		temp.key = add + line.substr(kpos1 + 1, kpos2 - kpos1 - 1);
		vpos1 = line.find("\"", div);
		if (vpos1 != -1) {
			vpos2 = line.rfind("\"");
			temp.value = line.substr(vpos1 + 1, vpos2 - vpos1 - 1);
			answer[temp.key] = temp;
		}
		else {
			temp.valueIsObject = true;
			init(temp.key + ".", true);
			answer[temp.key] = temp;
		}
	}
}

void solve() {
	while (m--) {
		string query, key, subclass;
		cin >> query;
		if (answer.count(query)) {
			if (answer[query].valueIsObject) cout << "OBJECT" << endl;
			else  cout << "STRING " << answer[query].value << endl;
		}
		else cout << "NOTEXIST" << endl;
	}
}

int main() {
	cin >> n >> m;
	getchar();
	init("",false);
	solve();
	return 0;
}
