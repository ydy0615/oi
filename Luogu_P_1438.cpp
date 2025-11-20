#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define lc u<<1
#define rc u<<1|1
int a[N],c[N];
struct node{
	int l,r,s,lz;
}t[N<<3];
void build(int u,int l,int r){
	if(l==r){
		t[u]={l,r,c[l],0};
		return ;
	}
	t[u]={l,r,0,0};
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[u].s=t[lc].s+t[rc].s;
	return ;
}
void push_down(int u){
	if(t[u].lz==0) return ;
	t[lc].s+=(t[lc].r-t[lc].l+1)*t[u].lz;
	t[rc].s+=(t[rc].r-t[rc].l+1)*t[u].lz;
	t[lc].lz+=t[u].lz;
	t[rc].lz+=t[u].lz;
	t[u].lz=0;
}
void add(int u,int l,int r,int x){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		//cout<<x<<" "<<l<<" "<<r<<" "<<t[u].l<<" "<<t[u].r<<" "<<t[u].s<<endl;
		t[u].s+=(t[u].r-t[u].l+1)*x;
		t[u].lz+=x;
		//cout<<x<<" "<<l<<" "<<r<<" "<<t[u].l<<" "<<t[u].r<<" "<<t[u].s<<endl;
		push_down(u);
		return ;
	}
	int mid=(t[u].l+t[u].r)>>1;
	if(l<=mid) add(lc,l,r,x);
	if(r>mid) add(rc,l,r,x);
	t[u].s=t[lc].s+t[rc].s;
}
int ask(int u,int l,int r){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		return t[u].s;
	}
	int mid=(t[u].l+t[u].r)>>1,ans=0;
	if(l<=mid) ans+=ask(lc,l,r);
	if(r>mid) ans+=ask(rc,l,r);
	return ans;
}
signed main(){
	int n,m,l,r,k,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i]-a[i-1];
	}
	build(1,1,n+1);
	for(int i=1,op;i<=m;i++){
		cin>>op;
		if(op==1){
			cin>>l>>r>>k>>d;
			add(1,l,l,k);
			add(1,l+1,r,d);
			add(1,r+1,r+1,-(k+d*(r-l)));
		}
		else if(op==2){
			cin>>k;
			cout<<ask(1,1,k)<<endl;
		}
	}
	return 0;
}