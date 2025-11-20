#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define int long long
int a[N][N],fa[N],sz[N];
vector<int> t[N];
void dfs(int u,int f){
	for(int v:t[u]){
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	sz[u]++;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
	for(int i=2;i<=n;i++){
		int ma=0,u=0;
		for(int j=1;j<=n;j++){
			if((a[1][j]>a[1][i] && a[j][i]>ma) || u==0){
				u=j;
				ma=a[j][i];
			}
		}
		fa[i]=u;
		t[u].push_back(i);
	}
	dfs(1,0);
	for(int i=2;i<=n;i++){
		cout<<fa[i]<<" "<<i<<" "<<(a[i][i]-a[i][fa[i]])/(n-sz[i])<<"\n";
	}
	return 0;
}