#include<stdio.h>
int main(){
	int n,c=1;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1])
		c++;
	}
	printf("%d",c);
} 
