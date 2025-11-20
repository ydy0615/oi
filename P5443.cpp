#include<bits/stdc++.h>
using namespace std;
#define N 100010
struct edge{
	int u,v,w,t;
}e[N];
int fa[N],sz[N],top,B;
int n,m,vis[N],ys[N],ans[N];
struct ak{
	int s,w,t;
}sk[N];
int st[N],tp=0;
inline bool cmp1(ak x,ak y){return x.w>y.w;}
inline bool cmp2(edge x,edge y){return x.w>y.w;}
vector<ak> es;
vector<edge> a[N];
inline int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(sz[x]<sz[y]) swap(x,y);
	st[++tp]=y;
	sz[x]+=sz[y];
	fa[y]=x;
}
void cut(int id){
	while(tp>id){
		sz[fa[st[tp]]]-=sz[st[tp]];
		fa[st[tp]]=st[tp];
		tp--;
	}
}
void solve(){
	sort(e+1,e+m+1,cmp2);
	sort(sk+1,sk+top+1,cmp1);
	for(int i=1;i<=m;i++) ys[e[i].t]=i;
	vector<ak> M;
	M.clear();
	for(auto i:es){
		vis[i.s]=-1;
		M.push_back({i.s,e[ys[i.s]].w,0});
	}
	for(auto i:es) M.push_back(i);
	for(int i=1;i<=n;i++){fa[i]=i;sz[i]=1;}
	tp=0;
	for(int i=1,it=1;i<=top;i++){
		while(it<=m && e[it].w>=sk[i].w){
			if(!vis[e[it].t]) merge(e[it].u,e[it].v);
			it++;
		}
		int last=tp;
		for(auto a:M) if(a.t<=sk[i].t) vis[a.s]=a.w;
		for(auto a:M) if(vis[a.s]>=sk[i].w) merge(e[ys[a.s]].u,e[ys[a.s]].v);
		ans[sk[i].t]=sz[find(sk[i].s)];
		cut(last);
	}
	for(auto i:es){
		e[ys[i.s]].w=i.w;
		vis[i.s]=0;
	}
	es.clear();
	top=0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;
	cin>>n>>m;
	B=sqrt(n*(__lg(n)+1))+1;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w,i};
	}
	cin>>q;
	for(int i=1,op,x,y;i<=q;i++){
		cin>>op>>x>>y;
		if(op==1) es.push_back({x,y,i});
		else sk[++top]={x,y,i};
		if(i%B==0) solve();
	}
	if(q%B) solve();
	for(int i=1;i<=q;i++) if(ans[i]) cout<<ans[i]<<"\n";
	return 0;
}