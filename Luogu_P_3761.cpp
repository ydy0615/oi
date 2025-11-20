#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define inf 0x3f3f3f3f
vector<pair<int,int> > g[N];
pair<pair<int,int>,int> a[N];
int fa[N],dep[N],tp[N],mm[N],pm[N],vis[N],mu,rt,rtx,rty;
int dfs(int u,int f,int d){
	fa[u]=f;
	tp[u]=rt;
	dep[u]=d;
	if(dep[u]>dep[mu]) mu=u;
	int ma=0,mi=0;
	for(auto i:g[u]){
		int v=i.first,w=i.second;
		if(v==f) continue;
		if((u==rtx && v==rty) || (u==rty && v==rtx)) continue;
		int tmp=dfs(v,u,d+w)+w;
		if(tmp>ma){
			mi=ma;
			ma=tmp;
		}
		else if(tmp>mi) mi=tmp;
	}
	mm[u]=ma;
	pm[u]=mi;
	return ma;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=inf;
	cin>>n;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		a[i]={{u,v},w};
	}
	for(int i=1;i<n;i++){
		memset(vis,0,sizeof(vis));
		rtx=a[i].first.first;
		rty=a[i].first.second;
		rt=mu=rtx;
		dfs(rtx,0,0);
		while(mu){
			vis[mu]=1;
			mu=fa[mu];
		}
		rt=mu=rty;
		dfs(rty,0,0);
		while(mu){
			vis[mu]=1;
			mu=fa[mu];
		}
		int mx=inf,my=inf,ans1=0;
		for(int j=1;j<=n;j++){
			if(tp[j]==rtx){
				int tmp=mm[j];
				if(vis[j]) tmp=max(tmp,pm[rtx]+dep[j]);
				else tmp=max(tmp,mm[rtx]+dep[j]);
				mx=min(mx,tmp);
			}
			if(tp[j]==rty){
				int tmp=mm[j];
				if(vis[j]) tmp=max(tmp,pm[rty]+dep[j]);
				else tmp=max(tmp,mm[rty]+dep[j]);
				my=min(my,tmp);
			}
			ans1=max(ans1,mm[j]+pm[j]);
		}
		cout<<i<<" "<<mx+my+a[i].second<<endl;
		ans=min(ans,mx+my+a[i].second);
	}
	cout<<ans<<"\n";
	return 0;
}