#include<stdio.h>
int main(){
	int a[16][11],b[5][5],n,f=0,mb;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=10;j++)
		    scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++)
		    scanf("%d",&b[i][j]);
	}
	for(int i=4;i>0;i--){
		for(int j=1;j<=4;j++){
			if(b[i][j]==1){
				f=i;
			}
		}
		if(f!=0)
		break;
	}
	scanf("%d",&n);
	for(int i=4;i<16;i++){
		int flag=0;
		for(int j=i;j>i-f;j--){
			for(int k=n;k<n+4;k++){
				if((a[j][k]+b[f+j-i][k-n+1])>1)
				flag=1;
			}
		}
		if(flag==1){
			mb=i-1;
//			printf("mbpk:%d\n",mb);
			break;
		}
		if(flag==0&&i==15){
			mb=i;
//			printf("mbdd:%d\n",mb);
			break;
		}
	}
	for(int i=mb;i>mb-f;i--){
		for(int j=n;j<n+4;j++){
			a[i][j]+=b[f+i-mb][j-n+1];
		}
	}
	for(int i=1;i<=15;i++){
		for(int j=1;j<=10;j++)
		    printf("%d ",a[i][j]);
		    printf("\n");
	}
} 
