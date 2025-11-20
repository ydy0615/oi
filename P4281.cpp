#include<bits/stdc++.h>
using namespace std;
#define N 500010
vector<int> t[N];
int fa[N][21],dep[N];
void dfs(int u,int f){
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int v:t[u]){
		if(v==f) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	if(x==y) return x;
	return fa[x][0];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dep[1]=1;
	dfs(1,0);
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		int x1=lca(z,y),y1=lca(x,z),z1=lca(x,y),ans=0;
		if(x1==y1 && y1==z1){
			ans=abs(dep[x]-dep[x1])+abs(dep[y]-dep[x1])+abs(dep[z]-dep[x1]);
			cout<<x1<<" "<<ans<<"\n";
		}
		else if(x1==y1){
			ans=abs(dep[x]-dep[z1])+abs(dep[y]-dep[z1])+abs(dep[z]-dep[x1])+abs(dep[z1]-dep[x1]);
			cout<<z1<<" "<<ans<<"\n";
		}
		else if(x1==z1){
			ans=abs(dep[x]-dep[y1])+abs(dep[z]-dep[y1])+abs(dep[y]-dep[x1])+abs(dep[y1]-dep[x1]);
			cout<<y1<<" "<<ans<<"\n";
		}
		else if(y1==z1){
			ans=abs(dep[y]-dep[x1])+abs(dep[z]-dep[x1])+abs(dep[x]-dep[y1])+abs(dep[x1]-dep[y1]);
			cout<<x1<<" "<<ans<<"\n";
		}
	}
	return 0;
}