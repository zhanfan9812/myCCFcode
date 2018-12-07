#include<stdio.h>
int main(){
	int n,c=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if((a[i]-1)==a[j]||(a[i]+1)==a[j])
			c++;
		}
	}
	printf("%d",c);
}
