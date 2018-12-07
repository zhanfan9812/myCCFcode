#include <iostream>
#include <vector>
//70分
//TIPS:一次性读入一整段进行处理。 

#include <map>
#include <string.h>
#include <string>

using namespace std;

int main() {
	std::string line;
	bool lastLineIfList = false;
	while (std::getline(std::cin, line)) {
		int pos, titleLevel = 0;
		bool  ifTitle = false, ifList = false;
		bool ifFirst = true;
		if (line.empty()) {
			if (lastLineIfList) {
				cout << "</ul>" << endl;
			}
			lastLineIfList = false;
			continue;
		}
		if (line[0] == '*') { 
			ifList = true; 
			line.erase(0, 1);
		}
		else if (line[0] == '#') {
			ifTitle = true;
			while (line[0] == '#') {
				titleLevel++;
				line.erase(0, 1);
			}
		}
		else {
			string nextLine;
			while (std::getline(std::cin, nextLine) && (!nextLine.empty())) {
				line = line + "\n" + nextLine;
			}
		}
		if (!ifList&&lastLineIfList) cout << "</ul>" << endl;
		while (line[0] == ' ') line.erase(0, 1);
		while ((pos = line.find('_')) != -1) {
			if (ifFirst) {
				line.erase(pos, 1);
				line.insert(pos, "<em>");
				ifFirst = false;
			}
			else {
				line.erase(pos, 1);
				line.insert(pos, "</em>");
				ifFirst = true;
			}
		}
		while ((pos = line.find('[')) != -1) {
			int pos1 = line.find(']');
			int pos2 = line.find('(');
			int pos3 = line.find(')');
			string text = line.substr(pos + 1, pos1 - pos - 1);
			string link = line.substr(pos2 + 1, pos3 - pos2 - 1);
			string newLink = "<a href=\"" + link + "\">" + text + "</a>";
			line.erase(pos, pos3 - pos + 1);
			line.insert(pos, newLink);
		}
		if (ifTitle) {
			cout << "<h" << titleLevel << ">" << line << "</h" << titleLevel << ">" << endl;
			lastLineIfList = false;
		}
		else if (ifList) {
			if (!lastLineIfList) cout << "<ul>" << endl;
			cout << "<li>" << line << "</li>" << endl;
			lastLineIfList = true;
		}
		else {
			cout << "<p>" << line << "</p>" << endl;
			lastLineIfList = false;
		}
	}
	return 0;
}
/*
#  Heading

## Sub-Heading

Pasdfdsf sdaf dsgfsd
by sdf sdfgfsdg.

sadfdsaf sdfdsf sdfreytu _asdf_.

sadfdf sadfgghf:

* aaaas
* aaaas
* aaaas

a [linkaaa](http://example.com).
*/
