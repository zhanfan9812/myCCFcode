#include<stdio.h>
const int N=3000;
int a[N][N]={0};
int main(){
	int n,m,ax1[11]={0},ax2[11]={0},ay1[11]={0},ay2[11]={0},s[11]={0};
	scanf("%d %d",&n,&m);
	for(int k=1;k<=n;k++){
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		ax1[k]=x1;ax2[k]=x2;ay1[k]=y1;ay2[k]=y2;
		for(int i=x1;i<=x2;i++){
			for(int j=y1;j<=y2;j++){
				a[i][j]=k;
			}
		}
	}
/*	for(int i=6;i>=0;i--){
	    for(int j=0;j<7;j++)
	    printf("%d ",a[i][j]);
	    printf("\n");
	 }*/
	for(int t=1;t<=m;t++){
		int x,y,f=0;
		scanf("%d %d",&x,&y);
		for(int k=1;k<11;k++){
			if(a[x][y]==k){
				f=1;
				s[t]=k;
				for(int i=ax1[k];i<=ax2[k];i++){
			        for(int j=ay1[k];j<=ay2[k];j++){
				        a[i][j]=k;
			        }
		        }
			}
		}
		if(f==0)
		s[t]=0;
	}
	for(int i=1;i<=m;i++){
		if(s[i]!=0){
			printf("%d\n",s[i]);
		}
		else printf("IGNORED\n");
	}
} 
