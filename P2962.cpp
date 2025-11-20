#include<bits/stdc++.h>
using namespace std;
#define N 110
#define int long long
int p[N][N],a[N][N];
int vis[N],d[N],l[N],ans=0x3f3f3f3f,n;
void dfs(int x,int num){
	if(num>=ans) return;
	if(x==0){
		ans=num;
		return;
	}
	if(a[x][x]){
		bool v=a[x][n+1];
		for(int i=x+1;i<=n;i++) if(a[x][i]) v^=l[i];
		dfs(x-1,num+v);
	}
	else{
		dfs(x-1,num);
		l[x]=1;
		dfs(x-1,num+1);
		l[x]=0;
	}
}
signed main(){
	int m,flag=1;
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		p[x][y]=1;
		p[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		p[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[i][j]){
				a[i][j]=1;
			}
		}
		a[i][n+1]=1;
	}
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(a[j][i] && !vis[j]){
				u=j;
				break;
			}
		}
		if(u==0){
			flag=0;
			continue;
		}
		swap(a[u],a[i]);
		vis[i]=1;
		int tmp=a[i][i]^1;
		for(int j=1;j<=n+1;j++){
			a[i][j]^=tmp;
		}
		for(int j=1;j<=n;j++){
			if(a[j][i]==0 || j==i) continue;
			tmp=a[j][i];
			for(int k=1;k<=n+1;k++){
				a[j][k]^=(a[i][k]*tmp);
			}
		}
	}
	if(!flag){
		dfs(n,0);
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][n+1];
		}
	}
	cout<<ans<<"\n";
	return 0;
}