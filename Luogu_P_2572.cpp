#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define lc u<<1
#define rc u<<1|1
int a[N];
struct node{
	int l,r,s,lz,lm,rm,m,li,ri,mi;
	void sw(){
		s=(r-l+1)-s;
		swap(lm,li);
		swap(rm,ri);
		swap(m,mi);
	}
	void clear(){
		s=lm=rm=m=0;
		li=ri=mi=(r-l+1);
	}
	void full(){
		s=lm=rm=m=(r-l+1);
		li=ri=mi=0;
	}
}t[N<<2];
struct nod{
	int lm,rm,m;
};
void push_up(int u){
	t[u].s=t[lc].s+t[rc].s;
	if(t[lc].s==(t[lc].r-t[lc].l+1)) t[u].lm=t[lc].s+t[rc].lm;
	else t[u].lm=t[lc].lm;
	if(t[rc].s==(t[rc].r-t[rc].l+1)) t[u].rm=t[rc].s+t[lc].rm;
	else t[u].rm=t[rc].rm;
	t[u].m=max({t[lc].m,t[rc].m,t[lc].rm+t[rc].lm,t[u].lm,t[u].rm});
	if(t[lc].mi==(t[lc].r-t[lc].l+1)) t[u].li=t[lc].mi+t[rc].li;
	else t[u].li=t[lc].li;
	if(t[rc].mi==(t[rc].r-t[rc].l+1)) t[u].ri=t[rc].mi+t[lc].ri;
	else t[u].ri=t[rc].ri;
	t[u].mi=max({t[lc].mi,t[rc].mi,t[lc].ri+t[rc].li,t[u].li,t[u].ri});
}
void push_down(int u){
	if(t[lc].l==0) return ;
	if(t[u].lz==1){
		t[lc].clear();
		t[rc].clear();
		t[lc].lz=t[rc].lz=1;
	}
	else if(t[u].lz==2){
		t[lc].full();
		t[rc].full();
		t[lc].lz=t[rc].lz=2;
	}
	else if(t[u].lz==3){
		t[lc].sw();
		t[rc].sw();
		t[lc].lz=3-t[lc].lz;
		t[rc].lz=3-t[rc].lz;
	}
	t[u].lz=0;
}
void build(int u,int l,int r){
	t[u].l=l;
	t[u].r=r;
	if(l==r){
		if(a[l]) t[u].full();
		else t[u].clear();
		return ;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void add(int u,int l,int r,int y){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		t[u].lz=y;
		if(y==1) t[u].clear();
		else if(y==2) t[u].full();
		else if(y==3) t[u].sw();
		return ;
	}
	int mid=(t[u].l+t[u].r)>>1;
	if(l<=mid) add(lc,l,r,y);
	if(r>mid) add(rc,l,r,y);
	push_up(u);
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
nod que(int u,int l,int r){
	push_down(u);
	if(l<=t[u].l && t[u].r<=r){
		return {t[u].lm,t[u].rm,t[u].m};
	}
	int mid=(t[u].l+t[u].r)>>1,cnt=0;
	nod a[3];
	if(l<=mid) a[++cnt]=que(lc,l,r);
	if(r>mid) a[++cnt]=que(rc,l,r);
	if(cnt==1) return a[1];
	else{
		if(a[1].rm==(mid-max(l,t[u].l)+1)) a[0].lm=a[1].rm+a[2].lm;
		else a[0].lm=a[1].lm;
		if(a[2].lm==(min(r,t[u].r)-mid)) a[0].rm=a[2].lm+a[1].rm;
		else a[0].rm=a[2].rm;
		a[0].m=max({a[1].m,a[2].m,a[1].rm+a[2].lm,a[0].lm,a[0].rm});
		return a[0];
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,op,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	while(m--){
		cin>>op>>x>>y;
		if(op==0) add(1,x+1,y+1,1);
		if(op==1) add(1,x+1,y+1,2);
		if(op==2) add(1,x+1,y+1,3);
		if(op==3) cout<<ask(1,x+1,y+1)<<"\n";
		if(op==4) cout<<que(1,x+1,y+1).m<<"\n";
	}
	return 0;
}