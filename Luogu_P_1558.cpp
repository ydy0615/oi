#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
#define lc u<<1
#define rc u<<1|1
struct node{
	int l,r,s,lz;
}t[N<<3];
void build(int u,int l,int r){
	if(l==r){
		t[u]={l,r,1,0};
		return ;
	}
	t[u]={l,r,1,0};
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[u].s=t[lc].s|t[rc].s;
	return ;
}
void push_down(int u){
	if(t[u].lz==0) return ;
	t[lc].s=t[u].lz;
	t[rc].s=t[u].lz;
	t[lc].lz=t[u].lz;
	t[rc].lz=t[u].lz;
	t[u].lz=0;
}
void add(int u,int l,int r,int x){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		t[u].s=x;
		t[u].lz=x;
		push_down(u);
		return ;
	}
	int mid=(t[u].l+t[u].r)>>1;
	if(l<=mid) add(lc,l,r,x);
	if(r>mid) add(rc,l,r,x);
	t[u].s=t[lc].s|t[rc].s;
}
int ask(int u,int l,int r){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		return t[u].s;
	}
	int mid=(t[u].l+t[u].r)>>1,ans=0;
	if(l<=mid) ans|=ask(lc,l,r);
	if(r>mid) ans|=ask(rc,l,r);
	return ans;
}
signed main(){
	int n,m,q,ans;
	char op;
	cin>>n>>m>>q;
	build(1,1,n+1);
	for(int i=1,x,y,z;i<=q;i++){
		cin>>op;
		if(op=='C'){
			cin>>x>>y>>z;
			if(x>y) swap(x,y);
			add(1,x,y,(1<<(z-1)));
		}
		else if(op=='P'){
			ans=0;
			cin>>x>>y;
			if(x>y) swap(x,y);
			z=ask(1,x,y);
			for(int j=0;j<m;j++){
				if(z&(1<<j)) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}