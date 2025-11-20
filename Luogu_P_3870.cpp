#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define lc u<<1
#define rc u<<1|1
struct node{
	int l,r,s,lz;
}t[N<<3];
void build(int u,int l,int r){
	t[u]={l,r,0};
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	return ;
}
void push_down(int u){
	if(t[u].lz==0) return ;
	t[lc].s=(t[lc].r-t[lc].l+1)-t[lc].s;
	t[rc].s=(t[rc].r-t[rc].l+1)-t[rc].s;
	t[lc].lz^=1;
	t[rc].lz^=1;
	t[u].lz=0;
}
void add(int u,int l,int r){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		t[u].s=(t[u].r-t[u].l+1)-t[u].s;
		t[u].lz=1;
		//cout<<u<<" "<<l<<" "<<r<<" "<<t[u].l<<" "<<t[u].r<<endl;
		push_down(u);
		return ;
	}
	int mid=(t[u].l+t[u].r)>>1;
	if(l<=mid) add(lc,l,r);
	if(r>mid) add(rc,l,r);
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
int main(){
	int n,m,op,x,y;
	cin>>n>>m;
	build(1,1,n);
	while(m--){
		cin>>op>>x>>y;
		if(op==0){
			add(1,x,y);
		}
		else{
			cout<<ask(1,x,y)<<endl;
		}
	}
	return 0;
}