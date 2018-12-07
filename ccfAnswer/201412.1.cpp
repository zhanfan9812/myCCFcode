#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n+1]={0},c[n+1]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]++;
		for(int j=i-1;j>=0;j--){
			if(a[i]==a[j])
			c[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",c[i]);
	}
}
