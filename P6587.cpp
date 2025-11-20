#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define lc u<<1
#define rc u<<1|1
struct node{
	int s,p,sum;
};
node t[800010];
int a[N],n,cnt;
void build(int u,int s,int p){
	cout<<u<<" "<<s<<" "<<p<<"\n";
	t[u].s=s;
	t[u].p=p;
	if(p>=cnt){
		t[u].s=a[s];
		return ;
	}
	build(lc,s,p+1);
	build(rc,s+1,p+1);
	t[u].s+=t[lc].s+t[rc].s;
}
void add(int u,int s,int p,int d){
	if(p==0) return ;
	if(s>t[u].s){
		t[u].sum+=n/(1<<s);
	}
	else{
		t[u].sum+=n/(1<<t[u].s);
	}
	if(p%2==t[u].s%2){
		p/=2;
		add(lc,s,p/2,d);
	}
	else{
		p/=2;
		add(rc,s,p/2,d);
	}
}
int ask(int u,int s,int d){
	if(s>t[u].s){

	}
	if(t[u]%2==t[u].s){
		p/=2;
		ask(lc,s,p/2,d);
	}
	else{

	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,cnt=0,sum=1,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(;sum<n;sum*=2){
		++cnt;
	}
	build(1,1,0);
	for(int i=1,op,x,y,z;i<=m;i++){
		cin>>op;
		op=(ans+ans)%2+1;
		if(op==1){
			cin>>x>>y>>z;
			add(1,x,y,z);
		}
		if(op==2){
			cin>>x>>y;
		}
	}
	return 0;
}