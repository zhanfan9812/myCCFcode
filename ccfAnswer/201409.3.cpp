#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<ctype.h>

using namespace std;

int main(){
    string flag;
    int n,f;
    cin>>flag;
    cin>>f>>n;
    if(!f){
        for(int i=0;i<flag.size();i++)
            flag[i]=tolower(flag[i]);
    }
    while(n--){
        string s,temp;
        string::size_type p;
        cin>>s;
        temp=s;
        if(!f){
            for(int i=0;i<temp.size();i++)
                temp[i]=tolower(temp[i]);
        }
        p=temp.find(flag);
        if(p!=temp.npos){
            cout<<s<<endl;
        }
    }
}

