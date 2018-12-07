#include<stdio.h>
int main(){
	int n1,n2,n3,s=0,c=1,fi,a[10],t1=100,t2=10000;
	char f,fl;
	scanf("%d-%d-%d-%c",&n1,&n2,&n3,&f);
	fi=int(f-'0');
	a[1]=n1;
	for(int i=2;i<5;i++){
		a[i]=n2/t1;
		n2%=t1;
		t1/=10;
	}
	for(int i=5;i<10;i++){
		a[i]=n3/t2;
		n3%=t2;
		t2/=10;
	}
	for(int i=1;i<10;i++){
		s+=a[i]*i;
	}
	if(f=='X'){
		if(s%11==10){
			printf("Right");
		}
		else{
			printf("%d-%d%d%d-%d%d%d%d%d-%d",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],s%11);
		}
	}
	if(f!='X'){
		if(s%11==fi){
			printf("Right");
		}
		else{
			if(s%11!=10)
			printf("%d-%d%d%d-%d%d%d%d%d-%d",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],s%11);
			if(s%11==10)
			printf("%d-%d%d%d-%d%d%d%d%d-X",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		}
	}
} 
//²âÊÔ8-100-00000-0
