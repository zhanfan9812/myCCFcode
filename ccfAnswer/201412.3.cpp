
/* CCF201412-3 ���Ͼ��� */



#include <iostream>

#include <queue>

#include <cstring>

#include <cstdio>



using namespace std;



const int N = 5000;



struct trading {

    int orderno;

    char t;

    float price;

    long long quantity;

    bool operator < (const trading& n) const {

        if(t == 's')

            return price > n.price;

        else // t == 'b'

            return price < n.price;

    }

};



bool cancelflag[N+1];



int main()

{

    trading t;

    priority_queue<trading> sell, buy;

    string strading;



    // ������ʼ��

    memset(cancelflag, false, sizeof(cancelflag));



    // ��������

    int no = 0, tno;



    while(cin >> strading) {
        if(strading[0] == 'c') {
            // ���ý��׺�
            no++;
            // ����ȡ���Ľ��׺�
            cin >> tno;
            // ����ȡ����־
            cancelflag[tno] = true;
        } else if(strading[0] == 'b' || strading[0] == 's') {
            // ���ý��׺�
            t.orderno = ++no;
            // ���뽻�׼۸������
            cin >> t.price >> t.quantity;
            // �����׷ֱ������������������ȶ���
            if(strading[0] == 'b') {
                t.t = strading[0];
                buy.push(t);
            } else {    // t.trading[0] == 's'
                t.t = strading[0];
                sell.push(t);
            }
        } else
            break;
    }
    // ���Ͼ��۴���
    t.price = 0;
    t.quantity = 0;
    trading b, s;
    for(;;) {
        // �����ȡ���Ķ�����ͬʱ����ͷ����b��s�У�
        while(!buy.empty()) {
            b = buy.top();
            if(cancelflag[b.orderno])
                buy.pop();
            else
                break;
        }
        while(!sell.empty()) {
            s = sell.top();
            if(cancelflag[s.orderno])
                sell.pop();
            else
                break;
        }
        // ��������ֻҪ��һ��Ϊ�գ��������
        if(buy.empty() || sell.empty())
            break;
        // ��Bջ���ļ۸�(��߼�)ȥ��Sջ���ļ۸�(��ͼ�)���ټ���Ӧ����
        if(b.price >= s.price) {
            t.quantity += min(b.quantity, s.quantity);
            t.price = b.price;
            if(b.quantity == s.quantity) {
                buy.pop();
                sell.pop();
            } else if(b.quantity > s.quantity) {
                b.quantity -= s.quantity;
                buy.pop();
                buy.push(b);
                sell.pop();
            } else {    // b.quantity < s.quantity
                buy.pop();
                s.quantity -= b.quantity;
                sell.pop();
                sell.push(s);
            }
        } else
            break;
    }
    // ������
    printf("%.2f", t.price);
    cout << " " << t.quantity << endl;
    return 0;
}
