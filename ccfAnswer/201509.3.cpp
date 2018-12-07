
/* CCF201509-3 模板生成系统 */

 

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

 

    // 输入数据

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

 

    // 替换处理与输出结果

    for(int i=0; i<n; i++) {

        // 替换处理

        prev = 0;

        for(;;) {

            if((prev = tv[i].find("{{ ", prev)) == (int)string::npos)

                break;

            if((next = tv[i].find(" }}", prev)) == (int)string::npos)

                break;

 

            key = tv[i].substr(prev + 3, next - prev - 3);

            // 以下两个语句是等价的，后一句会更快

//            tv[i].replace(prev, key.length() + 6, dict.count(key) ? dict[key] : "");

            tv[i].replace(prev, next - prev + 3, dict.count(key) ? dict[key] : "");

 

            prev += dict.count(key) ? dict[key].length() : 0;   // 避免重复替换

        }

 

        // 输出结果

        cout << tv[i] << endl;

    }

 

    return 0;

}

