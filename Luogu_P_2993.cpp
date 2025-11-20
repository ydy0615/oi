#include<bits/stdc++.h>
using namespace std;
#define N 30010
#define inf 0x3f3f3f3f
vector<pair<int,int> > g[N],t[N];
priority_queue<pair<int,int> > q;
int d[N],vis[N],vp[N],vs[N];
int sz[N],tot,c[N],rt;
pair<int,int> tmp[N],p[N];
int topt,topp,pp[N];
int ans=0,ans2,n,m,k,cv[N];
void dij(){
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vs[u]) continue;
		vs[u]=1;
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}
void build(int u){
	vp[u]=1;
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(vp[v] || d[u]+w!=d[v]) continue;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
		build(v);
	}
}
void s(int u,int f){
	sz[u]=1;
	c[u]=0;
	for(auto i:t[u]){
		int v=i.first;
		if(v==f || vis[v]) continue;
		s(v,u);
		sz[u]+=sz[v];
		c[u]=max(c[u],sz[v]);
	}
	c[u]=max(c[u],tot-sz[u]);
	if(c[u]<c[rt]) rt=u;
}
void dfs2(int u,int f,int dth,int dep){
	if(dth>k) return ;
	tmp[++topt]={dth,dep};
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		if(v==f || vis[v]) continue;
		dfs2(v,u,dth+1,dep+w);
	}
}
void calc(int u){
	topp=0;
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		if(vis[v]) continue;
		topt=0;
		dfs2(v,u,1,w);
		for(int l=1;l<=topt;l++){
			if(k-tmp[l].first-1>=0){
				if(p[k-tmp[l].first-1].first+tmp[l].second>ans){
					ans=max(ans,p[k-tmp[l].first-1].first+tmp[l].second);
					ans2=p[k-tmp[l].first-1].second;
				}
				else if(p[k-tmp[l].first-1].first+tmp[l].second==ans){
					ans2+=p[k-tmp[l].first-1].second;
				}
			}
		}
		for(int l=1;l<=topt;l++){
			if(p[tmp[l].first].first==-inf) pp[++topp]=tmp[l].first;
			if(p[tmp[l].first].first<tmp[l].second) p[tmp[l].first]={tmp[l].second,1};
			else if(p[tmp[l].first].first==tmp[l].second) p[tmp[l].first].second++;
		}
	}
	for(int i=1;i<=topp;i++) p[pp[i]]={-inf,0};
}
void dfs(int u){
	vis[u]=1;
	calc(u);
	for(auto i:t[u]){
		int v=i.first;
		if(vis[v]) continue;
		tot=sz[v];
		rt=0;
		s(v,u);
		dfs(rt);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	dij();
	build(1);
	rt=0;
	c[0]=inf;
	for(int i=1;i<=n;i++) p[i]={-inf,0};
	p[0]={0,1};
	tot=n;
	s(1,0);
	dfs(rt);
	cout<<ans<<" "<<ans2<<"\n";
	return 0;
}