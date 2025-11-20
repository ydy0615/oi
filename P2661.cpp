#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define int long long
vector<int> g[N],h[N];
int vis[N],hv[N],rt;
int dfs(int u,int f){
	vis[u]=1;
	int ret=0,flag=1;
	for(int v:g[u]){
		int tmp=0;
		if(v==f && flag){
			flag=0;
			continue;
		}
		if(vis[v] && !hv[v]){
			ret=v;
			h[rt].push_back(u);
			hv[u]=1;
		}
		else if(!hv[v]) tmp=dfs(v,u);
		if(tmp){
			h[rt].push_back(u);
			hv[u]=1;
			if(tmp!=u) ret=tmp;
		}
	}
	return ret;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0x3f3f3f3f;
	cin>>n;
	for(int i=1,v;i<=n;i++){
		cin>>v;
		g[i].push_back(v);
		g[v].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			rt=i;
			dfs(i,0);
			ans=min((int)h[i].size(),ans);
		}
	}
	cout<<ans<<"\n";
	return 0;
}