#include<stdio.h>
int main(){
	int t=0,s;
	scanf("%d",&t);
	if(t<=3500)         {s=t;}
	if(3500<t&&t<=4955)    {s=100*(t-3500)/97+3500;}
	if(4955<t&&t<=7655)    {s=100*(t-4955)/90+5000;}
	if(7655<t&&t<=11255)   {s=100*(t-7655)/80+8000;}
	if(11255<t&&t<=30755)  {s=100*(t-11255)/75+12500;}
	if(30755<t&&t<=44755)  {s=100*(t-30755)/70+38500;}
	if(44755<t&&t<=61005)  {s=100*(t-44755)/65+58500;}
	if(61005<t)         {s=100*(t-61005)/55+83500;}
	printf("%d",s);
}
