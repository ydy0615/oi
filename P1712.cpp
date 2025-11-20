#include<bits/stdc++.h>
using namespace std;
#define N 5000010
#define inf 0x3f3f3f3f
int n,m,ans=inf,l,r,ad[N],ma[N],p[N];
struct node{
	int l,r;
}a[500010];
bool operator<(node a,node b){
	return (a.r-a.l)<(b.r-b.l);
}
int sum(int l,int r){
	return p[a[r].r]-p[a[r].l]-p[a[l].r]+p[a[l].l];
}
void add(int u,int l,int r,int x,int y,int z){
	if(l==x && r==y){
		ad[u]+=z;
		ma[u]+=z;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(u<<1,l,mid,x,min(mid,y),z);
	if(y>mid) add(u<<1|1,mid+1,r,max(x,mid+1),y,z);
	ma[u]=max(ma[u<<1],ma[u<<1|1])+ad[u];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		p[i*2-1]=a[i].l;
		p[i*2]=a[i].r;
	}
	sort(p+1,p+n*2+1);
	int k=unique(p+1,p+n*2+1)-p-1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(p+1,p+k+1,a[i].l)-p,
		a[i].r=lower_bound(p+1,p+k+1,a[i].r)-p;
	}
	for(int l=1,r=0;l<=n;l++){
		while(r<n && ma[1]<m){
			r++;
			add(1,1,k,a[r].l,a[r].r,1);
		}
		if(r==n && ma[1]<m) break;
		ans=min(ans,sum(l,r));
		add(1,1,k,a[l].l,a[l].r,-1);
	}
	if(ans==inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}