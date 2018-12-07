
/* CCF201509-3 ģ������ϵͳ */

 

#include <iostream>

#include <string>

#include <vector>

#include <map>

 

using namespace std;

 

int main()

{

    int n, m;

    vector<string> tv;

    string key, value, temp;

    map<string, string> dict;

    int prev, next;

 

    // ��������

    cin >> n >> m;

    getchar();

    for(int i=1; i<=n; i++) {

        getline(cin, temp);

 

        tv.push_back(temp);

    }

    for(int i=1; i<=m; i++) {

        cin >> key;

        getline(cin, value);

 

        dict[key] = value.substr(2, value.length()-3);

    }

 

    // �滻������������

    for(int i=0; i<n; i++) {

        // �滻����

        prev = 0;

        for(;;) {

            if((prev = tv[i].find("{{ ", prev)) == (int)string::npos)

                break;

            if((next = tv[i].find(" }}", prev)) == (int)string::npos)

                break;

 

            key = tv[i].substr(prev + 3, next - prev - 3);

            // ������������ǵȼ۵ģ���һ������

//            tv[i].replace(prev, key.length() + 6, dict.count(key) ? dict[key] : "");

            tv[i].replace(prev, next - prev + 3, dict.count(key) ? dict[key] : "");

 

            prev += dict.count(key) ? dict[key].length() : 0;   // �����ظ��滻

        }

 

        // ������

        cout << tv[i] << endl;

    }

 

    return 0;

}

