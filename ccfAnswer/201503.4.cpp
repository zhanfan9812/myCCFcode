#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<map>

using namespace std;

const int N=10000+1;
const int M=10000+1;
int n,m;
int fars=0,farv=0;
map<int,vector<int> >p;

void bfs(int start){
    queue<int> q;
    int visit[n+m+1];
    int vstep[n+m+1];
    memset(visit,0,sizeof(visit));
    memset(vstep,0,sizeof(vstep));
    int now;
    q.push(start);
    visit[start]=1;
    while(!q.empty()){
        now=q.front();
        if(vstep[now]>fars){
            fars=vstep[now];
            farv=now;
        }
        q.pop();
        for(int i=0;i<(p[now].size());i++){
            int next=p[now][i];
            if(!visit[next]){
                q.push(next);
                visit[next]=1;
                vstep[next]=vstep[now]+1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    p.clear();
    int t;
    for(int i=2;i<=n+m;i++){
        cin>>t;
        if(!p.count(i))
            p[i]=vector<int>();
        p[i].push_back(t);
        if(!p.count(t))
            p[t]=vector<int>();
        p[t].push_back(i);
    }
    bfs(1);
    bfs(farv);
    cout<<fars;
}
