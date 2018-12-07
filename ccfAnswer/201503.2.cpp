#include<stdio.h>
int main(){
	int n,tc,ta;
	scanf("%d",&n);
	int a[n]={0},c[n]={0};
	for(int k=0;k<n;k++){
		int f=0,temp;
		scanf("%d",&temp);
		for(int i=0;i<n;i++){
			if(temp==a[i]){
				c[i]++;
				f=1;
			}
			if(f==0&&i==n-1){
				for(int j=0;j<n;j++){
					if(a[j]==0){
						a[j]=temp;
						c[j]++;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(c[i]<c[j]){
				tc=c[i];
				c[i]=c[j];
				c[j]=tc;
				ta=a[i];
				a[i]=a[j];
				a[j]=ta;
			}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(c[i]==c[j]&&a[i]>a[j]){
				ta=a[i];
				a[i]=a[j];
				a[j]=ta;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			printf("%d %d\n",a[i],c[i]);
		}
	}
} 
