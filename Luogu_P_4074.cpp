#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
int bl,ans,res[N];
int V[N],W[N],vis[N],a[N];
int fa[N][20],dep[N],dfn[N],top=0;
int in[N],out[N],pre[N];
vector<int> tree[N];
struct mo{
	int l,r,t,num,lcf;
}d[N];
mo cg[N];
bool cmp(mo x,mo y){
	return (x.l/bl==y.l/bl)?(x.r/bl==y.r/bl?x.t<y.t:x.r<y.r):x.l<y.l;
}
void dfs(int u,int f,int d){
	dfn[++top]=u;
	dep[u]=d;
	fa[u][0]=f;
	for(int v:tree[u]){
		if(v==f) continue;
		dfs(v,u,d+1);
	}
	dfn[++top]=u;
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=18;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	if(x==y) return x;
	for(int i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void s(int x){
	if(vis[x]) ans-=V[a[x]]*W[--pre[a[x]]+1];
	else ans+=V[a[x]]*W[++pre[a[x]]];
	vis[x]^=1;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q,t=1,cnt=0,lcf;
	cin>>n>>m>>q;
	bl=cbrt(n*n);
	for(int i=1;i<=m;i++) cin>>V[i];
	for(int i=1;i<=n;i++) cin>>W[i];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i];
	}
	dfs(1,0,1);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	for(int i=1;i<=n*2;i++){
		if(!vis[dfn[i]]){
			in[dfn[i]]=i;
			vis[dfn[i]]=1;
		}
		else{
			out[dfn[i]]=i;
		}
	}
	for(int i=1,op,x,y;i<=q;i++){
		cin>>op>>x>>y;
		if(op==0){
			cg[++t]={x,y,pre[x]};
			pre[x]=y;
		}
		if(op==1){
			if(in[x]>in[y]) swap(x,y);
			lcf=lca(x,y);
			if(lcf==x || lcf==y){
				x=in[x];
				y=in[y];
				d[++cnt]={x,y,t,cnt,0};
			}
			else{
				x=out[x];
				y=in[y];
				d[i].lcf=lcf;
				d[++cnt]={x,y,t,cnt,lcf};
			}
		}
	}
	sort(d+1,d+cnt+1,cmp);
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	t=1;
	int L=1,R=0,xl,xr,num;
	for(int i=1;i<=cnt;i++){
		while(t<d[i].t){
			t++;
			if(vis[cg[t].l]){
				s(cg[t].l);
				a[cg[t].l]=cg[t].r;
				s(cg[t].l);
			}
			else a[cg[t].l]=cg[t].r;
		}
		while(t>d[i].t){
			if(vis[cg[t].l]){
				s(cg[t].l);
				a[cg[t].l]=cg[t].t;
				s(cg[t].l);
			}
			else a[cg[t].l]=cg[t].t;
			t--;
		}
		while(d[i].l<L) s(dfn[--L]);
		while(d[i].l>L) s(dfn[L++]);
		while(d[i].r<R) s(dfn[R--]);
		while(d[i].r>R) s(dfn[++R]);
		if(d[i].lcf){
			s(d[i].lcf);
			res[d[i].num]=ans;
			s(d[i].lcf);
		}
		else{
			res[d[i].num]=ans;
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<res[i]<<"\n";
	}
	return 0;
}