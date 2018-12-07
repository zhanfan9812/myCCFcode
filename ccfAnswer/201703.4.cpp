#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

const int N=100000+1;
const int M=200000+1;
int lastp[N];

struct road{
	int start;
	int end;
	int length;
	operator <(const road &r)const{
	    return length<r.length;
	}
}pq[M];

int find(int x){
	return lastp[x]==x?x:lastp[x]=find(lastp[x]);
//	return lastp[x]==x?x:find(lastp[x]);则运行超时
}

int main(){
	int n,m,ans;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		lastp[i]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&pq[i].start,&pq[i].end,&pq[i].length);
	}
	sort(pq,pq+m);
	for(int i=0;i<m;i++){
		lastp[find(pq[i].end)]=find(pq[i].start);
		if(find(1)==find(n)){
			printf("%d",pq[i].length);
			break;
		}
	}
}
/*
6 7
1 2 8
2 3 4
3 6 7
1 4 2
4 5 3
5 6 9
2 4 6*/
