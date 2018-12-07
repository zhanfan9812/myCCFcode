#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

struct position{
    long long x,y;
    int step;
    int cost;
    int visit;
};

int n,m,k;
long long r;
vector<position>v;

bool arrive(position t1,position t2){
    if(((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y)<=r*r)&&
       (t1.cost+t2.cost<=k)&&(t2.visit==0)){
        return true;
    }
    return false;
}

void bfs(){
    queue<position>q;
    position now;
    q.push(v.front());
    v[0].visit=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(arrive(now,v[1])){
            cout<<now.step;
            break;
        }else{
            for(int i=2;i<(n+m);i++){
                if(arrive(now,v[i])){
                    position next;
                    v[i].visit=1;
                    next.cost=now.cost+v[i].cost;
                    next.x=v[i].x;
                    next.y=v[i].y;
                    next.step=now.step+1;
                    next.visit=1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>k>>r;
    position temp;
    for(int i=0;i<n;i++){
        cin>>temp.x>>temp.y;
        temp.step=0;
        temp.cost=0;
        temp.visit=0;
        v.push_back(temp);
    }
    for(int i=0;i<m;i++){
        cin>>temp.x>>temp.y;
        temp.step=0;
        temp.cost=1;
        temp.visit=0;
        v.push_back(temp);
    }
    bfs();
}

