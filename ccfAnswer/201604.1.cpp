#include<stdio.h>
int main(){
	int n,c=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int f=a[0]-a[1];
	for(int i=1;i<n-1;i++){
		if(f*(a[i]-a[i+1])<0){
			c++;
		}
		f=(a[i]-a[i+1]);
	}
	printf("%d",c);
}
