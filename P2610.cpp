#include<bits/stdc++.h>
using namespace std;
#define N 200010
map<pair<int,int>,int> mp;
vector<pair<int,int> > e,t[N];
int d[N],ma,rt;
void add(int x,int y){
	if(abs(x-y)>=2){
		if(x>y){
			if(mp[{y,x}]==0) e.push_back({y,x});
			mp[{y,x}]++;
		}
		else{
			if(mp[{x,y}]==0) e.push_back({x,y});
			mp[{x,y}]++;
		}
	}
}
void dfs(int u,int f){
	if(d[u]>=ma){
		ma=d[u];
		rt=u;
	}
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		if(v==f) continue;
		d[v]=d[u]+w;
		dfs(v,u);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1,u,v,w;i<=n-2;i++){
		cin>>u>>v>>w;
		add(u,v);
		add(u,w);
		add(v,w);
	}
	for(auto i:e){
		t[i.first].push_back({i.second,1});
	}
	d[1]=0;
	dfs(1,0);
	ma=0;
	d[rt]=0;
	dfs(rt,0);
	cout<<n-2<<endl;
	return 0;
}