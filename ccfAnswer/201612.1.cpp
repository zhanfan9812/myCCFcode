#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n],t,c=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[n/2])
		c++;
	}
	if((n-c)%2==0)
	printf("%d",a[n/2]);
	else printf("-1");
}
