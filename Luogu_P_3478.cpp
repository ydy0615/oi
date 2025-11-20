#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
vector<int> t[N];
int dp[N],fa[N],sum[N],ans=0,dep[N],c;
void dfs1(int u,int f,int d){
	fa[u]=f;
	sum[u]=1;
	dep[u]=d;
	for(int v:t[u]){
		if(v==f) continue;
		dfs1(v,u,d+1);
		sum[u]+=sum[v];
		dp[u]+=dp[v];
	}
	dp[u]+=sum[u]-1;
}
void dfs2(int u,int f,int num,int s){
	for(int v:t[u]){
		if(v==f) continue;
		dfs2(v,u,num+sum[u]-sum[v],s+dp[u]-dp[v]-sum[v]+num+sum[u]-sum[v]);
	}
	if(dp[u]+s>ans){
		ans=dp[u]+s;
		c=u;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	dfs1(1,0,1);
	dfs2(1,0,0,0);
	cout<<c<<"\n";
	return 0;
}