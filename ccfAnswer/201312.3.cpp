#include<iostream>

using namespace std;
const int N = 1000;
int h[N];

int main(){
    int n, ans, height, area;
    // 输入数据
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> h[i];
    // 计算最大矩形面积：暴力法（枚举法）
    ans = 0;
    for(int i=0; i<n; i++) {
        height = h[i];
        for(int j=i; j<n; j++) {
            if(h[j] < height)
                height = h[j];
            area = (j - i + 1) * height;
            if(area > ans)
                ans = area;
        }
    }
    // 输出结果
    cout << ans << endl;
    return 0;
}
