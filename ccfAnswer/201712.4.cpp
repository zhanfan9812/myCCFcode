#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 100000+1

struct road{
	int wid,strat,end,len;
}road[MAX];

int bfs(int n){
	
}

int main(){
	int n,m,tired;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&road[i].wid,&road[i].strat,&road[i].end,&road[i].len);
	}
	tired=bfs(n);
	printf("%d",tired);
} 
