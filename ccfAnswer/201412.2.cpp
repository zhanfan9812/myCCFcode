#include<stdio.h>
int main(){
	int n,m,h=1,l=1,d=1;
	scanf("%d",&n);
	m=n*n;
	int a[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
//	printf("mmmmm%d\n",m);
	while(m){
		int fh1=0,fl1=0,fh2=0,fl2=0;
		printf("%d ",a[h][l]);
//		printf("h:%d l:%d d:%d\n",h,l,d);
		if(1<=(h-d)&&(h-d)<=n&&1<=(l+d)&&(l+d)<=n){
			h-=d;
		    l+=d;
//		    printf("zhixing\n");
		    m--;
		    continue;
		}
		if(h==1&&l==n&&d==1){
			h+=1;
			d*=-1;
			m--;
			continue;
		}
		if(h==n&&l==1&&d==-1){
			l+=1;
			d*=-1;
			m--;
			continue;
		}
		if(h-d<1){	
			fh1=1;
		}
		if(h-d>n){
			fh2=1;
		}
		if(l+d<1){	
			fl1=1;
		}
		if(l+d>n){
			fl2=1;
		}
		if(fh1==1){
			l+=d;
			d*=-1;
		}
		if(fh2==1){
			l-=d;
			d*=-1;
		}
		if(fl1==1){
			h-=d;
			d*=-1;
		}
		if(fl2==1){
			h+=d;
			d*=-1;
		}
		m--;
//		printf("m:%d\n",m);
	}
}
