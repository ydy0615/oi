#include<bits/stdc++.h>
using namespace std;
#define N 200010
vector<int> t[N];
int a[N],b[N],col[N],vis[N],a1,b1,c1;
int main(){
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		a1=b1=c1=0;
		for(int i=1;i<=n;i++){
			t[i].clear();
			a[i]=b[i]=col[i]=vis[i]=0;
		}
		for(int i=1,u,v;i<=m;i++){
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			if(!t[i].size()) a[++a1]=i;
			else b[++b1]=i;
		}
		int flag=1;
		for(int i=1;i<=b1;i++){
			if(col[b[i]]) continue;
			col[b[i]]=++c1;
			for(int j:t[b[i]]){
				vis[j]=b[i];
			}
			for(int j=1;j<=b1;j++){
				if(vis[b[j]]==b[i] || j==i) continue;
				if(col[b[j]] || t[b[j]].size()!=t[b[i]].size()){
					flag=0;
					break;
				}
				for(int v:t[b[j]]){
					if(vis[v]!=b[i]){
						flag=0;
						break;
					}
				}
				if(!flag) break;
				col[b[j]]=c1;
			}
			if(!flag) break;
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		if(a1==0){
			if(n==2 && m==1){
				cout<<"YES\n1 2\n";
				continue;
			}
			else{
				cout<<"NO\n";
				continue;
			}
		}
		if(a1==1){
			if(c1==n-1){
				cout<<"YES\n";
				for(int i=1;i<=n;i++){
					if(i!=a[1]) cout<<a[1]<<" "<<i<<"\n";
				}
				continue;
			}
			else{
				cout<<"NO\n";
				continue;
			}
		}
		if(a1==2){
			if(c1==2){
				cout<<"YES\n"<<a[1]<<" "<<a[2]<<"\n";
				for(int i=1;i<=b1;i++){
					cout<<b[i]<<" "<<a[col[b[i]]]<<"\n";
				}
				continue;
			}
			else{
				cout<<"NO\n";
				continue;
			}
		}
		if(a1<=c1){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=1;i<=a1;i++){
			if(i!=c1+1) cout<<a[i]<<" "<<a[c1+1]<<"\n";
		}
		for(int i=1;i<=b1;i++){
			cout<<b[i]<<" "<<a[col[b[i]]]<<"\n";
		}
	}
	return 0;
}