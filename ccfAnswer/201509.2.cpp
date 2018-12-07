#include<stdio.h>
int main(){
	int y,c,a[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d",&y,&c);
	if(((y%4==0)&&(y%100)!=0)||(y%400==0)){
		a[2]=29;
	}
	else a[2]=28;
	for(int i=1;i<13;i++){
		if((c-a[i])<=0){
			printf("%d\n%d",i,c);
			break;
		}
		else c-=a[i];
	}
}
