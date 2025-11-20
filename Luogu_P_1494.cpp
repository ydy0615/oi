#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
int a[N],cnt[N],ans[N],bl,num,ans1[N];
struct node{
	int l,r,num;
}p[N];
bool cmp(node x,node y){
	if(x.l/bl==y.l/bl) return x.r<y.r;
	return x.l<y.l;
}
void add(int x){
	num-=cnt[a[x]]*cnt[a[x]];
	cnt[a[x]]++;
	num+=cnt[a[x]]*cnt[a[x]];
}
void del(int x){
	num-=cnt[a[x]]*cnt[a[x]];
	cnt[a[x]]--;
	num+=cnt[a[x]]*cnt[a[x]];
}
signed main(){
	int n,q,k;
	cin>>n>>q>>k;
	bl=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>p[i].l>>p[i].r;
		p[i].num=i;
	}
	sort(p+1,p+q+1,cmp);
	int l=0,r=0;
	for(int i=1;i<=q;i++){
		while(r<p[i].r) add(++r);
		while(r>p[i].r) del(r--);
		while(l<p[i].l) del(l++);
		while(l>p[i].l) add(--l);
		ans[p[i].num]=num;
		ans1[p[i].num]=(p[i].r-p[i].l+1)*(p[i].r-p[i].l);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]-1<<endl;
	}
	return 0;
}