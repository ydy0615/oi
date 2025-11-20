#include<bits/stdc++.h>
using namespace std;
#define N 110
#define int long long
int w[N],v[N],dp[50][2010],num[N];
vector<pair<int,int> > a[30];
pair<int,int> sol(int x){
	int s=1;
	for(;x%s==0;s*=2);
	s/=2;
	return {x/s,__lg(s)};
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,W;
	while(1){
		cin>>n>>W;
		if(n==-1) return 0;
		for(int i=0;i<=30;i++) a[i].clear();
		for(int i=1;i<=n;i++){
			cin>>w[i]>>v[i];
			auto j=sol(w[i]);
			a[j.second].push_back({j.first,v[i]});
			num[j.second]+=j.first;
		}
		memset(dp,0,sizeof(dp));
		int l=1;
		for(;W>=(1<<l);l++);
		l--;
		for(int i=0;i<=l;i++){
			for(auto k:a[i]){
				for(int j=900;j>=k.first;j--){
					dp[i][j]=max(dp[i][j],dp[i][j-k.first]+k.second);
				}
			}
			if(!i) continue;
			for(int j=900;j>=0;j--){
				for(int k=0;k<=j;k++){
					dp[i][j]=max(dp[i][j],dp[i-1][(k<<1)|((W>>(i-1))&1)]+dp[i][j-k]);
				}
			}
		}
		cout<<dp[l][1]<<"\n";
	}
	return 0;
}