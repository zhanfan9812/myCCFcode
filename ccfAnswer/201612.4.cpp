#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

const int N=1001;
const int INF=0x7f7f7f7f;

int sum[N],w[N],dp[N][N];

int main(){
	int n;
	memset(dp,INF,sizeof(dp));
//	printf("%d\n",INF);
//	printf("%d",dp[0][0]);
	scanf("%d",&n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum[i]=sum[i-1]+w[i];
		dp[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
//            	cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" len:"<<len<<endl;
            	int ans=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
//            	cout<<dp[i][k]<<" "<<dp[k+1][j]<<" "<<dp[i][j]<<endl;
//            	cout<<ans<<endl;
            	if(ans<dp[i][j])
            		dp[i][j]=ans;
			}
		}
	}
	printf("%d",dp[1][n]);
}
