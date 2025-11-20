#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define mod 998244353
int n,m,sum[N];
int v[N],f[N],s[N];
vector<int> t[N];
long long ans1,ans2;
int qp(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfs(int u){
	if(v[u]) return ;
	v[u]=1;
	sum[u]=1;
	f[u]=0;
	for(auto v:t[u]){
		dfs(v);
		f[u]+=f[v]+1*sum[v];
		sum[u]+=sum[v];
		f[u]%=mod;
		sum[u]%=mod;
	}
	ans1=(ans1+f[u])%mod;
	ans2=(ans2+sum[u])%mod;
}
signed main(){
	memset(f,0,sizeof(f));
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		t[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!f[i]) dfs(i);
	}
	cout<<ans1*qp(ans2,mod-2)%mod<<"\n";
	return 0;
}