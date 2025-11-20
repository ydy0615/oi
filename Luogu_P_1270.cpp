#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define M 10010
int a[N],s[N],top=0;
int dp[N][M];
int n;
vector<pair<int,int> > t[N];
int dfs(int u){
	dp[u][0]=0;
	int sum=0;
	for(auto i:t[u]){
		int v=i.first,w=i.second;
		sum+=dfs(v);
		for(int j=min(sum+w*2,n);j>=w*2;j--){
			for(int k=j-w*2;k>=0;k--){
				dp[u][j]=max(dp[u][j-w*2-k]+dp[v][k],dp[u][j]);
			}
		}
		sum+=w*2;
	}
	if(a[u]){
		for(int i=1;i<=a[u];i++){
			dp[u][i*5]=i;
		}
		return a[u]*5;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cnt,x,y,ans=0;
	cin>>n;
	s[++top]=0;
	while(top){
		cnt++;
		cin>>x>>y;
		t[s[top]].push_back({cnt,x});
		top--;
		if(y==0){
			s[++top]=cnt;
			s[++top]=cnt;
		}
		else{
			a[cnt]=y;
		}
	}
	dfs(0);
	for(int i=0;i<n;i++){
		ans=max(ans,dp[0][i]);
	}
	cout<<ans<<endl;
	return 0;
}