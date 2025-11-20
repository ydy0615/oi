#include<bits/stdc++.h>
using namespace std;
#define N 1010
int vis[N],rt,dis[N][N],nxt[N][N];
vector<int> mp[N];
double f[N][N];
int du[N];
double dp(int u,int v){
	if(f[u][v]) return f[u][v];
	if(u==v) return 0;
	int fi=nxt[u][v],r=nxt[fi][v];
	if(fi==v || r==v) return 1;
	f[u][v]=0;
	for(int j:mp[v]){
		f[u][v]+=(dp(r,j)+1)/(du[v]+1);
	}
	f[u][v]+=(dp(r,v)+1)/(du[v]+1);
	return f[u][v];
}
queue<int> q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(nxt,0x3f,sizeof(nxt));
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
		du[v]++;
		du[u]++;
	}
	for(int i=1;i<=n;i++){
		rt=i;
		dis[i][i]=1;
		q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:mp[u]){
				if(!dis[i][v]){
					dis[i][v]=dis[i][u]+1;
					q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		nxt[i][i]=i;
		for(int k:mp[i]){
			for(int j=1;j<=n;j++){
				if(dis[i][j]-1==dis[k][j]){
					nxt[i][j]=min(nxt[i][j],k);
				}
			}
		}
	}
	cout<<fixed<<setprecision(3)<<dp(s,t)<<"\n";
	return 0;
}