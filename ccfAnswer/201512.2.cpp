#include<stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1],h[n+1][m+1],l[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			h[i][j]=0;
			l[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int th=0;
		for(int j=1;j<m;j++){
			if(a[i][j]==a[i][j+1]){
				th++;
//				printf("thxt:%d\n",th);
				if(th>1){
					h[i][j+1]=th;
				}
			}
			if(a[i][j]!=a[i][j+1]){
				th=0;
//				printf("thbt:%d\n",th);
			}
		}
	}
	for(int i=1;i<=m;i++){
		int tl=0;
		for(int j=1;j<n;j++){
			if(a[j][i]==a[j+1][i]){
				tl++;
//	     		printf("tlxt:%d\n",tl);
				if(tl>1){
					l[j+1][i]=tl;
				}
			}
			if(a[j][i]!=a[j+1][i]){
				tl=0;
//				printf("tlbt:%d\n",tl);
			}
		}
	}
/*	printf("hq:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",h[i][j]);
		}
		printf("\n");
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(h[i][j]!=0){
//				printf("i:%d j:%d th:%d\n",i,j,h[i][j]);
				for(int k=j;k>=(j-h[i][j]);k--)
				a[i][k]=0;
			}
			if(l[i][j]!=0){
//				printf("i:%d j:%d tl:%d\n",i,j,l[i][j]);
				for(int k=i;k>=(i-l[i][j]);k--)
				a[k][j]=0;
			}
		}
	}
/*	printf("h:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",h[i][j]);
		}
		printf("\n");
	}
	printf("l:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",l[i][j]);
		}
		printf("\n");
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
