#include<stdio.h>
int main(){
	int n,m=0;
	scanf("%d",&n);
	for(int i=0;i<10;i++){
		m+=(n%10);
		n/=10;
	}
	printf("%d",m);
}
