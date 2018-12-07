//只有80分 找不到bug？？？？？？？？ 

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

map<int, vector<string> >rulesMap;
vector<string>rulesName;
map<int, vector<string> >needProcess;
int pathMap[100];
int n, m;

void init() {
	cin >> n >> m;
	memset(pathMap, 0, sizeof(pathMap));
	char rule[101], name[101], ques[101];
	char *sp;
	bool lastchar;//判断最后一个字符是不是/
	for (int i = 0; i < n; i++) {
		cin >> rule >> name;
		lastchar = false;
		if (rule[strlen(rule) - 1] == '/') {
			lastchar = true;
		}
		rulesName.push_back(name);
		sp = strtok(rule, "/");
		while (sp) {
			if (!strcmp(sp, "<path>")) {
				pathMap[i] = 1;
			}
			rulesMap[i].push_back(sp);
			sp = strtok(NULL, "/");
		}
		if (lastchar) {
			rulesMap[i].push_back("/");
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> ques;
		lastchar = false;
		if (ques[strlen(ques) - 1] == '/') {
			lastchar = true;
		}
		sp = strtok(ques, "/");
		while (sp) {
			needProcess[i].push_back(sp);
			sp = strtok(NULL, "/");
		}
		if (lastchar) {
			needProcess[i].push_back("/");
		}
	}
}

void moveZero(string &s) {
	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			flag++;
		}
		else {
			break;
		}
	}
	if (flag == s.size()) flag--;
	s = s.substr(flag, s.size() - flag);
}

bool allIsNum(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) return false;
	}
	return true;
}

int specialRules(string s) {
	if (s == "<int>") return 1;
	else if (s == "<str>") return 2;
	else if (s == "<path>") return 3;
	else return 0;
}

void sovle() {
	for (int i = 0; i < m; i++) {//待处理字符串(needProcess)循环
		bool matchSuccess = false;
		int isParameter[100];
		for (int j = 0; j < n; j++) {//规则字符串(rulesMap)循环
			memset(isParameter, 0, sizeof(isParameter));
			if (needProcess[i].size() != rulesMap[j].size() && (!pathMap[j])) {
				continue;
			}
			for (int k = 0; k < rulesMap[j].size(); k++) {
				int specialVaule = specialRules(rulesMap[j][k]);
				if (!specialVaule) {
					if (!(rulesMap[j][k] == needProcess[i][k])) {
						break;
					}
				}
				else if (specialVaule == 1) {
					if (!allIsNum(needProcess[i][k])) {
						break;
					}
					else {
						moveZero(needProcess[i][k]);
						isParameter[k] = 1;
					}
				}
				else if (specialVaule == 2) {
					isParameter[k] = 1;
					continue;
				}
				else if (specialVaule == 3) {//规则为<path>时还原消掉的'/'
					matchSuccess = true;
					isParameter[k] = 1;
					for (int t = (needProcess[i].size() - 1); t > k; t--) {
						if (t == (needProcess[i].size() - 1) && needProcess[i][t] == "/") {
							needProcess[i][t - 1] = needProcess[i][t - 1] + "/";
						}
						else {
							needProcess[i][t - 1] = needProcess[i][t - 1] + "/" + needProcess[i][t];
						}
						needProcess[i].pop_back();
					}
					break;
				}
				if (k == rulesMap[j].size() - 1) {
					matchSuccess = true;
				}
			}
			if (matchSuccess) {
				cout << rulesName[j] << " ";
				for (int t = 0; t < needProcess[i].size(); t++) {
					if (isParameter[t]) {
						cout << needProcess[i][t] << " ";
					}
				}
				cout << endl;
				break;
			}
		}
		if (!matchSuccess) {
			cout << "404" << endl;
		}
	}
}

int main() {
	init();
	sovle();
}
/*
5 4
/static/<path> static_serve
/articles/2003/ special_case_2003
/articles/<int>/ year_archive
/articles/<int>/<int>/ month_archive
/articles/<int>/<int>/<str>/ article_detail
/articles/2004
/articles/1985/09/aloha
/articles/hello
/static/js/jquery.js
*/
