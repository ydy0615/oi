#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],cnt[N],num=0,ans[N],bl;
struct node{
	int l,r,num;
}p[N];
bool cmp(node x,node y){
	if(x.l/bl==y.l/bl) return x.r<y.r;
	return x.l<y.l;
}
void add(int x){
	if(cnt[a[x]]==0) num++;
	cnt[a[x]]++;
}
void del(int x){
	if(cnt[a[x]]==1) num--;
	cnt[a[x]]--;
}
int main(){
	int n,q;
	cin>>n>>q;
	bl=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>p[i].l>>p[i].r;
		p[i].num=i;
	}
	sort(p+1,p+1+q,cmp);
	int l=0,r=0;
	for(int i=1;i<=q;i++){
		while(r<p[i].r) add(++r);
		while(r>p[i].r) del(r--);
		while(l<p[i].l) del(l++);
		while(l>p[i].l) add(--l);
		if(num==(r-l+1)) ans[p[i].num]=1;
		else ans[p[i].num]=0;
		//cout<<num<<" "<<r<<" "<<l<<endl;
	}
	for(int i=1;i<=q;i++){
		if(ans[i]) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}