#include<bits/stdc++.h>
using namespace std;
#define N 2000010
int a[N],bl,n,cnt[N],num[N],ans[N];
struct node{
	int l,r,a,b,num;
}p[N];
int lb(int x){
	return x&(-x);
}
void pls(int x,int y){
	for(;x<=n;x+=lb(x))	num[x]+=y;
}
int ask(int x){
	int ans=0;
	for(;x;x-=lb(x)) ans+=num[x];
	return ans;
}
bool cmp(node x,node y){
	if(x.l/bl==y.l/bl) return x.r<y.r;
	return x.l<y.l;
}
void add(int x){
	if(cnt[a[x]]==0) pls(a[x],1);
	cnt[a[x]]++;
}
void del(int x){
	if(cnt[a[x]]==1) pls(a[x],-1);
	cnt[a[x]]--;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m;
	cin>>n>>m;
	bl=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i].l>>p[i].r>>p[i].a>>p[i].b;
		p[i].num=i;
	}
	sort(p+1,p+m+1,cmp);
	int l=0,r=0;
	for(int i=1;i<=m;i++){
		while(r<p[i].r) add(++r);
		while(r>p[i].r) del(r--);
		while(l<p[i].l) del(l++);
		while(l>p[i].l) add(--l);
		ans[p[i].num]=ask(p[i].b)-ask(p[i].a-1);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}