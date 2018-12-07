#include<stdio.h>
int main(){
	int n,p,a[21][6];
	scanf("%d",&n);
	for(int i=1;i<21;i++)
	    for(int j=1;j<6;j++)
	        a[i][j]=0;
	while(n){
		scanf("%d",&p);
		int f=0,seat=p;
		for(int i=1;i<21;i++){
			int lseat=0;
			for(int j=1;j<6;j++){
				if(a[i][j]==0){
					lseat++;
					a[i][j]=2;
				}
				if(lseat==p){
					f=1;
					break;
				}
				if(a[i][j]==1){
					lseat=0;
				}
			}
			if(f==1){
				for(int k=1;k<6;k++){
					if(a[i][k]==2){
						printf("%d ",5*(i-1)+k);
						a[i][k]=1;
					}
				}
				break;
			}
			if(f==0){
				for(int k=1;k<6;k++){
					if(a[i][k]==2){
						a[i][k]=0;
					}
				}
			//	printf("第%d排位子不够 去下一排:\n",i);
			}
		}
		if(f==0){
			for(int i=1;i<21;i++){
	            for(int j=1;j<6;j++){
	                if(a[i][j]==0&&seat!=0){
	                    printf("%d ",5*(i-1)+j);
	                    a[i][j]=1;
	                    seat--;
					}
				}
			}
		}
		printf("\n");
		n--;
	/*	for(int i=1;i<21;i++){
	    for(int j=1;j<6;j++)
	        printf("%d ",a[i][j]);
	        printf("\n");
		}*/
	}
} 
