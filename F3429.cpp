#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define int long long
#define mod 998244353
vector<int> t[N];
int f[N][N],g[N][N],fv[N],gv[N];
int n,sz[N],C[N][N];
void dfs(int u,int fa){
	f[u][0]=1;
	for(int v:t[u]){
		if(v==fa) continue;
		dfs(v,u);
		for(int i=0;i<=sz[u];i++){
			for(int j=0;j<=sz[v];j++){
				fv[i+j]+=f[u][i]*f[v][j]%mod*C[i+j][j]%mod;
				gv[i+j]+=(g[u][i]*f[v][j]+g[v][j]*f[u][i])%mod*C[i+j][j]%mod;
			}
		}
		sz[u]+=sz[v];
		for(int i=0;i<=sz[u];i++){
			f[u][i]=fv[i];
			g[u][i]=gv[i];
			fv[i]=gv[i]=0;
		}
	}
	for(int i=0;i<=sz[u];i++){
		fv[i+1]+=f[u][i]*(i+1);
		gv[i+1]+=g[u][i]*(i+1)+f[u][i]*((i+1)*i/2);
		if(i){
			fv[i-1]+=f[u][i];
			gv[i-1]+=g[u][i];
		}
	}
	sz[u]++;
	for(int i=0;i<=sz[u];i++){
		f[u][i]=fv[i];
		g[u][i]=gv[i];
		gv[i]=fv[i]=0;
	}
}
signed main(){
	ios::sync_
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	dfs(1,0);
	cout<<g[1][0]<<"\n";
	return 0;
}