#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>

using namespace std;

struct road{
	int strat;
	int end;
	int cost;
	operator <(const road&r)const{
		return cost>r.cost;
	}
};

class caj{
	private:
	    int f[1000+1];
	public:
		//��ʼ������
		cbj(int n){
			for(int i=1;i<=n;i++)
			    f[i]=i;
		}
		//��������ĸ��ڵ�
		int find(int x){
			if(f[x]!=x){
				return find(f[x]);
			}
			else return x;
		}
		//�����������������ĸ��ڵ�(!!!!)������
		int conncet(int a,int b){
			if(find(a)!=find(b)){
				f[find(a)]=find(b);
			}
		}

};

priority_queue<road>pq;

int main(){
	int n,m,num=0,costsum=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		road t;
		scanf("%d %d %d",&t.strat,&t.end,&t.cost);
		pq.push(t);
	}
	cbj link(n);
	//kruskal
	while(!pq.empty()){
		road temp=pq.top();
//		cout<<temp.strat <<" "<<temp.end<<" "<<temp.cost<<endl;
		pq.pop();
		if(link.find(temp.strat)!=link.find(temp.end)){
			costsum+=temp.cost;
			num++;
			link.conncet(temp.strat,temp.end);
		}
		if(num==n-1) break;
	}
	printf("%d",costsum);
}
/*
6 10
1 2 3
1 3 1
1 4 6
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6*/
