#include<stdio.h>
#include<math.h>
int main(){
	int n,b=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n-1;i++){
		if(abs(a[i]-a[i+1])>b)
		b=abs(a[i]-a[i+1]);
	}
	printf("%d",b);
}
