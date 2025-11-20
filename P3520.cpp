#include<bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> g[N],ans[N];
int e[N],f[N],q[N],k=0;
stack<int> st;
void dfs(int u){
	f[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!v) continue;
		g[u][i]=0;
		for(int j=0;j<g[v].size();j++){
			if(g[v][j]==u) g[v][j]=0;
		}
		dfs(v);
	}
	if(q[u]){
		k++;
		ans[k].push_back(u);
		for(int t=st.top();t!=u;t=st.top()){
			ans[k].push_back(t);
			q[t]=0;
			st.pop();
		}
		ans[k].push_back(u);
	}
	else{
		st.push(u);
		q[u]=1;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,x,y,a,b;i<=m;i++){
		cin>>x>>y>>a>>b;
		if(a!=b){
			g[x].push_back(y);
			g[y].push_back(x);
			e[x]++;
			e[y]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(e[i]%2){
			cout<<"NIE\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(!f[i]) dfs(i);
	}
	cout<<k<<"\n";
	for(int i=1;i<=k;i++){
		cout<<ans[i].size()-1<<" ";
		for(int j:ans[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}