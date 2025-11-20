#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int a,b;
int dp[100010];
int mark[100010][2];
int ans[110][10];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	char ch;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>ch;
			a+=(ch-'0')<<((i-1)*4+(j-1));
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>ch;
			b+=(ch-'0')<<((i-1)*4+(j-1));
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[a]=0;
	for(int k=1;k<=8;k++){
		for(int i=0;i<(1<<16);i++){
			if(dp[i]==inf && dp[i]>=k-1) continue;
			for(int j=0;j<16;j++){
				if(j%4==3) continue;
				if(((i&(1<<j))>0 && (i&(1<<(j+1)))>0) || ((i&(1<<j))==0 && (i&(1<<(j+1)))==0)) continue;
				if(dp[i^(3<<j)]>dp[i]+1){
					dp[i^(3<<j)]=dp[i]+1;
					mark[i^(3<<j)][0]=i;
					mark[i^(3<<j)][1]=j;
				}
			}
			for(int j=0;j<12;j++){
				if(((i&(1<<j))==0 && (i&(1<<(j+4)))>0) || ((i&(1<<j))>0 && (i&(1<<(j+4)))==0)){
					if(dp[i^(1<<j)^(1<<(j+4))]>dp[i]+1){
						dp[i^(1<<j)^(1<<(j+4))]=dp[i]+1;
						mark[i^(1<<j)^(1<<(j+4))][0]=i;
						mark[i^(1<<j)^(1<<(j+4))][1]=j+100;
					}
				}
			}
		}
	}
	cout<<dp[b]<<"\n";
	int top=0;
	for(int i=b;i!=a;i=mark[i][0]){
		if(mark[i][1]>=100){
			int tmp=mark[i][1]-100;
			ans[++top][1]=tmp/4+1;
			ans[top][2]=tmp%4+1;
			ans[top][3]=tmp/4+2;
			ans[top][4]=tmp%4+1;
		}
		else{
			int tmp=mark[i][1];
			ans[++top][1]=mark[i][1]/4+1;
			ans[top][2]=mark[i][1]%4+1;
			ans[top][3]=mark[i][1]/4+1;
			ans[top][4]=mark[i][1]%4+2;
		}
	}
	for(int i=top;i>=1;i--){
		cout<<ans[i][1]<<ans[i][2]<<ans[i][3]<<ans[i][4]<<"\n";
	}
	return 0;
}