#include<bits/stdc++.h>
using namespace std;
#define N 20010
#define inf 0x3f3f3f3f
vector<pair<int,int> > mp[N],t[N];
int d[N],v[N],f[N],n,m,k;
priority_queue<pair<int,int> > q;
void dij(int s){
	for(int i=1;i<=n;i++) d[i]=inf;
	for(int i=1;i<=n;i++) v[i]=0;
	d[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(v[u]) continue;
		v[u]=1;
		for(auto i:mp[u]){
			int v=i.first,w=i.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
int dp[1<<10][20];
int main(){
	int ans=inf;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int i=1;i<=k+1;i++){
		dij(i);
		for(int j=i+1;j<=k+1;j++){
			t[i].push_back({j,d[j]});
			t[j].push_back({i,d[j]});
		}
	}
	dij(n);
	for(int i=1;i<=k+1;i++){
		t[i].push_back({n,d[i]});
		t[n].push_back({i,d[i]});
	}
	int g;
	cin>>g;
	for(int i=1,x,y;i<=g;i++){
		cin>>x>>y;
		f[y]|=(1<<(x-1));
	}
	dp[1][1]=0;
	for(int i=1;i<(1<<(k+1));i++){
		for(int j=1;j<=k+1;j++){
			if(dp[i][j]==inf) continue;
			for(auto s:t[j]){
				int v=s.first;
				if((i&f[v])==f[v]){
					dp[i|(1<<(v-1))][v]=min(dp[i|(1<<(v-1))][v],dp[i][j]+s.second);
				}
			}
		}
	}
	for(int j=1;j<=k+1;j++){
		ans=min(ans,dp[(1<<(k+1))-1][j]+d[j]);
	}
	cout<<ans<<"\n";
	return 0;
}