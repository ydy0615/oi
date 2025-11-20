#include<bits/stdc++.h>
using namespace std;
#define N 400010
int bl,ans,res[N];
int vis[N],a[N],b[N];
map<int,int> mp;
int fa[N][20],dep[N],dfn[N],top=0;
int in[N],out[N];
int sum[N];
vector<int> tree[N];
struct mo{
	int l,r,num,lcf;
}d[N];
mo cg[N];
bool cmp(mo x,mo y){
	return (x.l/bl==y.l/bl)?(x.r<y.r):x.l<y.l;
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
	if(!vis[x]){
		if(!sum[a[x]]){
			ans++;
		}
		sum[a[x]]++;
	}
	else{
		if(sum[a[x]]==1){
			ans--;
		}
		sum[a[x]]--;
	}
	vis[x]^=1;
}
int main(){
	//freopen("p.in","r",stdin);
	int n,m,q,cnt=0,lcf,len;
	cin>>n>>q;
	bl=cbrt(n*n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b;
	for(int i=1;i<=len;i++){
		mp[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		a[i]=mp[a[i]];
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
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
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		if(in[x]>in[y]) swap(x,y);
		lcf=lca(x,y);
		if(lcf==x || lcf==y){
			x=in[x];
			y=in[y];
			d[++cnt]={x,y,cnt,0};
		}
		else{
			x=out[x];
			y=in[y];
			d[++cnt]={x,y,cnt,lcf};
		}
	}
	sort(d+1,d+cnt+1,cmp);
	memset(vis,0,sizeof(vis));
	int L=1,R=0,xl,xr,num;
	for(int i=1;i<=cnt;i++){
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