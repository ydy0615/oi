#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define mod 1000000007
#define int long long
#define pii pair<int,int>
pii a[N];
int dp[N][N],tree[N][4010],n,ma;
int lb(int x){return x&(-x);}
bool cmp(pii x,pii y){
	if(x.second==y.second) return x.first<y.first;
	return x.second<y.second;
}
void add(int x,int y,int u){
	for(;x<=ma;x+=lb(x)){
		tree[u][x]+=y;
	}
}
int ask(int x,int u){
	int ans=0;
	for(;x;x-=lb(x)){
		ans+=tree[u][x];
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		ma=max(ma,a[i].second);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for(int j=0;j<i;j++){
			if(a[j].second<a[i].first && j) continue;
			if(a[j].first<a[i].first) dp[i][j]+=ask(a[i].first,j);
			else dp[i][j]+=ask(a[j].first,i);
			dp[i][j]=dp[i][j]%mod;
			add(a[j].second+1,dp[i][j],i);
			ans=(ans+dp[i][j])%mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}