#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
int lb(int x){return x&(-x);}
int a[N],b[N],tree1[N],tree2[N],len;
void add(int x,int y,int tmp){
	for(;x<=len;x+=lb(x)){
		tree1[x]+=y;
		tree2[x]+=y*tmp;
	}
}
int ask1(int x){
	int ans=0;
	for(;x;x-=lb(x)) ans+=tree1[x];
	return ans;
}
int ask2(int x){
	int ans=0;
	for(;x;x-=lb(x)) ans+=tree2[x];
	return ans;
}
int ops[N][5],uq[N],tp;
unordered_map<int,int> mp;
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		uq[++tp]=a[i];
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1,op,x,y,z;i<=m;i++){
		cin>>op>>x>>y;
		if(op==1){
			ops[i][1]=op;
			ops[i][2]=x;
			ops[i][3]=y;
			uq[++tp]=x;
			uq[++tp]=y;
		}
		if(op==2){
			cin>>z;
			ops[i][1]=op;
			ops[i][2]=x;
			ops[i][3]=y;
			ops[i][4]=z;
			uq[++tp]=y;
		}
	}
	sort(uq+1,uq+1+tp);
	len=unique(uq+1,uq+1+tp)-uq-1;
	for(int i=1;i<=len;i++){
		mp[uq[i]]=i;
	}
	for(int i=1;i<=n;i++) add(mp[a[i]],b[i],a[i]);
	for(int i=1;i<=m;i++){
		if(ops[i][1]==2){
			add(mp[a[ops[i][2]]],-b[ops[i][2]],a[ops[i][2]]);
			add(mp[ops[i][3]],ops[i][4],ops[i][3]);
			a[ops[i][2]]=ops[i][3];
			b[ops[i][2]]=ops[i][4];
		}
		else{
			int l,r;
			l=mp[ops[i][2]];
			r=mp[ops[i][3]];
			int ls=ask1(l-1),rs=ask1(r),mid=(rs-ls)>>1,x=l-1;
			for(int j=20;j>=0;j--){
				if(x+(1<<j)<=len && ask1(x+(1<<j))-ls<=mid){
					x=x+(1<<j);
				}
			}
			x++;
			cout<<(ask1(x)-ls)*uq[x]-ask2(x)+ask2(l-1)-(ask1(r)-ask1(x))*uq[x]+ask2(r)-ask2(x)<<"\n";
		}
	}
	return 0;
}