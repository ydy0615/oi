#include<bits/stdc++.h>
using namespace std;
#define N 200010
vector<int> t[N];
int d[N],fa[N],ma,rt,a[N];
int mm[N],pm[N],son[N],buc[N];
int st[N],top=0,cnt=0,ans[N];
int dfs(int u,int f,int dep){
	fa[u]=f;
	d[u]=dep;
	if(d[u]>=ma){ma=d[u];rt=u;}
	son[u]=0;
	for(int v:t[u]){
		if(v==f) continue;
		int tmp=dfs(v,u,dep+1)+1;
		if(tmp>mm[u]){
			pm[u]=mm[u];
			mm[u]=tmp;
			son[u]=v;
		}
		else if(tmp>pm[u]){
			pm[u]=tmp;
		}
	}
	return mm[u];
}
int sum=1;
void dfs2(int u,int f){
	if(f){
		if(buc[a[f]]==0) cnt++;
		st[++top]=f;
		buc[a[f]]++;
	}
	while(top && abs(d[st[top]]-d[u])<=pm[u]){
		if(buc[a[st[top]]]==1) cnt--;
		buc[a[st[top]]]--;
		top--;
	}
	if(son[u]) dfs2(son[u],u);
	while(top && abs(d[st[top]]-d[u])<=mm[u]){
		if(buc[a[st[top]]]==1) cnt--;
		buc[a[st[top]]]--;
		top--;
	}
	ans[u]=max(cnt,ans[u]);
	for(int v:t[u]){
		if(v==f || v==son[u]) continue;
		dfs2(v,u);
	}
	if(st[top]==f){
		if(buc[a[st[top]]]==1) cnt--;
		buc[a[st[top]]]--;
		top--;
	}
}
int main(){
	int n,m,st1,st2;
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d[1]=0;
	dfs(1,0,0);
	ma=0;
	int tmp=rt;
	memset(mm,0,sizeof(mm));
	memset(pm,0,sizeof(pm));
	dfs(rt,0,0);
	dfs2(tmp,0);
	ma=0;
	tmp=rt;
	memset(mm,0,sizeof(mm));
	memset(pm,0,sizeof(pm));
	dfs(rt,0,0);
	top=0;
	cnt=0;
	dfs2(tmp,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}