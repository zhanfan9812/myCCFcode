#include<stdio.h>
int main(){
	int n,k,c=0,s=0,t;
	scanf("%d %d",&n,&k);
	while(n){
		scanf("%d",&t);
		s+=t;
		if(s>=k){
			s=0;
			c++;
		}
		if(n==1&&s!=0){
			c++;
		}
		n--;
	}
	printf("%d",c);
} 
