#include<stdio.h>
#include<iostream>

using namespace std;

int map[4][4];

int ifend(){
	int win=0,ans=0;
	for(int i=1;i<=3;i++){
		if((map[i][1]==map[i][2])&&(map[i][2]==map[i][3])&&map[i][1]!=0){
			win=map[i][1];
			break;
		}
		if((map[1][i]==map[2][i])&&(map[2][i]==map[3][i])&&map[1][i]!=0){
			win=map[1][i];
			break;
		}
	}
	if((((map[1][1]==map[2][2])&&(map[2][2]==map[3][3]))||
	((map[3][1]==map[2][2])&&(map[2][2]==map[1][3])))&&map[2][2]!=0){
		win=map[2][2];
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(!map[i][j])
			    ans++;
		}
	}
	if(win==1) return (ans+1); //Alice 赢
	else if(win==2) return -1*(ans+1); //Bob 赢
	else if((!win)&&(!ans)) return 0; //平局
	else return 10; //不分胜负
}

int dfs(int turn){
	int flag=ifend();
/*	cout<<"flag:"<<flag<<endl;
	for(int i=1;i<=3;i++){
		    for(int j=1;j<=3;j++){
		    	printf("%d ",map[i][j]);
		    }
		    printf("\n");
		}
	getchar();*/
	if(flag!=10) return flag;
	int flag_ans;
    flag_ans=turn==1?-100:100;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(map[i][j])
			continue;
			if(!map[i][j]){
				map[i][j]=turn;
				//max(-flag_ans,min(100,max(-100,(dfs(2)...继续循环直到flag返回值))))))
				flag_ans=turn==1?max(flag_ans,dfs(2)):min(flag_ans,dfs(1));
			}
			map[i][j]=0;
		}
	}
	return flag_ans;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		for(int i=1;i<=3;i++){
		    for(int j=1;j<=3;j++){
		    	scanf("%d",&map[i][j]);
		    }
		}
		printf("%d\n",dfs(1));
	}
}
