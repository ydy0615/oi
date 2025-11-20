#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define M 10000010
#define inf 0x3f3f3f3f
vector<pair<int,int> > g[N];
int sz[N],c[N],vis[N],ak[N],rt,tot;
int tmp[N],topt,q[N],topq;
bool cal[M];
int n,m,ma,ans[N];
void cd(int u,int f){
	sz[u]=1;
	c[u]=0;
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(v==f || vis[v]) continue;
		cd(v,u);
		sz[u]+=sz[v];
		c[u]=max(c[u],sz[v]);
	}
	c[u]=max(c[u],tot-sz[u]);
	if(c[u]<c[rt]) rt=u;
}
void dfs2(int u,int f,int d){
	if(d>ma) return ;
	tmp[++topt]=d;
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(v==f || vis[v]) continue;
		dfs2(v,u,d+w);
	}
}
void calc(int u){
	topq=0;
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(vis[v]) continue;
		topt=0;
		dfs2(v,u,w);
		for(int j=1;j<=m;j++){
			for(int k=1;k<=topt;k++){
				if(ak[j]>=tmp[k] && cal[ak[j]-tmp[k]]){
					ans[j]=1;
				}
			}
		}
		for(int k=1;k<=topt;k++){
			cal[tmp[k]]=1;
			q[++topq]=tmp[k];
		}
	}
	for(int i=1;i<=topq;i++) cal[q[i]]=0;
}
void dfs(int u){
	vis[u]=1;
	calc(u);
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(vis[v]) continue;
		tot=sz[v];
		rt=0;
		cd(v,0);
		dfs(rt);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=m;i++){
		cin>>ak[i];
		ma=max(ma,ak[i]);
	}
	rt=0;
	cal[0]=1;
	c[0]=inf;
	tot=n;
	cd(1,0);
	dfs(rt);
	for(int i=1;i<=m;i++){
		if(ans[i]) cout<<"AYE\n";
		else cout<<"NAY\n";
	}
	return 0;
}