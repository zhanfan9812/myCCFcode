#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n+1]={0},c[n+1]={0};
	for(int i=1;i<=n;i++){
		int t=0,f=0;
		scanf("%d",&t);
		for(int j=i-1;j>=0;j--){
			if(a[j]==t){
				c[j]++;
				f=1;
			}
		}
		if(f==0){
			a[i]=t;
			c[i]++;
		}
	}
/*	for(int i=0;i<1;i++){
		printf("%d %d\n",a[k],c[k]);
	}*/
	int cmax=c[1],amin;
//	printf("%d %d\n",amin,cmax);
	for(int i=1;i<=n;i++){
		if(c[i]>=cmax){
		cmax=c[i];
		amin=a[i];
        }
	}
//	printf("%d %d\n",amin,cmax);
	for(int j=1;j<=n;j++){
			if(c[j]==cmax&&a[j]<amin)
			amin=a[j];
		}
		printf("%d",amin);
}
