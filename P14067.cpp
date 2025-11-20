#include<bits/stdc++.h>
using namespace std;
#define N 1000010
vector<int> g[N],t[N],up[N],path,output;
vector<pair<int,int> > anss;
int vis[N],dep[N],fa[N];
int ans=0,stu,stv,sz;
int add[N],del[N];
int p,flg=0;
int rt,tg;
void dfs(int u,int f,int d){
	vis[u]=1;
	dep[u]=d;
	fa[u]=f;
	for(int v:g[u]){
		if(v==f) continue;
		if(vis[v]){
			if(dep[u]>dep[v] && (dep[u]-dep[v])%2){
				ans=1;
				stu=u;
				stv=v;
				sz=dep[u]-dep[v]+1;
			}
			else if(dep[u]>dep[v]){
				add[u]++;
				del[v]++;
				up[u].push_back(v);
			}
		}
		else{
			t[u].push_back(v);
			t[v].push_back(u);
			dfs(v,u,d+1);
		}
	}
}
int cf(int u,int f){
	vis[u]=1;
	int cnt=0;
	for(int v:t[u]){
		if(v==f || vis[v]) continue;
		cnt+=cf(v,u);
		if(flg) return 0;
	}
	cnt-=del[u];
	cnt+=add[u];
	if(cnt>=2){
		p=u;
		flg=1;
		return 0;
	}
	return cnt;
}
void dfs2(int u,int f){
	for(int v:t[u]){
		if(v==f) continue;
		dfs2(v,u);
	}
	for(int f:up[u]){
		if(dep[f]<dep[rt]){
			anss.push_back({u,f});
		}
	}
}
int find(int u,int f){
	if(u==tg){
		path.push_back(u);
		return 1;
	}
	for(int v:t[u]){
		if(v==f) continue;
		int tmp=find(v,u);
		if(tmp==1){
			path.push_back(u);
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0,0);
			if(ans) break;
		}
	}
	if(ans){
		cout<<"YES\n"<<sz<<"\n";
		for(int i=stu;i!=stv;i=fa[i]){
			cout<<i<<" ";
		}
		cout<<stv<<"\n";
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cf(i,0);
			if(flg) break;
		}
	}
	if(flg){
		rt=p;
		dfs2(p,fa[p]);
		if(dep[anss[0].second]>dep[anss[1].second]) swap(anss[0],anss[1]);
		tg=anss[0].first;
		find(p,fa[p]);
		for(int i=path.size()-1;i>=0;i--) output.push_back(path[i]);
		path.clear();
		tg=anss[1].second;
		find(anss[0].second,fa[anss[0].second]);
		for(int i=path.size()-1;i>=0;i--) output.push_back(path[i]);
		path.clear();
		tg=anss[1].first;
		find(p,fa[p]);
		for(int i=0;i<path.size()-1;i++) output.push_back(path[i]);
		cout<<"YES\n"<<output.size()<<"\n";
		for(int i:output) cout<<i<<" ";
		cout<<"\n";
	}
	else cout<<"NO\n";
	return 0;
}