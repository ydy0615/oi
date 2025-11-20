#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
#define lc (u<<1)
#define rc (u<<1|1)
int c[N],sz[N],sum[N],cnt[N],L,top,dep[N];
int conv[N],dfn[N],nxt[N];
int f[N][20],h[N];
vector<pair<int,int> > g[N];
void dij(int s){
	int fa=s/2;
	for(int i=dfn[s];i<=nxt[s];i++){
		f[conv[i]][dep[s]]=min(f[conv[i]][dep[fa]]+c[s],(long long)inf);
	}
	f[s][dep[s]]=0;
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(f[v][dep[s]]>f[u][dep[s]]+w){
				f[v][dep[s]]=f[u][dep[s]]+w;
				q.push({-f[v][dep[s]],v});
			}
		}
		if(u!=s){
			int v=u/2,w=c[u];
			if(f[v][dep[s]]>f[u][dep[s]]+w){
				f[v][dep[s]]=f[u][dep[s]]+w;
				q.push({-f[v][dep[s]],v});
			}
		}
	}
}
void dfs1(int u){
	sz[u]=1;
	dfn[u]=++top;
	dep[u]=dep[u/2]+1;
	conv[top]=u;
	if(rc<=L){
		dfs1(lc);
		dfs1(rc);
		sz[u]=sz[u]+sz[lc]+sz[rc];
		sum[u]=sum[lc]+sum[rc]+sz[lc]*c[lc]+sz[rc]*c[rc];
		sum[u]%=mod;
	}
	nxt[u]=top;
}
void dfs2(int u){
	int t=u;
	while(t!=1){
		if(f[u][dep[t/2]]==inf) break;
		h[u]=(h[u]+(sum[t/2]-sum[t]+mod-sz[t]*c[t]%mod+mod)%mod+(sz[t/2]-sz[t])*f[u][dep[t/2]]%mod)%mod;
		//h[u]=h[u]+(sum[t/2]-sum[t]-(sz[t]*c[t]%mod)+10ll*mod)+(sz[t/2]-sz[t]+mod)*f[u][dep[t/2]]%mod;
		//h[u]=h[u]%mod;
		t/=2;
	}
	dij(u);
	if(rc<=L){
		dfs2(lc);
		dfs2(rc);
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	L=(1<<n)-1;
	c[1]=0;
	for(int i=2;i<=L;i++) cin>>c[i];
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=L;i++){
		f[i][0]=inf;
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=L;i++){
		ans=(ans+sum[i]+h[i])%mod;
		if(sum[i]<0 || h[i]<0) while(1);
	}
	cout<<ans;
	return 0;
}