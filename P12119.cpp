#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 400010
#define lc u<<1
#define rc u<<1|1
int x[N],y[N],z[N];
int a[N*2],t=0;
map<int,int> mp;
struct node{
	int x1,x2,y1,y2,w;
}p[N];
vector<int> tin[N],tout[N];
struct tree{
	int u,l,r,s,lz;
}xdt[N<<2];
void build(int u,int l,int r){
	xdt[u].l=l;
	xdt[u].r=r;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void push_down(int u){
	xdt[lc].s+=xdt[u].lz;
	xdt[rc].s+=xdt[u].lz;
	xdt[lc].lz+=xdt[u].lz;
	xdt[rc].lz+=xdt[u].lz;
	xdt[u].lz=0;
}
void add(int u,int l,int r,int v){
	if(l<=xdt[u].l && xdt[u].r<=r){
		xdt[u].s+=v;
		xdt[u].lz+=v;
		push_down(u);
		return ;
	}
	push_down(u);
	int mid=(xdt[u].l+xdt[u].r)>>1;
	if(l<=mid) add(lc,l,r,v);
	if(r>mid) add(rc,l,r,v);
	xdt[u].s=max(xdt[lc].s,xdt[rc].s);
}
signed main(){
	int n,w,h,ans=0;
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
		a[++t]=x[i];
		a[++t]=y[i];
	}
	sort(a+1,a+t+1);
	t=unique(a+1,a+t+1)-(a+1);
	for(int i=1;i<=t;i++){
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		x[i]=mp[x[i]];
		y[i]=mp[y[i]];
	}
	for(int i=1;i<=n;i++){
		p[i].x2=x[i];
		p[i].y2=y[i];
		//cout<<x[i]<<" "<<y[i]<<endl;
		int x2=a[x[i]]-w+1,y2=a[y[i]]-h+1;
		p[i].x1=lower_bound(a+1,a+t+1,x2)-a;
		p[i].y1=lower_bound(a+1,a+t+1,y2)-a;
		p[i].w=z[i];
		tin[p[i].y1].push_back(i);
		tout[p[i].y2+1].push_back(i);
		//cout<<p[i].x1<<" "<<p[i].x2<<" "<<p[i].y1<<" "<<p[i].y2<<endl;
	}
	build(1,1,t);
	for(int i=1;i<=t;i++){
		for(int j:tin[i]){
			add(1,p[j].x1,p[j].x2,p[j].w);
			//cout<<"# "<<j<<endl;
		}
		for(int j:tout[i]){
			add(1,p[j].x1,p[j].x2,-p[j].w);
			//cout<<"$ "<<j<<endl;
		}
		ans=max(ans,xdt[1].s);
	}
	cout<<ans<<endl;
	return 0;
}