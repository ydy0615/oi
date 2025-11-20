#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
vector<pair<int,int> > t[N];
int d[N],fa[N][22],ma,rt,dep[N];
void dfs(int u,int f){
	fa[u][0]=f;
	if(d[u]>=ma){
		ma=d[u];
		rt=u;
	}
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		if(v==f) continue;
		d[v]=d[u]+w;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	for(int i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	if(x==y) return x;
	return fa[x][0];
}
signed main(){
	int n,tmp1,tmp2;
	cin>>n;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v;
		t[u].push_back({v,1});
		t[v].push_back({u,1});
	}
	dep[1]=0;
	d[1]=0;
	dfs(1,0);
	tmp1=rt;
	dep[rt]=0;
	ma=d[rt]=0;
	dfs(rt,0);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	int flg=1,ans1=0,ans2=0,ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]==ma && flg){
			flg=0;
			ans1=i;
		}
		else if(d[i]==ma){
			ans1=lca(ans1,i);
		}
	}
	dep[rt]=0;
	ma=d[rt]=0;
	tmp2=rt;
	dfs(rt,0);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	flg=1;
	for(int i=1;i<=n;i++){
		if(d[i]==ma && flg){
			flg=0;
			ans2=i;
		}
		else if(d[i]==ma){
			ans2=lca(ans2,i);
		}
	}
	if(ans1==0) while(1);
	while(ans2!=ans1){
		ans2=fa[ans2][0];
		ans++;
	}
	cout<<ma<<"\n";
	return 0;
}