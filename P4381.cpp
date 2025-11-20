#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
vector<pair<int,int> > g[N],h[N];
int vis[N],hv[N],dp[N],rt;
long long ans2,d[N],s[N];
int dfs(int u,int f){
	vis[u]=1;
	int ret=0,flag=1;
	for(auto i:g[u]){
		int v=i.first,w=i.second,tmp=0;
		if(v==f && flag){
			flag=0;
			continue;
		}
		if(vis[v] && !hv[v]){
			ret=v;
			h[rt].push_back({u,w});
			hv[u]=1;
		}
		else if(!hv[v]) tmp=dfs(v,u);
		if(tmp){
			h[rt].push_back({u,w});
			hv[u]=1;
			if(tmp!=u) ret=tmp;
		}
	}
	return ret;
}
void dfs2(int u,int f){
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(v==f || hv[v]) continue;
		dfs2(v,u);
		ans2=max(ans2,d[u]+d[v]+w);
		d[u]=max(d[u],d[v]+w);
	}
}
int solve(int i){
	int ans=0,ans3=0;ans2=0;
	rt=i;
	dfs(rt,0);
	for(auto k:h[i]){
		dfs2(k.first,0);
	}
	ans=ans2;
	int tmp=h[i].size();
	for(int j=0;j<tmp;j++){
		dp[j]=dp[j+tmp]=h[i][j].first;
		s[j]=s[j+tmp]=h[i][j].second;
	}
	tmp*=2;
	for(int j=0;j<tmp;j++){
		s[j]=s[j-1]+s[j];
	}
	deque<int> q;
	for(int j=0;j<tmp;j++){
		while(!q.empty() && q.front()<=j-tmp/2) q.pop_front();
		if(!q.empty()) ans3=max(ans3,d[dp[j]]+d[dp[q.front()]]+s[j]-s[q.front()]);
		while(!q.empty() && d[dp[q.back()]]-s[q.back()]<=d[dp[j]]-s[j]) q.pop_back();
		q.push_back(j);
	}
	ans=max(ans,ans3);
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1,u,v;i<=n;i++){
		cin>>u>>v;
		g[i].push_back({u,v});
		g[u].push_back({i,v});
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans+=solve(i);
		}
	}
	cout<<ans<<"\n";
	return 0;
}