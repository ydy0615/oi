#include<bits/stdc++.h>
using namespace std;
#define N 100010
pair<pair<int,int>,int> b[N];
int fa[N],a[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		b[i]={{u,v},w};
		if(w==0){
			fa[find(u)]=find(v);
		}
		if(w>1 || (u==v && w!=0)){
			cout<<"No";
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i].second==1){
			a[i]=0;
			if(find(b[i].first.first)==find(b[i].first.second)){
				cout<<"No";
				return 0;
			}
		}
		else{
			a[i]=1;
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}