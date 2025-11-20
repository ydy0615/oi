#include<bits/stdc++.h>
using namespace std;
#define M 30
#define N 110
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int a[M][M];
vector<int> tin[N],tout[N],node;
int n,m,rt,ans;
int dp[2][600010];
int f[1<<20];
void dfs(int u,int d,int v){
	if(u==m){
		ans=min(ans,d);
		return ;
	}
	for(int i=m;i>1;i--){
		if(rt&(1<<(i-1)) || v&(1<<(i-1)) || a[u][i]==inf) continue;
		if(d+a[u][i]<ans) dfs(i,d+a[u][i],v|(1<<(i-1)));
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(a,0x3f,sizeof(a));
	memset(f,0x3f,sizeof(f));
	int k,e,d;
	cin>>n>>m>>k>>e;
	for(int i=1,u,v,w;i<=e;i++){
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=a[u][v];
	}
	cin>>d;
	for(int i=1,p,a,b;i<=d;i++){
		cin>>p>>a>>b;
		tin[a].push_back(p-1);
		tout[b+1].push_back(p-1);
	}
	int _d=(1<<m)-1;
	for(int i=0;i<(1<<(m-1));i++){
		rt=i;
		ans=inf;
		dfs(1,0,1);
		f[_d-i]=ans;
	}
	int mi=0;
	for(int i=0;i<(1<<m);i++){
		if(f[i]!=inf) node.push_back(i);
	}
	d=0;
	mi=-k;
	for(int i=1;i<=n;i++){
		for(int j:tin[i]) d|=(1<<j);
		for(int j:tout[i]) if(d&(1<<j)) d-=(1<<j);
		int tmp=inf;
		for(int j=0;j<node.size();j++){
			dp[i&1][j]=inf;
			if(node[j]&d) continue;
			dp[i&1][j]=min(mi+k+f[node[j]],dp[!(i&1)][j]+f[node[j]]);
			tmp=min(tmp,dp[i&1][j]);
		}
		mi=tmp;
	}
	cout<<mi<<"\n";
	return 0;
}