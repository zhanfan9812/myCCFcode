#include<stdio.h>

int main(){
	//a-2  b-2,0  c-2,3  d-2,3,0  e-2,0,1  f-2,3,0,1
	int n,num;
	long long a,b,c,d,e,f;
	long long ta,tb,tc,td,te,tf;
	b=c=d=e=f=0;	a=1;
	scanf("%d",&n);
	while(--n){
		tb=b+b+a;
		tc=c+a;
		td=d+d+c+b;
		te=e+e+b;
		tf=f+f+d+e;
		b=tb%1000000007;
		c=tc%1000000007;
		d=td%1000000007;
		e=te%1000000007;
		f=tf%1000000007;
	}
	printf("%d",f);
}
