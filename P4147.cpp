#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define int long long
int a[N][N],res,root;
int s[N],top=0,lc[N],rc[N];
int dfs(int u){
	int ans=1;
	if(lc[u]) ans+=dfs(lc[u]);
	
	//if(root==91) cout<<u<<" "<<ans<<" "<<rc[u]<<" "<<lc[u]<<endl;
	if(rc[u]) ans+=dfs(rc[u]);
	res=max(res,ans*a[u][root]);
	//if(root==91) cout<<u<<" # "<<ans<<endl;
	return ans;
}
signed main(){
	//freopen("P4147_5.in","r",stdin);
	int n,m,anss=0;
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=m;j++){
			cin>>ch;
			if(ch=='R') s=0;
			else s++;
			a[i][j]=s;
		}
	}
	for(int i=1;i<=m;i++){
		memset(lc,0,sizeof(lc));
		memset(rc,0,sizeof(rc));
		memset(s,0,sizeof(s));
		int rt=1;
		res=0;
		top=0;
		for(int j=1;j<=n;j++){
			int k=top;
			while(a[s[k]][i]>=a[j][i] && k) k--;
			if(!k) rt=j;
			if(k) rc[s[k]]=j;
			if(k<top) lc[j]=s[k+1];
			s[++k]=j;
			top=k;
		}
		root=i;
		//if(i==91){
		//	cout<<rt<<endl;
		//	for(int j=1;j<=n;j++){
		//		cout<<j<<" "<<a[j][i]<<" "<<lc[j]<<" "<<rc[j]<<endl;
		//	}
		//}
		dfs(rt);
		//cout<<i<<" "<<res<<"\n";
		anss=max(anss,res*3);
	}
	cout<<anss<<"\n";
	return 0;
}