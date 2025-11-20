#include<bits/stdc++.h>
using namespace std;
#define N 810
#define M 200010
#define int long long
#define eps (1e-9)
struct node{
	int u,v,c,t;
}e[M];
int fa[N];
double dn;
bool cmp(node x,node y){
	double tx=1.0*x.c+dn*x.t;
	double ty=1.0*y.c+dn*y.t;
	return tx<ty;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	int n,m,f;
	cin>>n>>m>>f;
	for(int i=1,u,v,c,t;i<=m;i++){
		cin>>u>>v>>c>>t;
		e[i]={u,v,c,t};
	}
	double l=0,r=2000000000,mid;
	while(l<r-eps){
		mid=(l+r)/2;
		dn=mid;
		sort(e+1,e+m+1,cmp);
		int st=0,sc=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1,x,y;i<=m;i++){
			x=find(e[i].u);
			y=find(e[i].v);
			if(x!=y){
				fa[x]=y;
				st+=e[i].t;
				sc+=e[i].c;
			}
		}
		if(1.0*(f-sc)/st>mid){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<fixed<<setprecision(4)<<l<<endl;
	return 0;
}