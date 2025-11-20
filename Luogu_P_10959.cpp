#include<bits/stdc++.h>
using namespace std;
int a[20],dp[12][92][92][92];
int dfs(int dep,int sum,int num,int mod,bool lim){
	if(dep==0) return (sum==mod && !num);
	if(!lim && dp[dep][sum][num][mod]>=0) return dp[dep][sum][num][mod];
	int top=9,ans=0;
	if(lim) top=a[dep];
	for(int i=0;i<=top;i++){
		if(sum+i<=mod){
			ans+=dfs(dep-1,sum+i,(num*10+i)%mod,mod,lim&(i==a[dep]));
		}
	}
	if(!lim) dp[dep][sum][num][mod]=ans;
	return ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int l,r,len,ans;
	while(cin>>l>>r){
		len=ans=0;
		for(int i=r;i;i/=10) a[++len]=i%10;
		for(int i=len*9;i>=1;i--){
			ans+=dfs(len,0,0,i,1);
		}
		l--;
		len=0;
		for(int i=l;i;i/=10) a[++len]=i%10;
		for(int i=len*9;i>=1;i--){
			ans-=dfs(len,0,0,i,1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}