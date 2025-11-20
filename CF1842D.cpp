#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define N 110
vector<pair<int,int> > mp[N];
int d[N],v[N];
priority_queue<pair<int,int> > q;
void dij(){
	for(int i=2;i<=100;i++){
		d[i]=inf;
	}
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(v[u]) continue;
		v[u]=0;
		for(auto i:mp[u]){
			int v=i.first,w=i.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
			}
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){

	}
	return 0;
}