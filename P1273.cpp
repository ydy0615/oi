#include<bits/stdc++.h>
using namespace std;
#define N 3010
vector<pair<int,int> > t[N];
int a[N],f[N][N],sum[N],n,m;
void dfs(int u){
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		dfs(v);
		sum[u]+=sum[v];
		for(int j=sum[u];j>=1;j--){
			for(int k=1;k<=min(j,sum[v]);k++){
				f[u][j]=min(f[u][j],f[u][j-k]+w+f[v][k]);
			}
		}
	}
	if(u>n-m){
		sum[u]=1;
		f[u][1]=-a[u];
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(f,0x3f,sizeof(f));
	int ans=0;
	cin>>n>>m;
	for(int i=1,k;i<=n-m;i++){
		cin>>k;
		for(int j=1,v,w;j<=k;j++){
			cin>>v>>w;
			t[i].push_back({v,w});
		}
	}
	for(int i=1;i<=n;i++){
		f[i][0]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i+(n-m)];
	}
	dfs(1);
	for(int j=0;j<=m;j++){
		if(f[1][j]<=0) ans=j;
	}
	cout<<ans<<"\n";
	return 0;
}