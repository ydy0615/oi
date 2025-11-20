#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define N 1000010
#define mod 1000000007
#define lc u<<1
#define rc u<<1|1
struct mat{
	int a[2][2];
	mat operator*(const mat &b) const {
		mat res;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				res.a[i][j]=(a[i][0]*b.a[0][j]+a[i][1]*b.a[1][j])%mod;
			}
		}
		return res;
	}
	void print(){
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}ones,s[4];
mat t[N<<2][4];
int tmp[N],lz[N<<2];
void build(int u,int l,int r){
	if(l==r){
		for(int i=0;i<=2;i++) t[u][i]=s[(tmp[l]+i)%3];
		return ;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	for(int i=0;i<=2;i++) t[u][i]=t[lc][i]*t[rc][i];
}
void pushdown(int u){
	lz[lc]=(lz[lc]+lz[u])%3;
	lz[rc]=(lz[rc]+lz[u])%3;
	for(int i=1;i<=lz[u];i++){
		swap(t[lc][0],t[lc][1]);
		swap(t[lc][1],t[lc][2]);
		swap(t[rc][0],t[rc][1]);
		swap(t[rc][1],t[rc][2]);
	}
	lz[u]=0;
}
void add(int u,int l,int r,int L,int R){
	if(L<=l && r<=R){
		lz[u]=(lz[u]+1)%3;
		swap(t[u][0],t[u][1]);
		swap(t[u][1],t[u][2]);
		pushdown(u);
		return ;
	}
	pushdown(u);
	int mid=(l+r)>>1;
	if(L<=mid) add(lc,l,mid,L,R);
	if(mid<R) add(rc,mid+1,r,L,R);
	for(int i=0;i<=2;i++) t[u][i]=t[lc][i]*t[rc][i];
}
mat ask(int u,int l,int r,int L,int R){
	if(L<=l && r<=R) return t[u][0];
	pushdown(u);
	int mid=(l+r)>>1;
	mat ans=ones;
	if(L<=mid) ans=ask(lc,l,mid,L,R);
	if(mid<R) ans=ans*ask(rc,mid+1,r,L,R);
	return ans;
}
bool cmp(mat u){
	return u.a[0][0]==1 && u.a[0][1]==0 && u.a[1][0]==0 && u.a[1][1]==1;
}
signed main(){
	int n,m;
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='0') tmp[i]=0;
		else if(ch=='1') tmp[i]=1;
		else if(ch=='2') tmp[i]=2;
	}
	ones={1,0,0,1};
	s[0]={998244353,353442899,610614424,1755654};
	s[1]={114514,1919810,358338529,999885493};
	s[2]={123456789,987654321,866052702,876543218};
	build(1,1,n);
	for(int i=1,op,x,y;i<=m;i++){
		cin>>op>>x>>y;
		if(op==1){
			add(1,1,n,x,y);
		}
		else{
			if(cmp(ask(1,1,n,x,y))) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}