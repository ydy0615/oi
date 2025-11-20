#include<bits/stdc++.h>
using namespace std;
#define N 20010
#define M 50010
int fa[N],dep[N];
pair<int,int> g[N];
struct node{
	int u,v,w;
}e[M];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]); 
}
bool cmp(node x,node y){
	return x.w>y.w;
}
int wt[N],tot,f[N][20],vis[N];
void dfs(int u,int fa,int d){
	f[u][0]=fa;
	dep[u]=d;
	if(g[u].first){
		dfs(g[u].first,u,d+1);
		dfs(g[u].second,u,d+1);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=18;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	int n,m,q;
	cin>>n>>m;
	for(int i=1;i<=n*2;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	tot=n;
	for(int i=1,x,y;i<=m;i++){
		x=find(e[i].u);
		y=find(e[i].v);
		if(x!=y){
			fa[x]=++tot;
			fa[y]=tot;
			g[tot].first=x;
			g[tot].second=y;
			wt[tot]=e[i].w;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[find(i)]){
			dfs(find(i),0,1);
			vis[find(i)]=1;
		}
	}
	for(int i=1;i<=18;i++){
		for(int j=1;j<=tot;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
	cin>>q;
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		if(find(x)!=find(y)){
			cout<<"-1\n";
		}
		else{
			int tmp=lca(x,y);
			cout<<wt[tmp]<<"\n";
		}
	}
	return 0;
}