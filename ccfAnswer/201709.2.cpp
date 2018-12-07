#include<stdio.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1],f[n+1],w[k+1],s[k+1],c[k+1],ta[2*k+1],tt[2*k+1],tma,tmt,m=-1;
	for(int i=1;i<=n;i++){
		f[i]=1;
		a[i]=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&w[i],&s[i],&c[i]);
	}
	//将时间（tt）与钥匙号(ta)放入数组 
	for(int i=1;i<=k;i++){
		ta[2*i-1]=-1*w[i];
		ta[2*i]=w[i];
		tt[2*i-1]=s[i];
		tt[2*i]=s[i]+c[i];
	}
	//按要求以时间为标准排序，并相应改变钥匙号排序 
	for(int i=1;i<=2*k-1;i++){
		for(int j=i+1;j<=2*k;j++){
			if(tt[i]>tt[j]){
				tmt=tt[i];
				tt[i]=tt[j];
				tt[j]=tmt;
				tma=ta[i];
				ta[i]=ta[j];
				ta[j]=tma;
			}
			if(tt[i]==tt[j]){
				if(ta[i]<0&&ta[j]>0){
					tma=ta[i];
				    ta[i]=ta[j];
				    ta[j]=tma;
				}
				if(ta[i]>0&&ta[j]>0&&(ta[i]>ta[j])){
					tma=ta[i];
				    ta[i]=ta[j];
				    ta[j]=tma;
				}
			}
		}
	}
	for(int i=1;i<=2*k;i++){
		//借钥匙操作 
		if(ta[i]<0){
			for(int j=1;j<=n;j++){
				if(a[j]==ta[i]*-1){
				f[j]=0;
				a[j]=0; 
			    }
			}
		}
		//还钥匙操作 
		if(ta[i]>0){
			for(int j=1;j<=n;j++){
				if(f[j]==0){
				m=j;
			//	printf("m:%d\n",m);
				break;
			    }
			}
			a[m]=ta[i];
			f[m]=1;
		}
	/*	for(int k=1;k<=n;k++){
		printf("%d ",f[k]);
	    }
	    printf("\n");*/ 
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	/*
	for(int i=1;i<=2*k;i++){
	    printf("%d ",ta[i]);
    }
    printf("\n");
    for(int i=1;i<=2*k;i++){
	    printf("%d ",tt[i]);
    }*/
}
