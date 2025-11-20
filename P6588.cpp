#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define pii pair<int,int>
#define lc u<<1
#define rc u<<1|1
struct node{
	int l,r,psum;
	pii sum;
	int qx,qy,lzx,lzy,xy,yx;
}t[N<<2];
pii a[N];
int qx[N],qy[N];
pii add(pii x,pii y){
	pii res;
	res.first=x.first+y.first;
	res.second=x.second+y.second;
	return res;
}
void pushup(int u){
	t[u].sum=add(t[lc].sum,t[rc].sum);
	t[u].psum=t[lc].psum+t[rc].psum;
	t[u].xy=t[lc].xy+t[rc].xy;
	t[u].yx=t[lc].yx+t[rc].yx;
	t[u].qx=t[lc].qx+t[rc].qx;
	t[u].qy=t[lc].qy+t[rc].qy;
}
void pushdown(int u){
	t[lc].xy+=t[u].lzx*t[lc].sum.second;
	t[lc].yx+=t[u].lzy*t[lc].sum.first;
	t[rc].xy+=t[u].lzx*t[rc].sum.second;
	t[rc].yx+=t[u].lzy*t[rc].sum.first;
	t[lc].qx+=t[u].lzx*(t[lc].r-t[lc].l+1);
	t[lc].qy+=t[u].lzy*(t[lc].r-t[lc].l+1);
	t[rc].qx+=t[u].lzx*(t[rc].r-t[rc].l+1);
	t[rc].qy+=t[u].lzy*(t[rc].r-t[rc].l+1);
	t[lc].lzx+=t[u].lzx;
	t[lc].lzy+=t[u].lzy;
	t[rc].lzx+=t[u].lzx;
	t[rc].lzy+=t[u].lzy;
	t[u].lzx=0;
	t[u].lzy=0;
}
void build(int u,int l,int r){
	t[u].l=l;
	t[u].r=r;
	if(l==r){
		t[u].sum=a[l];
		t[u].psum=t[u].sum.first*t[u].sum.first+t[u].sum.second*t[u].sum.second;
		t[u].qx=qx[l-1];
		t[u].qy=qy[l-1];
		return ;
	}
	pushup(u);
}
void add1(int u,int x,pii y){
	if(t[u].l==x && t[u].r==x){
		t[u].sum=add(t[u].sum,y);
		t[u].psum=t[u].sum.first*t[u].sum.first+t[u].sum.second*t[u].sum.second;
		t[u].xy+=t[u].qx*y.second;
		t[u].yx+=t[u].qy*y.first;
		return ;
	}
	pushdown(u);
	int mid=(t[u].l+t[u].r)>>1;
	if(x<=mid) add1(lc,x,y);
	else add1(rc,x,y);
	pushup(u);
}
void add2(int u,int l,int r,pii y){
	if(l<=t[u].l && t[u].r<=r){
		t[u].xy+=t[u].sum.second*y.first;
		t[u].yx+=t[u].sum.first*y.second;
		t[u].qx+=(t[rc].r-t[rc].l+1)*y.first;
		t[u].qy+=(t[rc].r-t[rc].l+1)*y.second;
		t[u].lzx+=y.first;
		t[u].lzy+=y.second;
		return ;
	}
	pushdown(u);
	int mid=(t[u].l+t[u].r)>>1;
	if(l<=mid) add2(lc,l,r,y);
	if(r>mid) add2(rc,l,r,y);
	pushup(u);
}
int ask1(int u,int ,int y){
	if(x<=t[u].l && t[u].r<=y){
		return t[u].sum.first+t[u].sum.second;
	}
	int mid=(t[u].l+t[u].r)>>1,ans=0;
	if(x<=mid) ans+=ask1(lc,x,y);
	else ans+=ask1(rc,x,y);
	return ans;
}
int ask2(int u,int x,int y){
	if(x<=t[u].l && t[u].r<=y){
		return t[u].psum+t[u].psum;
	}
	int mid=(t[u].l+t[u].r)>>1,ans=0;
	if(x<=mid) ans+=ask2(lc,x,y);
	else ans+=ask2(rc,x,y);
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		qx[i]=qx[i-1]+a[i].first;
		qy[i]=qy[i-1]+a[i].second;
	}
	build(1,1,n);
	for(int i=1,op,x,y,z;i<=m;i++){
		cin>>op;
		if(op==1){
			cin>>x>>y>>z;
			add1(1,x,{y,z});
		}
		if(op==2){
			cin>>x>>y>>z;
			add1(1,x,{-y,-z});
		}
		if(op==3){
			cin>>x>>y;
			add2(1,x,{y,y});
		}
		if(op==4){
			cin>>x>>y;

		}
		if(op==5){
			cin>>x>>y;

		}
	}
	return 0;
}