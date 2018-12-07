#include<stdio.h>
int main(){
	int n,k,c=1,i=0;
	scanf("%d %d",&n,&k);
	int a[n+1],s=n;
	for(int i=1;i<=n;i++)
	    a[i]=0;
	    a[0]=1;
	while(s-1){
		i++; 
		i=i%(n+1);
	//	printf("%d\n",i);
		for(int j=i;j<n;j++){
			if(a[i]==1){
		//	printf("tt i:%d j:%d\n",i,j);
			i++;
			//printf("tt:%d\n",i);
		    }
		} 
		if(a[i]==0){
		if((c%k==0)||(c%10==k)){
		//	printf("s:%d c:%d i:%d \n",s,c,i);
			s--;
			a[i]=1;
		}
		c++;
		}
		//printf("i:%d a[%d]:%d\n",i,i,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)
		printf("%d",i);
	}
	return 0;
} 

