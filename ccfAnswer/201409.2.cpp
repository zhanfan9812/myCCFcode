#include<stdio.h>
int main(){
	int n,c=0;
	scanf("%d",&n);
	int a[101][101];
	for(int i=0;i<101;i++)
	    for(int j=0;j<101;j++)
	        a[i][j]=0;
	for(int i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=x1+1;j<=x2;j++){
			for(int k=y1+1;k<=y2;k++){
				a[j][k]=1;
			}
		}
	}
/*	for(int i=0;i<10;i++){
	    for(int j=0;j<10;j++)
	    printf("%d",a[i][j]);
	    printf("\n");
	}*/
	for(int i=0;i<101;i++)
	    for(int j=0;j<101;j++)
	        if(a[i][j]==1)
	        	c++;
	printf("%d",c);
}
