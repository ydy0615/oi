#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define int long long
int a[N],ed[N],st[N],top=0,k,n;
priority_queue<int> q;
map<int,vector<int> > mp;
int ans[N];
map<int,bool> vis;
void dfs(int u){
	vis[u]=1;
	for(int i:mp[u]){
		if(i<=k) ans[i]=1;
		else if(!vis[st[i]]) dfs(st[i]);
	}
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=k;i++){
		q.push(-a[i]);
		st[++top]=0;
		ed[top]=a[i];
		mp[ed[top]].push_back(top);
	}
	for(int i=k+1;i<=n;i++){
		int u=q.top();
		q.pop();
		st[++top]=-u;
		ed[top]=-u+a[i];
		mp[ed[top]].push_back(top);
		q.push(u-a[i]);
	}
	int t=-q.top();
	cout<<t<<"\n";
	dfs(t);
	for(int i=1;i<=k;i++){
		cout<<ans[i];
	}
	return 0;
}