#include<stdio.h>
int main(){
	int n,s=0;
	scanf("%d",&n);
	s+=7*(n/50);
	n%=50;
	s+=4*(n/30);
	n%=30;
	s+=n/10;
	printf("%d",s);
}
