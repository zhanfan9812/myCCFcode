#include<cstdio>
#include<iostream>

using namespace std;

int leapyear(int i){
	if((i%400==0)||(i%4==0&&i%100!=0))
		return 1;
	return 0;
}

int main(){
	int a,b,c,y1,y2,flag=2;
	int summonth[13]={0,
	               0,
	               31,
				   31+28,
				   31+28+31,
				   31+28+31+30,
				   31+28+31+30+31,
				   31+28+31+30+31+30,
				   31+28+31+30+31+30+31,
				   31+28+31+30+31+30+31+31,
				   31+28+31+30+31+30+31+31+30,
				   31+28+31+30+31+30+31+31+30+31,
				   31+28+31+30+31+30+31+31+30+31+30,
				  };
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d %d %d %d",&a,&b,&c,&y1,&y2);
	for(int i=1850;i<y1;i++){
		flag+=365+leapyear(i);
	}
	flag+=summonth[a];
	if(a>2)
		flag+=leapyear(y1);
	flag=(flag%7)==0?7:(flag%7);
//	cout<<flag<<endl;
	for(int i=y1;i<=y2;i++){
		int ans,limit=month[a];
		if(c>=flag)
		    ans=(b-1)*7+c-flag+1;
		else
            ans=(b-1)*7+c+7-flag+1;
		if(a==2)
			limit+=leapyear(i);
		if(ans<=limit){
			printf("%d/%02d/%02d\n",i,a,ans);
		}else{
			printf("none\n");
		}
		if(a>2){
			flag=flag+365+leapyear(i+1);
		}else{
			flag=flag+365+leapyear(i);
		}
		flag=(flag%7)==0?7:(flag%7);
	}
}
