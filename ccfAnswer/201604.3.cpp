#include<iostream> 
#include<string.h>

using namespace std;

int main(){
	int num,pos,pos1;
	string curPos,line;
	cin >> num >> curPos;
	getchar();
	while (num--){
		getline(cin, line);
		if (line.empty())line = curPos;//0.�ַ���Ϊ�յ���� 
		else if (line[0] != '/')line = curPos + "/" + line;//  1.��λ��Ϊ'/'�����
		while ((pos = line.find("/../")) != -1){//  2.����/../
			if (!pos) line.erase(0, 3);//��ǰ�Ѿ��Ǹ�Ŀ¼ 
			else{
				pos1 = line.rfind("/", pos - 1);
				line.erase(pos1, pos - pos1 + 3);
			}
		}
		while ((pos = line.find("/./")) != -1)line.erase(pos, 2);//   3.����/./
		while ((pos = line.find("//")) != -1) line.erase(pos, 1);//   4.����///
		if (line.size()>1 && line[line.size() - 1] == '/')line.erase(line.size() - 1, 1);//   5.ĩβ��/
		cout << line << endl;// 6.������
	}
	return 0;
}
