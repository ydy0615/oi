#include<bits/stdc++.h>
using namespace std;
#define N 2010
vector<pair<int,int> > t[N];
long long dp[N][N];
int n,m,sz[N];
inline void read(int &a){
	a=0;
	char c;
	while((c=getchar())<48);
	do a=a*10+(c^48);
	while((c=getchar())>47);
}
long long tot(int sz,int k){
	return 1ll*k*(m-k)+(sz-k)*(n-m-sz+k);
}
inline void dfs(int u,int f){
	dp[u][0]=dp[u][1]=0;
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		for(int j=min(m,sz[u]+1);j>=0;j--){
			for(int k=0;k<=min(j,sz[v]);k++){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]+tot(sz[v],k)*w);
			}
		}
	}
	sz[u]++;
}
int main(){
	memset(dp,-0x3f,sizeof(dp));
	read(n);read(m);
	for(int i=1,u,v,w;i<n;i++){
		read(u);read(v);read(w);
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	dfs(1,0);
	cout<<dp[1][m];
	return 0;
}