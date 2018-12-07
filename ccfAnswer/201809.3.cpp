#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<queue>

using namespace std;

struct element{
    int no;
    string label;
    string id;
};

vector<element>v;

int main(){
    int n,m,num=0;
    char c;
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<n;i++){
        int tno=0;
        char tc;
        string tid="",tlabel="";
        element temp;
        while((c=getchar())!='\n'){
            int flag=1;
            if(c=='.'){
                tno++;
            }else if(c=='#'){
                cin>>tid;
                getchar();
                temp.id=c+tid;
                break;
            }else{
                tlabel+=c;
                while((tc=getchar())!=' '){
                    if(tc=='\n'){
                        flag=0;
                        break;
                    }
                    tlabel+=tc;
                }
                temp.label=tlabel;
                if(!flag)
                    break;
            }
        }
        temp.no=tno/2;
        v.push_back(temp);
        num++;
    }
    while(m--){
        queue<string>cmd;
        queue<int>ans;
        int start=0,level=-1;
        char s[81];
        char *p;
        cin.getline(s,81);
        p=strtok(s," ");
        while(p){
            cmd.push(p);
            p=strtok(NULL," ");
        }
        while(!cmd.empty()){
            string ts;
            ts=cmd.front();
            cmd.pop();
            for(int i=start;i<num;i++){
                if((ts==v[i].id||(stricmp(ts.c_str(),v[i].label.c_str())==0))&&(v[i].no>level)){
                    if(!cmd.empty()){
                        start=i+1;
                        level=v[i].no;
                        break;
                    }else{
                        for(int j=i;j<num;j++){
                            if((ts==v[j].id||(stricmp(ts.c_str(),v[j].label.c_str())==0))&&(v[j].no>level)){
                                ans.push(j);
                            }
                        }
                        break;
                    }
                }
            }
        }
        printf("%d ",ans.size());
        while(!ans.empty()){
            int t=ans.front();
            ans.pop();
            printf("%d ",t+1);
        }
        printf("\n");
    }

}
