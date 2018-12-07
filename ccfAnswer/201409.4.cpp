#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>

using namespace std;

struct position{
	int x;
	int y;
	int cost;
};

queue<position>q;
//上下左右，只要动了花费就+1
position dir[4]={{-1,0,1},{1,0,1},{0,-1,1},{0,1,1}};
const int N=1001;
int buyer[N][N],visit[N][N];
long long costsum=0;

void bfs(int n,int m){
	position nowp,prep;
	while(!q.empty()){
	    prep=q.front();
	    q.pop();
		for(int i=0;i<4;i++){
			nowp.x=prep.x+dir[i].x;
			nowp.y=prep.y+dir[i].y;
			nowp.cost=prep.cost+dir[i].cost;
	  if((1<=nowp.x&&nowp.x<=n)&&(1<=nowp.y&&nowp.y<=n)
			&&!visit[nowp.x][nowp.y]){
				visit[nowp.x][nowp.y]=1;
				q.push(nowp);
				if(buyer[nowp.x][nowp.y]){
//					printf("x:%d y:%d cost:%d num:%d\n",nowp.x,nowp.y,nowp.cost,buyer[nowp.x][nowp.y]);
					costsum+=nowp.cost*buyer[nowp.x][nowp.y];
//					printf("剩余客户数%d\n",m);
					if(--m==0){
						return;
					}
				}
	    	}
    	}
	}
}

int main(){
	//初始化
	int n,m,k,d,pnum;
	memset(buyer,0,sizeof(buyer));
	memset(visit,0,sizeof(visit));
	scanf("%d %d %d %d",&n,&m,&k,&d);
	pnum=k;
	for(int i=0;i<m;i++){
		position temp;
		scanf("%d %d",&temp.x,&temp.y);
		temp.cost=0;
		visit[temp.x][temp.y]=1;
		q.push(temp);
	}
	for(int i=0;i<k;i++){
		int tbx,tby,tbw;
		scanf("%d %d %d",&tbx,&tby,&tbw);
		if(buyer[tbx][tby]){
			pnum--;//可能存在两个客户位置相同。
  }
		buyer[tbx][tby]+=tbw;
	}
	for(int i=0;i<d;i++){
		int tnx,tny;
		scanf("%d %d",&tnx,&tny);
		visit[tnx][tny]=1;
	}
	bfs(n,pnum);
	printf("%lld",costsum);
}
/*10 2 3 3
1 1
8 8
2 3 1
2 3 3
6 7 2
1 2
2 2
6 8*/
