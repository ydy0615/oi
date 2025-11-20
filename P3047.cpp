#include<bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> t[N];
int c[N];
int cnt,dp[N][30];
void dfs(int u,int f){
	for(int v:t[u]){
		int t=1,temp=0,tmp=cnt;
		while(tmp--){
			if(t%2==1){
				dp[u][cnt]+=dp[v][tmp];
			}
			else{
				dp[u][cnt]-=dp[u][tmp];
			}
			t++;
		}
		if(v==f) continue;
		dfs(v,u);
	}
	dp[u][cnt]=dp[u][cnt]+c[u];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		dp[i][0]=c[i];
	}
	for(int i=1;i<=k;i++){
		cnt=i;
		dfs(1,0);
	}
	for(int j=1;j<=n;j++){
		cout<<dp[j][k]<<"\n";
	}
	return 0;
}