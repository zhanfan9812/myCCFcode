#include<stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	while(m){
		int p,q,t,f;
		scanf("%d %d",&p,&q);
		for(int i=1;i<=n;i++){
			if(a[i]==p){
			f=i;
			break;
		    }
		}
		t=a[f];
		if(q>0){
			for(int i=f;i<f+q;i++){
			    a[i]=a[i+1];
		    }
		    a[f+q]=t;
		}
		if(q<0){
			for(int i=f;i>f+q;i--){
			    a[i]=a[i-1];
		    }
		    a[f+q]=t;
		}
	/*    for(int i=1;i<=n;i++)
	    printf("%d ",a[i]);
	    printf("\n");*/
		m--;
	}
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
}
